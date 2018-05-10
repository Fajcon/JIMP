//
// Created by ficon on 08.05.18.
//

#include "Serialization.h"
namespace academia{

    void Room::Serialize(Serializer *serializer) {

        serializer -> Header("Room");
        serializer -> IntegerField("Id", id_);
        serializer -> StringField("Name", name_);
        serializer -> StringField("Type", TypeToString(type_));
        serializer -> Footer("Room");


    }

    Room::Room(int id_, const std::string &name_, Room::Type type_) : id_(id_), name_(name_), type_(type_) {}

    std::string Room::TypeToString(Room::Type t) {
        switch (t){
            case Type(0):
                return "COMPUTER LAB";
        }
    }

    void Building::Serialize(Serializer *serializer) {

    }

    void JsonSerializer::IntegerField(const std::string &field_name, int value) {
        (*out_)<<"\""<<field_name<<"\""<<value

    }

    void JsonSerializer::DoubleField(const std::string &field_name, double value) {

    }

    void JsonSerializer::StringField(const std::string &field_name, const std::string &value) {

    }

    void JsonSerializer::BooleanField(const std::string &field_name, bool value) {

    }

    void JsonSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {

    }

    void JsonSerializer::ArrayField(const std::string &field_name,
                                    const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {

    }

    void JsonSerializer::Header(const std::string &object_name) {
        *(out_)<<object_name;

    }

    void JsonSerializer::Footer(const std::string &object_name) {
        *(out_)<<object_name;
    }

    JsonSerializer::JsonSerializer(std::ostream *out) : Serializer(out) {
        out_ = out;

    }

    Serializer::Serializer(std::ostream *out) {
        out_ = out;

    }
}
