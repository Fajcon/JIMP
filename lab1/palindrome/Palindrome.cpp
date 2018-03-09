//
// Created by ficojaku on 06.03.18.
//

#include "Palindrome.h"
#include <string>
#include <algorithm>
#include <iostream>

bool is_palindrome(std::string str){

    std::string copy(str);
    std::reverse(str.begin(),str.end());
    //std::cout << str;
    if (str == copy)
        return true;
    else
        return false;
}