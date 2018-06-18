//
// Created by ficon on 05.06.18.
//

#include "ArabicRoman.h"
#include <exception>
#include <stdexcept>
#include <regex>
std::string ArabicToRoman(int arabic){
    if (arabic == 0){
        throw (std::invalid_argument("Error 0 is not exist in Roman"));
    }
    if (arabic < 0){
        throw (std::invalid_argument("Error minus number is not exist in Roman"));
    }
    if (arabic > 3999){
        throw (std::invalid_argument("Error 3999 is not possible to convert in this implementation"));
    }
    std::string result;
    while(arabic >= 1000){
        result += "M";
        arabic -= 1000;
    }
    if(arabic >= 900){
        result += "CM";
        arabic -= 900;
    }
    if(arabic >= 500){
        result += "D";
        arabic -= 500;
    }
    if(arabic >= 400){
        result += "CD";
        arabic -= 400;
    }
    while(arabic >= 100){
        result += "C";
        arabic -= 100;
    }
    if(arabic >= 90){
        result += "XC";
        arabic -= 90;
    }
    if(arabic >= 50){
        result += "L";
        arabic -= 50;
    }
    while(arabic >= 10){
        result += "X";
        arabic -= 10;
    }
    if(arabic >= 9){
        result += "IX";
        arabic -= 9;
    }
    if(arabic >= 5){
        result += "V";
        arabic -= 5;
    }
    if(arabic >= 4){
        result += "IV";
        arabic -= 4;
    }
    while(arabic >= 1){
        result += "I";
        arabic -= 1;
    }
    return result;
}

std::string RomanToArabic(std::string roman) {
    std::regex pattern(R"([MDCLXVI]+)");
    if (!std::regex_match(roman, pattern)){
        throw (std::invalid_argument("Error, wrong signs"));
    }

}
