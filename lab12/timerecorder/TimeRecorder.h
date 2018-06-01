//
// Created by ficon on 01.06.18.
//

#ifndef JIMP_EXERCISES_TIMERECORDER_H
#define JIMP_EXERCISES_TIMERECORDER_H

#include <vector>
#include <chrono>

namespace profiling {
    template<class T>
    auto TimeRecorder(T t) {
        auto start = std::chrono::system_clock::now();
        auto value = t();
        double duration = std::chrono::duration<double, std::milli>
                (std::chrono::system_clock::now() - start).count();
        return std::make_pair(value, duration);
    };
}


#endif //JIMP_EXERCISES_TIMERECORDER_H
