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


}