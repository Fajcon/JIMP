//
// Created by fajcon on 11.03.18.
//

#include "GreatestProduct.h"
#include <vector>

int GreatestProduct(const std::vector<int> &numbers, int k){


    if (numbers.size() == 2)
        return numbers.back()*numbers.front();

    int h=1, l=1;
    std::vector<int> another_vector;



        for (int v : numbers){
        if (another_vector.size() > 0) {
            if(v>=another_vector.back()) {
                another_vector.push_back(v);
            }

        }
        else
            another_vector.push_back(v);
    }

    for (int i = 1; i <= k; ++i) {
        h = h * another_vector[another_vector.size()-i];

    }

    return h;

}