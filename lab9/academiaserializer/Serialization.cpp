//
// Created by ficon on 08.05.18.
//

#include "Serialization.h"
namespace academia{

    void Room::Serialize(Serializer *serializer) {

        serializer -> Header("room");
        serializer -> IntegerField("id", id_);
        serializer -> StringField("name", name_);
        serializer -> StringField("type", TypeToString(type_));
        serializer -> Footer("room");


    }

    Room::Room(int id_, const std::string &name_, Room::Type type_) : id_(id_), name_(name_), type_(type_) {}

    std::string Room::TypeToString(Room::Type t) const{
        switch (t){
            case Type (0):
                return "COMPUTER_LAB";
            case Type (1):
                return "LECTURE_HALL";
            case Type (2):
                return "CLASSROOM";
        }
        return std::__cxx11::string();
    }

    void academia::Room::Serialize(academia::Serializer *serializer) const {
        serializer->Header("room");
        serializer->IntegerField("id", id_);
        serializer->StringField("name", name_);
        serializer->StringField("type", this->TypeToString(type_));
        serializer->Footer("room");
    }

    void academia::Building::Serialize(academia::Serializer *serializer) {
        serializer->Header("building");
        serializer->IntegerField("id", id_);
        serializer->StringField("name", name_);
        serializer->ArrayField("rooms", Reference_vector_to_rooms());
        serializer->Footer("building");
    }

    academia::Building::Building(int id_, const std::string &name_,
                                 std::initializer_list<const academia::Room> rooms):id_(id_), name_(name_) {
        for (auto &room:rooms){
            rooms_.emplace_back(room);
        }
    }
    void academia::Building::Serialize(academia::Serializer *serializer) const {
        serializer->Header("building");
        serializer->IntegerField("id", id_);
        serializer->StringField("name", name_);
        serializer->ArrayField("rooms", Reference_vector_to_rooms());
        serializer->Footer("building");
    }

    void JsonSerializer::IntegerField(const std::string &field_name, int value) {
        this->Distance();
        *(out_)<<"\""<<field_name<<"\": "<<value;

    }

    void JsonSerializer::DoubleField(const std::string &field_name, double value) {
        this->Distance();
        *(out_)<<"\""<<field_name<<"\": "<<value;
    }

    void JsonSerializer::StringField(const std::string &field_name, const std::string &value) {
        this->Distance();
        *(out_)<<"\""<<field_name<<"\": \""<<value<<"\"";
    }

    void JsonSerializer::BooleanField(const std::string &field_name, bool value) {
        this->Distance();
        *(out_)<<"\""<<field_name<<"\": \"";
        if (value)
            *out_<<"true";
        else
            *out_<<"false";
        *(out_)<<"\"";

    }

    void JsonSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
        this->Distance();
        *(out_)<<"\""<<field_name<<"\": \"";
        JsonSerializer sub_serializer(out_);
        value.Serialize(&sub_serializer);

    }

    void JsonSerializer::ArrayField(const std::string &field_name,
                                    const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {
        this->Distance();
        *(out_)<<"\""<<field_name<<"\": [";
        if (!value.empty()){
            JsonSerializer sub_serializer(out_);
            value[0].get().Serialize(&sub_serializer);
        }
        for (int i=1;i<value.size();++i){
            JsonSerializer sub_serializer(out_);
            *(out_)<<", ";
            value[i].get().Serialize(&sub_serializer);
        }
        *(out_)<<"]";

    }

    void JsonSerializer::Header(const std::string &object_name) {
        *(out_)<<"{";
        is_first_= true;

    }

    void JsonSerializer::Footer(const std::string &object_name) {
        *(out_)<<"}";
    }

    JsonSerializer::JsonSerializer(std::ostream *out) : Serializer(out) {
        out_ = out;

    }

    Serializer::Serializer(std::ostream *out) {
        out_ = out;

    }

    void academia::JsonSerializer::Distance() {
        if(is_first_){
            is_first_= false;
        } else {
            *out_<<", ";
        }
    }


    XmlSerializer::XmlSerializer(std::ostream *out) : Serializer(out) {

    }

    void XmlSerializer::IntegerField(const std::string &field_name, int value) {
        *(out_)<<"<"<<field_name<<">"<<value<<"<\\"<<field_name<<">";

    }

    void XmlSerializer::DoubleField(const std::string &field_name, double value) {
        *(out_)<<"<"<<field_name<<">"<<value<<"<\\"<<field_name<<">";

    }

    void XmlSerializer::StringField(const std::string &field_name, const std::string &value) {
        *(out_)<<"<"<<field_name<<">"<<value<<"<\\"<<field_name<<">";

    }

    void XmlSerializer::BooleanField(const std::string &field_name, bool value) {
        *(out_)<<"<"<<field_name<<">";
        if (value)
            *out_<<"true";
        else
            *out_<<"false";
    }

    void XmlSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
        *(out_)<<"<"<<field_name<<">";
        XmlSerializer sub_serializer(out_);
        value.Serialize(&sub_serializer);
    }

    void XmlSerializer::ArrayField(const std::string &field_name,
                                   const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {
        *(out_)<<"<"<<field_name<<">";
        if (!value.empty()){
            XmlSerializer sub_serializer(out_);
            value[0].get().Serialize(&sub_serializer);
        }
        for (int i=1;i<value.size();++i){
            XmlSerializer sub_serializer(out_);
            value[i].get().Serialize(&sub_serializer);
        }
        *(out_)<<"<\\"<<field_name<<">";

    }

    void XmlSerializer::Header(const std::string &object_name) {
        *(out_)<<"<"<<object_name<<">";

    }

    void XmlSerializer::Footer(const std::string &object_name) {
        *(out_)<<"<\\"<<object_name<<">";
    }

    void BuildingRepository::StoreAll(Serializer *serializer) const {
        serializer->Header("building_repository");
        serializer->ArrayField("buildings", this->Reference_vector_to_buildings());
        serializer->Footer("building_repository");
    }

    void BuildingRepository::Add(Building b) {
        buildings_.push_back(b);

    }

    std::experimental::optional<Building> BuildingRepository::operator[](int it) const{
        for (auto building:buildings_) {
            if (building.Id() == it) {
                return building;
            }
        }
    }


    std::vector<std::reference_wrapper<const Serializable>> Building::Reference_vector_to_rooms() const{
        std::vector<std::reference_wrapper<const Serializable>> result;
        for (auto &room:rooms_) {
            result.emplace_back(std::cref(room));
        }
        return result;
    }

    int Building::Id() const {
        return id_;
    }

    BuildingRepository::BuildingRepository(std::initializer_list<const academia::Building> buildings) {
        for (auto &building:buildings){
            buildings_.emplace_back(building);
        }
    }

    std::vector<std::reference_wrapper<const Serializable>>BuildingRepository::Reference_vector_to_buildings() const {
        std::vector<std::reference_wrapper<const Serializable>> result;
        for (auto &building:buildings_) {
            result.emplace_back(std::cref(building));
        }
        return result;
    }

}
