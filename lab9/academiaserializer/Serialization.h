//
// Created by ficon on 08.05.18.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H

#include <iostream>
#include <string.h>
#include <functional>
#include <vector>

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
        std::ostream *out_;
    };

    class Serializable{
    public:
        virtual void Serialize(Serializer *serializer) = 0;

    };

    class Room : public Serializable{
    public:
        enum class Type{
            COMPUTER_LAB,
            LECTURE_HALL,
            CLASSROOM
        };

        void Serialize (Serializer *serializer) override;

        int id_;
        std::string name_;
        Type type_;

        Room(int id_, const std::string &name_, Type type_);

        std:: string TypeToString(Type t);
    };

    class Building : public Serializable{
        void Serialize (Serializer *serializer) override;
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

        std::ostream *out_;
    };
}

#endif //JIMP_EXERCISES_SERIALIZATION_H
