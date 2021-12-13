//
// Created by Jason MacK on 2021-12-05.
//

#ifndef ASSIGNMENT_4_W0270109_NOPOSITIONAVAILABLEEXCEPTION_H
#define ASSIGNMENT_4_W0270109_NOPOSITIONAVAILABLEEXCEPTION_H

#include <exception>
#include <string>

class NoPositionAvailableException : std::exception {
    const char *what() const _NOEXCEPT override;

};


#endif //ASSIGNMENT_4_W0270109_NOPOSITIONAVAILABLEEXCEPTION_H
