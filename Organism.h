//
// Created by Jason MacK on 2021-11-27.
//

#ifndef ASSIGNMENT_4_W0270109_ORGANISM_H
#define ASSIGNMENT_4_W0270109_ORGANISM_H

#include "City.h"

class Organism {

protected:

    /**
     * The position of the organism on the grid, containing the x and y coordinates.
     */
    Position position;

    /**
     * The organism has moved during this tick.
     */
    bool moved = false;

    /**
     * Determines if this organism can act at any level.
     */
    bool actable = false;

    /**
     * The city object that this human resides in.
     */
    City *city;

public:
    Organism();

    Organism(Position position, City *city);

    Organism(const Organism& organism);

    virtual ~Organism() = 0;

    Organism& operator=(const Organism &right);

    /**
     * Allows the organism to perform a number of actions in a given order.
     */
    virtual void act() = 0;

    /**
     * Allows the organism to move in 1 direction. The organism cannot move if the tile is occupied.
     */
    virtual void move() = 0;

    /**
     * A function that resets the organisms internal state for the next action, or act.
     */
    virtual void reset() = 0;

    /**
     * The character that represents this organism.
     *
     * @return the character.
     */
    virtual char identifier() = 0;

    /**
     * Sets the position of this organism.
     *
     * @param position the new position of this organism on the grid.
     */
    virtual void setPosition(Position position);

    void setActable(bool actable);

    /**
     * Determines whether or not this entity, or organism, has moved.
     *
     * @return true if the entity has moved.
     */
    bool hasMoved() const {
        return moved;
    }

    bool isActable() const;

    const Position &getPosition() const;

};


#endif //ASSIGNMENT_4_W0270109_ORGANISM_H
