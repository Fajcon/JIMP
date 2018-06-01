//
// Created by ficon on 29.05.18.
//

#ifndef JIMP_EXERCISES_TREEITERATORS_H
#define JIMP_EXERCISES_TREEITERATORS_H

#include "Tree.h"

namespace tree {
    template <class T>
    class InOrderTreeIterator{
        InOrderTreeIterator<T> operator++(){

        };
        T operator* (){

        };
        bool operator!= (T){
            if(1){
                return true;
            }
            else {
                return false;
            }
        };

    };

    template <class T>
    class InOrderTreeView{
    public:
        InOrderTreeIterator<T> begin(){

        }
        InOrderTreeIterator<T> end(){

        }

    };

    template<class T>
    class InOrder {


    };

}


#endif //JIMP_EXERCISES_TREEITERATORS_H
