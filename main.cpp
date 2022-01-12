#include <iostream>
#include "City.h"
#include "Human.h"
#include "Zombie.h"
#include <thread>
#include <random>
#include <vector>
#include "GameSpecification.h"
#include

/**
 * Reference: http://www.cplusplus.com/reference/algorithm/shuffle/
 */

using namespace std;

/**
 * Creates a new simulation and returns a pointer to the created City object.
 *
 * @param print determines whether or not information about the city will print to the console.
 * @param sleep the time in milliseconds that the thread should sleep between city actions.
 * @return a new city.
 */
City* simulate(bool print, chrono::milliseconds sleep);

/**
 * Prepares the city reference by populating humans and zombies.
 *
 * @param city the city we're preparing.
 * @param humans the amount of humans to generate.
 * @param zombies the number of zombies to generate.
 * @param tiles the number of tiles for the city.
 */
void prepare(City &city, int humans, int zombies, int tiles);

/**
 * Creates a number of simulations and records the result from each of them. These
 * records are dumped to the console after execution. This may take upwards of 1-2 minutes
 * depending on the number of tests.
 */
void testMinimumGenerations(int tests);

/**
 * The entry point to the application. This can be used to test the minimum number of generated.
 * This is primarily used to create a single simulation of the city. The city is created on the heap,
 * and then disposed of.
 *
 * @return nothing.
 */
int main() {
    //testMinimumGenerations(100);

    Window window;

//    sf::Vector2<unsigned int> size(256, 256);
//
//    window.setSize(size);
//    window.display();

    this_thread::sleep_for(chrono::seconds(2));


    //City *city = simulate(true, chrono::milliseconds (GameSpecification::DRAWING_PAUSE_MILLISECONDS));

    //delete city;

    cout << "Simulation complete!" << endl;

    return 0;
}

City* simulate(bool print, chrono::milliseconds sleep) {
    City *city = new City(GameSpecification::TILES);

    prepare(*city, GameSpecification::HUMANS, GameSpecification::ZOMBIES, GameSpecification::TILES);

    if (print) {
        cout << *city << endl;
    }

    for (int tick = 0; tick < GameSpecification::MAXIMUM_TICKS; tick++) {
        city->act();

        if (print) {
            cout << *city << endl;
        }

        if (city->isExtinctionLevelEvent()) {
            break;
        }
        this_thread::sleep_for(sleep);
    }
    return city;
}

void testMinimumGenerations(int tests) {
    int humanWins = 0;

    int zombieWins = 0;

    int deadlocks = 0;

    int lessThanMinimum = 0;

    cout << "Executing " << tests << " tests, this may take a few seconds, or upwards of a minute.";

    for (int test = 0; test < tests; test++) {
        City *testCity = simulate(false, chrono::milliseconds(0));

        if (testCity->getHumans() <= 0) {
            zombieWins++;
        } else if (testCity->getZombies() <= 0) {
            humanWins++;
        }
        if (testCity->getTick() >= GameSpecification::MAXIMUM_TICKS) {
            deadlocks++;
        }
        if (testCity->getTick() < 100) {
            lessThanMinimum++;
        }
    }
    cout << "Human Wins\t" << "Zombie Wins\t" << "Deadlocks\t" << "LessThan100" << endl;
    cout << humanWins << "\t\t\t" << zombieWins << "\t\t\t" << deadlocks << "\t\t\t" << lessThanMinimum << endl;
}

void prepare(City &city, int humans, int zombies, int tiles) {
    if (humans + zombies > (tiles * tiles)) {
        throw invalid_argument("The number of humans and zombies exceeds the number of available tiles.");
    }
    vector<Position> available;

    for (int x = 0; x < tiles; x++) {
        for (int y = 0; y < tiles; y++) {
            available.emplace_back(x, y);
        }
    }
    random_device randomDevice;

    uniform_int_distribution<int> distribution(0, (int) available.size());

    shuffle(available.begin(), available.end(),
            std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count()));

    city.setHumans(humans);
    city.setZombies(zombies);

    while (humans > 0 || zombies > 0) {
        Position position = available.front();

        available.erase(available.begin());

        Organism *organism;

        if (humans > 0) {
            organism = new Human(position, &city, GameSpecification::HUMAN_TICKS_UNTIL_RECRUIT,
                      GameSpecification::HUMAN_TICKS_UNTIL_RECRUIT);

            humans--;
        } else {
            organism = new Zombie(position, &city,
                         GameSpecification::ZOMBIE_TICKS_UNTIL_BREED,
                         GameSpecification::ZOMBIE_TICKS_UNTIL_BREED,
                         0,
                         GameSpecification::ZOMBIE_TICKS_UNTIL_STARVE);
            zombies--;
        }
        organism->setActable(true);
        city.setOrganism(organism->getPosition(), organism);
    }
}
