//
// Created by ficon on 01.06.18.
//

#include "TeacherHash.h"
namespace academia{

    TeacherId::TeacherId(int id): id_(id) {
    }

    TeacherId::operator int() const {
        return id_;
    }

    bool TeacherId::operator!=(const TeacherId & other) const {
        return other.id_ != id_;
    }

    const TeacherId &Teacher::Id() const {
        return id_;
    }

    const std::string &Teacher::Name() const {
        return name_;
    }

    const std::string &Teacher::Department() const {
        return department_;
    }

    Teacher::Teacher(const TeacherId &id, const std::string &name, const std::string &department)
            : id_(id), name_(name), department_(department) {
    }

    bool Teacher::operator!=(const Teacher &other) const {
        return other.name_ != name_ || other.id_ != id_ || other.department_ != department_;
    }

    bool Teacher::operator==(const Teacher &other) const {
        return other.name_ == name_;
    }

    size_t TeacherHash::operator()(const Teacher &to_hash) const{
        size_t hash = std::hash<int>()(to_hash.Id());
        hash = 3*hash + std::hash<std::string>()(to_hash.Name());
        hash = 2*hash + std::hash<std::string>()(to_hash.Department());
        return hash;
    }


}