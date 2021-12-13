//
// Created by Jason MacK on 2021-12-05.
//

#include "DirectionOffset.h"

DirectionOffset::DirectionOffset(int x, int y) : x(x), y(y) {}

DirectionOffset::DirectionOffset(): x(0), y(0) {}

int DirectionOffset::getX() const {
    return x;
}

int DirectionOffset::getY() const {
    return y;
}
