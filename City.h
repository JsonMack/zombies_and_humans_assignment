//
// Created by Jason MacK on 2021-11-27.
//

#ifndef ASSIGNMENT_4_W0270109_CITY_H
#define ASSIGNMENT_4_W0270109_CITY_H

#include <vector>
#include <set>
#include "Position.h"
#include "DirectionOffset.h"
#include "GameSpecification.h"

using namespace std;

class Organism;

class City {

private:

    /**
     * The positive amount of tiles that exist along both the width and height of this city.
     */
    int tiles;

    /**
     * The current 'tick' or 'cycle' that the city is currently on. This increments by 1
     * every time the cities organisms are processed.
     */
    int tick = 0;

    /**
     * A flag that determines if there has been an extinction level event.
     */
    bool extinctionLevelEvent = false;

    /**
     * A vector that contains a vector of organisms, such that we have a matrix or grid
     * of organisms.
     */
    Organism *organisms[GameSpecification::TILES][GameSpecification::TILES];

    /**
     * The total count of humans
     */
    int humans = 0;

    /**
     * The total count of zombies.
     */
    int zombies = 0;


public:

    /**
     * Creates a new city with a predefined length and width. It should be noted that the underlying
     * matrix should not be resizable at this time. The city cannot be a rectangle and must be a square.
     *
     * @param tiles the number of tiles in the city
     */
    City(int tiles);

    /**
     * The default destructor for the city which should deallocate all associated
     * organisms.
     */
    ~City();

    /**
     * Each iteration or cycle the city should have each of its organisms attempt to perform some action
     * if possible. When this occurs, the underlying 'tick' should increment by 1.
     */
    void act();

    /**
     * Determines if the x and y are within the bounds of the city.
     *
     * @param position the position containing a valid x and y.
     * @return true if within bounds, otherwise false.
     */
    bool withinBounds(Position position);

    /**
     * Retrieves the organism at the given coordinates.
     *
     * @param position the position we're checking if the organism exists at.
     * @return either a valid organism or nullptr if one doesn't exist.
     */
    Organism *organismAt(Position position);

    /**
     * Creates a new organism and assigns it to the given position.
     *
     * @param position the position of the organism we're updating.
     * @param organism the organism itself that is being added to the city.
     * @return
     */
    void setOrganism(Position position, Organism *organism);

    /**
     * Deletes an organism at a given x and y.
     *
     * @param position the position of the organism we're deleting.
     */
    void deleteAt(Position position);

    /**
     * Finds an open tile that has no organism on it (a space).
     *
     * @param position the position we're finding an open tile surrounding it.
     * @param directions the possible vector or list of directions.
     * @return a random direction, or nullptr if none.
     */
    vector<Position> adjacent(Position position, const vector<DirectionOffset> &directions,
                              const set<char> &identifiers);

    Position randomAdjacent(Position position, const vector<DirectionOffset> &directions,
                              const set<char> &identifiers);

    Position randomAdjacentWithPriority(Position position, const vector<DirectionOffset> &directions,
                             const set<char> &identifiers, char prioritizedIdentifier);

    /**
     * Writes this city object to the stream by overloading the << operator.
     *
     * @param stream the stream we're writing to and returning.
     * @param city the city we're printing out
     *
     * @return the modified stream.
     */
    friend ostream& operator<<(ostream &stream, City &city);

    /**
     * Retrieves the number of tiles in the city.
     *
     * @return the number of tiles.
     */
    const int &getTiles() {
        return tiles;
    }

    int getHumans() const;

    int getZombies() const;

    void setHumans(int humans);

    void setZombies(int zombies);

    bool isExtinctionLevelEvent() const;

    int getTick() const;
};


#endif //ASSIGNMENT_4_W0270109_CITY_H