//
// Created by Jason MacK on 2021-11-27.
//

#include <random>
#include <iostream>
#include "Human.h"
#include "City.h"
#include "NoPositionAvailableException.h"

using namespace std;

Human::Human(Position position, City *city, int ticksUntilRecruit, int defaultTicksUntilRecruit): Organism(position, city),
    ticksUntilRecruit(ticksUntilRecruit), defaultTicksUntilRecruit(defaultTicksUntilRecruit) {
}

Human &Human::operator=(const Human &right) {
    this->position = right.position;
    this->city = right.city;
    this->moved = right.moved;
    this->ticksUntilRecruit = right.ticksUntilRecruit;
    this->defaultTicksUntilRecruit = right.defaultTicksUntilRecruit;
    this->actable = right.actable;

    return *this;
}

Human::~Human() {
    std::cout << "Deleting human at (" << this->position << ")" << endl;
};

void Human::act() {
    if (!actable) {
        return;
    }
    if (!moved) {
        move();
    }
    if (ticksUntilRecruit <= 0) {
        recruit();
        ticksUntilRecruit = defaultTicksUntilRecruit;
    }
    actable = false;
}

void Human::move() {
    const vector<DirectionOffset> offset = GameSpecification::CARDINAL_DIRECTIONS;

    try {
        Position originalPosition = this->position;

        Position open = city->randomAdjacent(position, offset,
                                             set<char>({ GameSpecification::IDENTIFIER_SPACE }));

        moved = true;

        ticksUntilRecruit--;

        Organism *spaceAt = city->organismAt(open);

        Organism *copyOfOrganismAt(spaceAt);

        city->deleteAt(open);
        city->setOrganism(open, this);
        city->setOrganism(originalPosition, copyOfOrganismAt);
    } catch (NoPositionAvailableException &noSpaceAvailableException) {
        //do nothing, no point in handling unless we need to
    }
}

void Human::recruit() {
    try {
        Position open = city->randomAdjacent(position, GameSpecification::CARDINAL_DIRECTIONS,
                                             set<char>({ GameSpecification::IDENTIFIER_SPACE }));

        auto *newHuman = new Human(open, city, defaultTicksUntilRecruit, defaultTicksUntilRecruit);

        newHuman->setActable(false);

        city->deleteAt(open);
        city->setOrganism(open, newHuman);
        city->setHumans(city->getHumans() + 1);
    } catch (NoPositionAvailableException &noSpaceAvailableException) {
        //do nothing, right?
    }
}

void Human::reset() {
    actable = true;
    moved = false;
}

char Human::identifier() {
    return GameSpecification::IDENTIFIER_HUMAN;
}

Human::Human(const Human &human): Organism(human) {
    this->ticksUntilRecruit = human.ticksUntilRecruit;
    this->defaultTicksUntilRecruit = human.defaultTicksUntilRecruit;
}
