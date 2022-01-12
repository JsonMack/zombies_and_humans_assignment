//
// Created by Jason MacK on 2021-12-05.
//

#ifndef ASSIGNMENT_4_W0270109_POSITION_H
#define ASSIGNMENT_4_W0270109_POSITION_H

#include <ostream>

/**
 * Represents a position on the grid that an organism may maintain.
 */
class Position {

private:
    /**
     * The x position on the grid.
     */
    int x;

    /**
     * The y position on the grid.
     */
    int y;

public:

    /**
     * Creates a new position from the given x and y.
     *
     * @param x the value on the x-axis.
     * @param y the value on the y-axis.
     */
    Position(int x, int y);

    Position();

    /**
     * Gets the x for this position.
     *
     * @return the x on the grid.
     */
    int getX() const;

    /**
     * Gets the y for this position.
     *
     * @return the y on the grid.
     */
    int getY() const;

    /**
     * Overloads the assignment operator to assign the x and y.
     *
     * @param right the right position value.
     * @return the new position with the rights values assigned.
     */
    Position &operator=(const Position &right);

    /**
     * Overloads the bitwise-left operator (chevron) so that we can write to a ostream object.
     *
     * @param stream the stream we're writing to.
     * @param position the position, or x and y.
     * @return the new stream, modified.
     */
    friend std::ostream &operator<<(std::ostream &stream, Position &position);

};


#endif //ASSIGNMENT_4_W0270109_POSITION_H
