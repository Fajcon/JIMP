//
// Created by ficon on 10.04.18.
//

#ifndef JIMP_EXERCISES_STUDENT_H
#define JIMP_EXERCISES_STUDENT_H

#include<iostream>
namespace academia {
    class StudyYear {
    private:
        int year_;

    public:
        StudyYear &operator++();

        StudyYear &operator--();
    };


    class Student {

    private:
        std::string id, first_name, last_name, program;
        StudyYear year;


    };


}
#endif //JIMP_EXERCISES_STUDENT_H
