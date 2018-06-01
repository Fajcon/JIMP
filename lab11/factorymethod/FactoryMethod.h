//
// Created by ficon on 22.05.18.
//

#ifndef JIMP_EXERCISES_FACTORYMETHOD_H
#define JIMP_EXERCISES_FACTORYMETHOD_H

#include <functional>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

namespace factoryMethod {
    template<class T> T Create(){
        T a;
        return a;
    }

    class MyType{
    public:
        MyType();
        ~MyType();
        std::string SayHello();
    };

    template<class T> T Add( const T a, const T b) {
        return a + b;
    }

    template<class T> T Value(T a){
        return *a;
    }

    template<class T> T Mean(std::vector<T> vectorT){
        T sum = std::accumulate(vectorT.begin(), vectorT.end(), 0);
        return sum/vectorT.size();
    }

    template<class T>
    class Repository {
    public:
        auto Size() {
            return data_.size();
        }

        T operator[](int x) {
            return data_[x];
        }

        T NextId() {
            return ++last_id;
        }
        //T FindBy(Query){
          //  for( auto it : data_)
            //{
              //  if(it == Query){
                //    return it;
                //}
            //}

        //}
    private:
        std::vector<T> data_;
        int last_id;
    };

    class Logger{

    };

}


#endif //JIMP_EXERCISES_FACTORYMETHOD_H
