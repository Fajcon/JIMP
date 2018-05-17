//
// Created by ficon on 08.05.18.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H

#include <iostream>
#include <string.h>
#include <functional>
#include <vector>
#include <list>
#include <experimental/optional>

namespace academia {

    class Serializable;

    class Serialization {

    };

    class Serializer{
    protected:
        Serializer(std::ostream* out);
    public:
        virtual void IntegerField(const std::string &field_name, int value) = 0;
        virtual void DoubleField(const std::string &field_name, double value) = 0;
        virtual void StringField(const std::string &field_name, const std::string &value) = 0;
        virtual void BooleanField(const std::string &field_name, bool value) = 0;
        virtual void SerializableField(const std::string &field_name, const academia::Serializable &value) = 0;
        virtual void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const academia::Serializable>> &value) = 0;
        virtual void Header(const std::string &object_name) = 0;
        virtual void Footer(const std::string &object_name) = 0;
    protected:
        std::ostream *out_;
    };

    class Serializable{
    public:
        virtual void Serialize(Serializer *serializer) = 0;
        virtual void Serialize (academia::Serializer *serializer) const =0;

    };

    class Room : public Serializable{
    public:
        enum class Type{
            COMPUTER_LAB,
            LECTURE_HALL,
            CLASSROOM
        };

        void Serialize (Serializer *serializer) override;

        void Serialize(academia::Serializer *serializer) const override;


        int id_;
        std::string name_;
        Type type_;

        Room(int id_, const std::string &name_, Type type_);

        std:: string TypeToString(Type t) const;
    };

    class Building : public Serializable{
    public:
        Building(int id_, const std::string &name_, std::initializer_list<const academia::Room> rooms);

        void Serialize(academia::Serializer *serializer) override;

        void Serialize(academia::Serializer *serializer) const override;

        int Id() const;

        int id_;
        std::string name_;

        std::vector<std::reference_wrapper<const Serializable>> Reference_vector_to_rooms() const;

        std::vector<academia::Room> rooms_;
    };

    class JsonSerializer : public Serializer{
    public:
        JsonSerializer(std::ostream *out);

        void IntegerField(const std::string &field_name, int value) override;

        void DoubleField(const std::string &field_name, double value) override;

        void StringField(const std::string &field_name, const std::string &value) override;

        void BooleanField(const std::string &field_name, bool value) override;

        void SerializableField(const std::string &field_name, const academia::Serializable &value) override;

        void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const academia::Serializable>> &value) override;

        void Header(const std::string &object_name) override;

        void Footer(const std::string &object_name) override;

    private:
        void Distance();

        bool is_first_=true;

    };

    class XmlSerializer:public Serializer{
    public:
        explicit XmlSerializer(std::ostream *out);

        void IntegerField(const std::string &field_name, int value) override;

        void DoubleField(const std::string &field_name, double value) override;

        void StringField(const std::string &field_name, const std::string &value) override;

        void BooleanField(const std::string &field_name, bool value) override;

        void SerializableField(const std::string &field_name, const academia::Serializable &value) override;

        void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const academia::Serializable>> &value) override;

        void Header(const std::string &object_name) override;

        void Footer(const std::string &object_name) override;
    };

    class BuildingRepository{
    public:
        BuildingRepository(std::initializer_list<const academia::Building> buildings);
        void StoreAll(Serializer *serializer) const;
        void Add(Building);
        std::vector<Building> buildings_;
        std::experimental::optional<Building>  operator [](int) const;
        std::vector<std::reference_wrapper<const Serializable>> Reference_vector_to_buildings() const;
    };
}

#endif //JIMP_EXERCISES_SERIALIZATION_H
