//
// Created by Jason MacK on 2021-12-06.
//

#ifndef ASSIGNMENT_4_W0270109_ZOMBIE_H
#define ASSIGNMENT_4_W0270109_ZOMBIE_H


#include "Organism.h"

class Zombie : public Organism {
private:
    int ticksUntilBreed;

    int defaultTicksUntilBreed;

    int ticksSinceEaten;

    int defaultTicksUntilStarve;

public:

    Zombie(const Position &position, City *city, int ticksUntilBreed, int defaultTicksUntilBreed,
           int ticksSinceEaten, int defaultTicksUntilStarve);

    Zombie();

    ~Zombie() override;

    void act() override;

    void move() override;

    void reset() override;

    char identifier() override;

    void breed();

    void starve();

};


#endif //ASSIGNMENT_4_W0270109_ZOMBIE_H
