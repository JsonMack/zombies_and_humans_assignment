//
// Created by Jason MacK on 2021-12-05.
//

#ifndef ASSIGNMENT_4_W0270109_DIRECTIONOFFSET_H
#define ASSIGNMENT_4_W0270109_DIRECTIONOFFSET_H

/**
 * Represents a potential offset in a given direction on the x and y axis.
 */
class DirectionOffset {

private:
    /**
     * The offset on the x-axis.
     */
    int x;

    /**
     * The offset on the y-axis.
     */
    int y;

public:
    /**
     * Creates a new potential direction offset at the given x and y.
     *
     * @param x the x offset.
     * @param y the y offset.
     */
    DirectionOffset(int x, int y);

    DirectionOffset();

    /**
     * Gets the offset on the x axis.
     *
     * @return the offset.
     */
    int getX() const;

    /**
     * Gets the offset on the y axis.
     *
     * @return the offset.
     */
    int getY() const;
};


#endif //ASSIGNMENT_4_W0270109_DIRECTIONOFFSET_H
