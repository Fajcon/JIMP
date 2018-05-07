//
// Created by ficon on 24.04.18.
//

#include "Pesel.h"

namespace academia{

    Pesel::Pesel(const char* input) {
        try{
            validatePesel(input);
        }catch(...){

        }
    }

    AcademiaDataValidationError::AcademiaDataValidationError(const std::string &message):
            std::runtime_error(message){

    }

    InvalidPeselChecksum::InvalidPeselChecksum(const std::string &message) :
            AcademiaDataValidationError(message) {

    }

    InvalidPeselLength::InvalidPeselLength(const std::string &message) :
            AcademiaDataValidationError(message) {

    }

    InvalidPeselCharacter::InvalidPeselCharacter(const std::string &message) :
            AcademiaDataValidationError(message) {

    }


    void Pesel::validatePesel(const char* input) {
        if(input.length != 11){
            throw InvalidPeselLength("Length error");
        }
        std::regex pattern(R"(\d[11])");
        std::smatch s;
        if(!(std::regex_match(input, s, pattern))){
            throw InvalidPeselCharacter("Character error");
        }

        if(9*(input[0]) + 7*input[1] + 3*input[2] + 1×d + 9×e + 7×f + 3×g + 1×h + 9×i + 7×j){

        }

    }
}