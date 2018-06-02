//
// Created by ficon on 02.06.18.
//

#ifndef JIMP_EXERCISES_SEQUENTIALGENERATOR_H
#define JIMP_EXERCISES_SEQUENTIALGENERATOR_H

template <class C, typename T>
class SequentialIdGenerator{
public:
    SequentialIdGenerator(){
        idCounter_=T(0);
    }
    SequentialIdGenerator(T startValue){
        idCounter_=startValue;
    }
    C NextValue(){
        C id(idCounter_);
        ++idCounter_;
        return id;
    }

private:
    T idCounter_;
};


#endif //JIMP_EXERCISES_SEQUENTIALGENERATOR_H
