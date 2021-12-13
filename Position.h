//
// Created by Jason MacK on 2021-12-05.
//

#ifndef ASSIGNMENT_4_W0270109_POSITION_H
#define ASSIGNMENT_4_W0270109_POSITION_H

#include <ostream>

class Position {

private:
    int x;

    int y;

public:
    Position(int x, int y);

    Position();

    int getX() const;

    int getY() const;

    Position &operator=(const Position &right);

    friend std::ostream &operator<<(std::ostream &stream, Position &position);

};


#endif //ASSIGNMENT_4_W0270109_POSITION_H
