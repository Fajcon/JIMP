//
// Created by ficon on 17.04.18.
//

#include <cstdlib>
#include "ArrayFill.h"
namespace arrays {

    IncrementalFill::IncrementalFill(int start, int step) : start(start), step(step) {}

    int IncrementalFill::Value(int index) const {
        int result = start + index*step;
        return result;
    }

    int UniformFill::Value(int index) const {
        return value_;
    }

    RandomFill::RandomFill() {

    }

    int RandomFill::Value(int index) const {
        std::rand();
        return 0;
    }

    void FillArray(size_t size, const ArrayFill &filler, std::vector<int> *v) {
        v->clear();
        v->reserve(size);
        for (size_t i = 0; i < size; i++) {
            v->emplace_back(filler.Value(i));
        }
    }

    SquaredFill::SquaredFill(int a , int b) {
        a_ = a;
        b_ = b;

    }
    int SquaredFill::Value(int index) const {
        int result;
        result = a_*(index*index)+b_;
        return result;
    }
}