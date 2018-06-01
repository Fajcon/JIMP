//
// Created by ficon on 01.06.18.
//

#ifndef JIMP_EXERCISES_ACADEMIATEACHERHASH_H
#define JIMP_EXERCISES_ACADEMIATEACHERHASH_H

#include <string>

namespace academia {
    class TeacherId{
    public:
        TeacherId(int id);
        operator int () const;

    private:
        int id_;

    };

    class Teacher{
    public:
        Teacher(const TeacherId &id, const std::string &name, const std::string &department);
        const TeacherId &Id() const;
        const std::string &Name() const;
        const std::string &Department() const;

    private:
        TeacherId id_;
        std::string name_;
        std::string department_;
    };


    class TeacherHash {

    };
}

#endif //JIMP_EXERCISES_ACADEMIATEACHERHASH_H
