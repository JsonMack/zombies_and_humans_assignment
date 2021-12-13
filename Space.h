//
// Created by Jason MacK on 2021-11-29.
//

#ifndef ASSIGNMENT_4_W0270109_SPACE_H
#define ASSIGNMENT_4_W0270109_SPACE_H

#include "Organism.h"

class Space : public Organism {

public:
    Space(Position position, City *city);

    Space(const Space &space);

    ~Space() override;

    void act() override;

    void move() override;

    char identifier() override;

    void reset() override;

};


#endif //ASSIGNMENT_4_W0270109_SPACE_H
