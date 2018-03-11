//
// Created by ficojaku on 06.03.18.
//

#include "Polybius.h"
#include <string>
#include <fstream>
#include <map>

bool getBoolean(const std::string &message, int i);

std::string PolybiusCrypt(std::string message){

    std::string crypted;
    std::map<char, int> v = {
            {'a', 11},
            {'b', 12},
            {'c', 13},
            {'d', 14},
            {'e', 15},
            {'f', 21},
            {'g', 22},
            {'h', 23},
            {'i', 24},
            {'j', 24}, // same as I
            {'k', 25},
            {'l', 31},
            {'m', 32},
            {'n', 33},
            {'o', 34},
            {'p', 35},
            {'q', 41},
            {'r', 42},
            {'s', 43},
            {'t', 44},
            {'u', 45},
            {'v', 51},
            {'w', 52},
            {'x', 53},
            {'y', 54},
            {'z', 55},
            {'A', 11},
            {'B', 12},
            {'C', 13},
            {'D', 14},
            {'E', 15},
            {'F', 21},
            {'G', 22},
            {'H', 23},
            {'I', 24},
            {'J', 24}, // same as I
            {'K', 25},
            {'L', 31},
            {'M', 32},
            {'N', 33},
            {'O', 34},
            {'P', 35},
            {'Q', 41},
            {'R', 42},
            {'S', 43},
            {'T', 44},
            {'U', 45},
            {'V', 51},
            {'W', 52},
            {'X', 53},
            {'Y', 54},
            {'Z', 55},
    };
    for (int i = 0; i < message.length() ; ++i) {
        if(getBoolean(message, i))
            return "";
        if(message[i] != ' ')
            crypted = crypted + std::to_string(v[message[i]]);

    }
    return crypted;
}

bool getBoolean(const std::string &message, int i) {
    return message[i] == 'ą' or message[i] == 'ę' or message[i] == 'ć' or message[i] == 'ż' or
                message[i] =='ź' or message[i] =='ł' or message[i] =='ó' or message[i] =='ń' or
                message[i] =='ś' or message[i] =='Ą' or message[i] =='Ę' or message[i] =='Ć' or
                message[i] =='Ź' or message[i] =='Ż' or message[i] =='Ł' or message[i] =='Ó' or
                message[i] =='Ń' or message[i] =='Ś';
}

std::string PolybiusDecrypt(std::string crypted){

    std::string message;

    const std::string square[5][5] = {
            {"a", "b", "c", "d", "e"},
            {"f", "g", "h", "i", "k"},
            {"l", "M", "N", "O", "P"},
            {"q", "r", "s", "t", "u"},
            {"v", "w", "x", "y", "z"},
    };

    for (int i = 0; i < crypted.length() ; i=i+2) {

        message = message + square[i][i+1];
    }

    return message;
}
