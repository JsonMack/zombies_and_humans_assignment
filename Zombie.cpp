//
// Created by Jason MacK on 2021-12-06.
//

#include "Zombie.h"
#include "NoPositionAvailableException.h"
#include "Space.h"
#include "Human.h"

Zombie::Zombie(const Position &position, City *city, int ticksUntilBreed, int defaultTicksUntilBreed,
               int ticksSinceEaten, int defaultTicksUntilStarve) :
               Organism(position, city),
               ticksUntilBreed(ticksUntilBreed),
               defaultTicksUntilBreed(defaultTicksUntilBreed),
               ticksSinceEaten(ticksSinceEaten),
               defaultTicksUntilStarve(defaultTicksUntilStarve) { }

Zombie::Zombie() {}

Zombie::~Zombie() = default;

void Zombie::act() {
    if (!actable) {
        return;
    }
    move();

    if (moved && ticksUntilBreed <= 0) {
        breed();
    }

    if (ticksSinceEaten >= defaultTicksUntilStarve) {
        starve();
    }
    actable = false;
}

void Zombie::move() {
    try {
        Position originalPosition = this->position;

        Position open = city->randomAdjacentWithPriority(
                position, GameSpecification::ORDINAL_DIRECTIONS, set<char>({
                     GameSpecification::IDENTIFIER_SPACE,
                     GameSpecification::IDENTIFIER_HUMAN
                 }),
                 GameSpecification::IDENTIFIER_HUMAN);

        moved = true;

        if (ticksUntilBreed > 0) {
            ticksUntilBreed--;
        }
        Organism *organismAt = city->organismAt(open);

        if (organismAt->identifier() == GameSpecification::IDENTIFIER_HUMAN) {
            ticksSinceEaten = 0;
            city->setHumans(city->getHumans() - 1);
            city->deleteAt(open);
            city->setOrganism(open, this);
            city->setOrganism(originalPosition, new Space(originalPosition, city));
        } else {
            Organism *copyOfOrganismAt(organismAt);

            city->deleteAt(open);

            city->setOrganism(open, this);
            city->setOrganism(originalPosition, copyOfOrganismAt);
            ticksSinceEaten++;
        }
    } catch (NoPositionAvailableException &noSpaceAvailableException) {
        //do nothing, no point in handling unless we need to
    }
}

void Zombie::breed() {
    try {
        const Position humanPosition = city->
                randomAdjacent(position, GameSpecification::ORDINAL_DIRECTIONS,
                               set<char>({ GameSpecification::IDENTIFIER_HUMAN }));

        auto *zombie = new Zombie(humanPosition, city,
                                  GameSpecification::ZOMBIE_TICKS_UNTIL_BREED,
                                  GameSpecification::ZOMBIE_TICKS_UNTIL_BREED,
                                  0,
                                  GameSpecification::ZOMBIE_TICKS_UNTIL_STARVE);

        zombie->setActable(false);
        city->setZombies(city->getZombies() + 1);
        city->setHumans(city->getHumans() - 1);
        city->deleteAt(humanPosition);
        city->setOrganism(humanPosition, zombie);
        ticksUntilBreed = defaultTicksUntilBreed;
    } catch (NoPositionAvailableException &noPositionAvailableException) {
        /**
         * No need to do anything. The ticksUntilBreed is still 0 or negative, and on next eat/move,
         * the zombie will attempt to eat again.
         */
    }
}

void Zombie::starve() {
    Position position = this->position;

    city->setHumans(city->getHumans() + 1);
    city->setZombies(city->getZombies() - 1);
    city->deleteAt(position);
    city->setOrganism(position, new Human(position, city,
                                          GameSpecification::HUMAN_TICKS_UNTIL_RECRUIT,
                                          GameSpecification::HUMAN_TICKS_UNTIL_RECRUIT));
}

void Zombie::reset() {
    actable = true;
    moved = false;
}

char Zombie::identifier() {
    return GameSpecification::IDENTIFIER_ZOMBIE;
}
