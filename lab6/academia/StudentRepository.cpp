//
// Created by ficon on 10.04.18.
//

#include "StudentRepository.h"

namespace academia {
    StudyYear &StudyYear::operator++() {
        year_++;
        return *this;
    }

    StudyYear &StudyYear::operator--() {
        year_--;
        return *this;
    }

    
}
