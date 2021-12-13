//
// Created by Jason MacK on 2021-12-05.
//

#include "NoPositionAvailableException.h"

const char *NoPositionAvailableException::what() const noexcept {
    return "No position available.";
}
