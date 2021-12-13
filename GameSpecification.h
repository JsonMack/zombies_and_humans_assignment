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
    static inline const int TILES = 20;

    static inline const int HUMANS = 100;

    static inline const int ZOMBIES = 5;

    static inline const int HUMAN_TICKS_UNTIL_RECRUIT = 3;

    static inline const int ZOMBIE_TICKS_UNTIL_BREED = 8;

    static inline const int ZOMBIE_TICKS_UNTIL_STARVE = 3;

    static inline const char IDENTIFIER_HUMAN = 'H';

    static inline const char IDENTIFIER_SPACE = ' ';

    static inline const char IDENTIFIER_ZOMBIE = 'Z';

    static inline const long DRAWING_PAUSE_MILLISECONDS = 1000;

    static inline const int MAXIMUM_TICKS = 1000;

    static inline const std::string MACOS_RED_COLOR = "\x1b[31m";

    static inline const std::string MACOS_BLUE_COLOR = "\x1b[34m";

    static inline const std::string MACOS_RESET_COLOR = "\x1b[0m";

    static inline const std::vector<DirectionOffset> CARDINAL_DIRECTIONS = std::vector<DirectionOffset>({
            DirectionOffset(-1, 0),
            DirectionOffset(1, 0),
            DirectionOffset(0, -1),
            DirectionOffset(0, 1)
    });

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
