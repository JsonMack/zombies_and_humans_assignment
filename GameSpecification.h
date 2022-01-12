//
// Created by Jason MacK on 2021-12-07.
//

#ifndef ASSIGNMENT_4_W0270109_GAMESPECIFICATION_H
#define ASSIGNMENT_4_W0270109_GAMESPECIFICATION_H

#include "DirectionOffset.h"
#include <vector>
#include <string>

/**
 * Credits to the following URI which provides insight on using inline variables. This
 * will allow us to define and assign at the same time, and create a single instance which
 * can be used by multiple headers.
 *
 * https://www.fluentcpp.com/2019/07/23/how-to-define-a-global-constant-in-cpp/
 */
class GameSpecification {

public:
    /**
     * The number of tiles in the city.
     */
    static inline const int TILES = 5;

    /**
     * The number of humans that are generated initially in the city.
     */
    static inline const int HUMANS = 3;

    /**
     * The number of zombies that are generated initially in the city.
     */
    static inline const int ZOMBIES = 2;

    /**
     * The number of ticks the human must wait until they can recruit.
     */
    static inline const int HUMAN_TICKS_UNTIL_RECRUIT = 3;

    /**
     * The number of ticks until the zombie can breed.
     */
    static inline const int ZOMBIE_TICKS_UNTIL_BREED = 8;

    /**
     * The number of ticks until the zombie starves if it does not eat.
     */
    static inline const int ZOMBIE_TICKS_UNTIL_STARVE = 3;

    /**
     * The unique identifier for the human.
     */
    static inline const char IDENTIFIER_HUMAN = 'H';

    /**
     * The unique identifier for the space organism.
     */
    static inline const char IDENTIFIER_SPACE = '.';

    /**
     * The unique identifier for the zombie identifier.
     */
    static inline const char IDENTIFIER_ZOMBIE = 'Z';

    /**
     * The milliseconds that the main thread will pause between each cities actions.
     */
    static inline const long DRAWING_PAUSE_MILLISECONDS = 1000;

    /**
     * The maximum number of ticks that exist before
     */
    static inline const int MAXIMUM_TICKS = 1000;

    /**
     * The unique red color identifier for mac.
     */
    static inline const std::string MACOS_RED_COLOR = "\x1b[31m";

    /**
     * The unique blue color identifier for mac.
     */
    static inline const std::string MACOS_BLUE_COLOR = "\x1b[34m";

    /**
     * The unique identifier that resets the current color.
     */
    static inline const std::string MACOS_RESET_COLOR = "\x1b[0m";

    /**
     * A set of directions that are north, east, soth, and est.
     */
    static inline const std::vector<DirectionOffset> CARDINAL_DIRECTIONS = std::vector<DirectionOffset>({
            DirectionOffset(-1, 0),
            DirectionOffset(1, 0),
            DirectionOffset(0, -1),
            DirectionOffset(0, 1)
    });

    /**
     * A set of directions that are cardinal, and all 4 points between, for a total of 8 points.
     */
    static inline const std::vector<DirectionOffset> ORDINAL_DIRECTIONS = std::vector<DirectionOffset>({
            DirectionOffset(-1, 0),
            DirectionOffset(1, 0),
            DirectionOffset(0, -1),
            DirectionOffset(0, 1),
            DirectionOffset(-1, 1),
            DirectionOffset(1, -1),
            DirectionOffset(1, 1),
            DirectionOffset(-1, -1)
    });

};

#endif //ASSIGNMENT_4_W0270109_GAMESPECIFICATION_H
