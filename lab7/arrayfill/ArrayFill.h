//
// Created by ficon on 17.04.18.
//

#ifndef JIMP_EXERCISES_ARRAYFILL_H
#define JIMP_EXERCISES_ARRAYFILL_H

#include <cstddef>
#include <vector>

namespace arrays {
    class ArrayFill {
    public:
        virtual int Value(int index) const =0;
    };

    class IncrementalFill: public ArrayFill{
    public:
        IncrementalFill(int start, int step = 1);
        int Value(int index) const override;
    private:
        int start;
        int step;

    };

    class UniformFill: public ArrayFill{
    public:
        UniformFill(int value = 0) : value_{value} {}
        virtual int Value(int index) const override;
    private:
        int value_;
    };

    class SquaredFill: public ArrayFill{
    public:
        SquaredFill(int a = 1, int b = 0);
        int Value(int index) const override;
    private:
        int a_;
        int b_;
    };

    class RandomFill: public ArrayFill{
    public:
        RandomFill();
        int Value(int index) const override;
    private:
    };

    void FillArray(size_t size, const ArrayFill &filler, std::vector<int> *v);

}


#endif //JIMP_EXERCISES_ARRAYFILL_H
