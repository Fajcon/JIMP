//
// Created by ficon on 08.03.18.
//

#include "DoubleBasePalindromes.h"
#include <iostream>
#include <string>
#include <cstdint>
#include <algorithm>

uint64_t DoubleBasePalindromes(int max_vaule_exculsive){

    uint64_t s = 0;
    std::string bin, str;

    for(int i=0; i<=max_vaule_exculsive; i++){
        bin = dec2bin(i);
        auto str = std::to_string(i);
        

        std::string copy(str);
        std::reverse(str.begin(),str.end());
        std::string copy2(bin);
        std::reverse(bin.begin(),bin.end());
        if((str == copy)&&(bin == copy2))
            s = s+i;
    }
    return s;
}

std::string dec2bin(int i){

    std::string result;
    do
    {
        if ( (i & 1) == 0 )
            result += "0";
        else
            result += "1";

        i >>= 1;
    } while ( i );

    return result;
}

