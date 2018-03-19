//
// Created by fajcon on 15.03.18.
//

#include "MinimalTimeDifference.h"

#include <vector>
#include <sstream>
#include <regex>
#include <cmath>
#include <iostream>
#include <string>



namespace minimaltimedifference {

    unsigned int Dif(std::string time1, std::string time2){

        int h1, m1, m2, m, h2, h;

        std::string s_h1 = time1.substr(0, 2);
        std::string s_h2 = time2.substr(0, 2);
        std::string s_m1 = time1.substr(3, 2);
        std::string s_m2 = time2.substr(3, 2);
        std::istringstream iss(s_h1);
        iss >> h1;
        std::istringstream iss2(s_h2);
        iss2 >> h2;
        if (abs(h1-h2)>abs(h2-h1))
            h = h2-h1;
        else
            h = h1-h2;
        std::istringstream iss3(s_m1);
        iss3 >> m1;
        std::cout << m1 << std::endl;

    }
    unsigned int ToMinutes(std::string time_HH_MM) {
    }

    unsigned int MinimalTimeDifference(std::vector<std::string> times) {


        for (int i = 0; i < times.size(); ++i) {
            for (int j = i; j < times.size(); ++j) {


            }
        }
    }
}