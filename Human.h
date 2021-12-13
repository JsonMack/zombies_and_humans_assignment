//
// Created by Jason MacK on 2021-11-27.
//

#ifndef ASSIGNMENT_4_W0270109_HUMAN_H
#define ASSIGNMENT_4_W0270109_HUMAN_H

#include "Organism.h"
#include "City.h"

/**
 * A human is essential an organism and as such it inherits from organism.
 */
class Human : public Organism {

private:

    /**
     * The number of ticks until the human can recruit. When this reaches zero, the human attempts to recruit.
     */
    int ticksUntilRecruit;

    /**
     * The number of ticks until the human can recruit. This value does not change.
     */
    int defaultTicksUntilRecruit;

public:
    Human(Position position, City *city, int ticksUntilRecruit, int defaultTicksUntilRecruit);

    Human(const Human &human);

    Human& operator=(const Human& right);

    ~Human() override;

    void recruit();

    void act() override;

    void move() override;

    char identifier() override;

    void reset() override;
};


#endif //ASSIGNMENT_4_W0270109_HUMAN_H
