//
// Created by Jason MacK on 2021-12-05.
//

#include "Position.h"

Position::Position(int x, int y) : x(x), y(y) {

}

Position::Position(): x(0), y(0) {}

int Position::getX() const {
    return x;
}

int Position::getY() const {
    return y;
}

std::ostream &operator<<(std::ostream &stream, Position &position) {
    return stream << "{ x: " << position.x << ", y: " << position.y << " }";
}

Position &Position::operator=(const Position &right) {
    this->x = right.x;
    this->y = right.y;

    return *this;
}
