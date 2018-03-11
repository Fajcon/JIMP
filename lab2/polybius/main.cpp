//
// Created by ficojaku on 06.03.18.
//

#include <iostream>
#include <fstream>
#include <string>
#include "Polybius.h"

int main()
{
    std::string word;
    std::ifstream myfile("file.txt");
    while(myfile >> word){
        PolybiusCrypt(word);
    }
    return 0;
}