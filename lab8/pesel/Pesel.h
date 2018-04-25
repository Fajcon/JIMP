//
// Created by ficon on 24.04.18.
//

#ifndef JIMP_EXERCISES_PESEL_H
#define JIMP_EXERCISES_PESEL_H

#include <stdexcept>
#include <string>
#include <regex>
#include <string.h>

namespace academia {
    class Pesel {

    public:

        Pesel(const char* input);

        void validatePesel(const std::string);


    };

    class AcademiaDataValidationError: public std::runtime_error{
    public:
        AcademiaDataValidationError(const std::string &message);

    };

    class InvalidPeselChecksum: public AcademiaDataValidationError{
    public:
        InvalidPeselChecksum(const std::string &message);

    };

    class InvalidPeselLength: public AcademiaDataValidationError{
    public:
        InvalidPeselLength(const std::string &message);
    };

    class InvalidPeselCharacter: public AcademiaDataValidationError {
    public:
        InvalidPeselCharacter(const std::string &message);
    };


}


#endif //JIMP_EXERCISES_PESEL_H
