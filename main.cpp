#include <iostream>
#include "City.h"
#include "Human.h"
#include "Zombie.h"
#include <thread>
#include <random>
#include <vector>
#include "GameSpecification.h"

/**
 * Reference: http://www.cplusplus.com/reference/algorithm/shuffle/
 */

using namespace std;

City* simulate(bool print, chrono::milliseconds sleep);

void prepare(City *city, int humans, int zombies, int tiles);

void testMinimumGenerations();

int main() {
    //testMinimumGenerations();

    City *city = simulate(true, chrono::milliseconds (GameSpecification::DRAWING_PAUSE_MILLISECONDS));

    delete city;

    cout << "Simulation complete!" << endl;

    return 0;
}

City* simulate(bool print, chrono::milliseconds sleep) {
    City *city = new City(GameSpecification::TILES);

    prepare(city, GameSpecification::HUMANS, GameSpecification::ZOMBIES, GameSpecification::TILES);

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

void testMinimumGenerations() {
    int humanWins = 0;

    int zombieWins = 0;

    int deadlocks = 0;

    int lessThanMinimum = 0;

    for (int test = 0; test < 100; test++) {
        cout << "Executing test: " << test << endl;

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

void prepare(City *city, int humans, int zombies, int tiles) {
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

    city->setHumans(humans);
    city->setZombies(zombies);

    while (humans > 0 || zombies > 0) {
        Position position = available.front();

        available.erase(available.begin());

        Organism *organism;

        if (humans > 0) {
            organism = new Human(position, city, GameSpecification::HUMAN_TICKS_UNTIL_RECRUIT,
                      GameSpecification::HUMAN_TICKS_UNTIL_RECRUIT);

            humans--;
        } else {
            organism = new Zombie(position, city,
                         GameSpecification::ZOMBIE_TICKS_UNTIL_BREED,
                         GameSpecification::ZOMBIE_TICKS_UNTIL_BREED,
                         0,
                         GameSpecification::ZOMBIE_TICKS_UNTIL_STARVE);
            zombies--;
        }
        organism->setActable(true);
        city->setOrganism(organism->getPosition(), organism);
    }
}
