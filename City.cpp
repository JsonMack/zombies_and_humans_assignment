//
// Created by Jason MacK on 2021-11-27.
//

#include "City.h"
#include <iostream>
#include "Organism.h"
#include "Space.h"
#include "NoPositionAvailableException.h"
#include <set>

using namespace std;

City::City(int tiles): tiles(tiles) {
    for (int y = 0; y < tiles; y++) {
        organisms[y] = vector<Organism*>(tiles);

        for (int x = 0; x < tiles; x++) {
            organisms[y][x] = new Space(Position(x, y), this);
        }
    }
}

City::~City() = default;

void City::act() {
    vector<Organism*> acted;

    for (int y = 0; y < tiles; y++) {
        for (int x = 0; x < tiles; x++) {
            Organism *organism = organisms[y][x];

            organism->act();

            if (!organism->isActable()) {
                acted.push_back(organism);
            }
        }
    }

    for (Organism *organism : acted) {
        organism->reset();
    }

    if (humans <= 0 || zombies <= 0) {
        extinctionLevelEvent = true;
    }
    tick++;
}

Organism *City::organismAt(Position position) {
    return organisms[position.getY()][position.getX()];
}

void City::setOrganism(Position position, Organism *organism) {
    organism->setPosition(position);
    organisms[position.getY()][position.getX()] = organism;
}

void City::deleteAt(Position position) {
    organisms[position.getY()][position.getX()] = nullptr;
}

ostream &operator<<(ostream &out, City &city) {
    out << "Generation<" << city.tick << ">\tHumans<" << city.humans << ">\tZombies<" << city.zombies << ">" << endl;

    for (int i = 0; i <= city.getTiles() * 3; i++) {
        out << "-";
    }
    out << endl;

    for (int y = 0; y < city.getTiles(); y++) {
        for (int x = 0; x < city.getTiles(); x++) {
            Organism *organism = city.organisms[y][x];

            if (organism->identifier() == GameSpecification::IDENTIFIER_ZOMBIE) {
                out << GameSpecification::MACOS_RED_COLOR;
            } else if (organism->identifier() == GameSpecification::IDENTIFIER_HUMAN) {
                out << GameSpecification::MACOS_BLUE_COLOR;
            }
            out << " " << organism->identifier() << " ";
            out << GameSpecification::MACOS_RESET_COLOR;
        }
        out << endl;
    }
    for (int i = 0; i <= city.getTiles() * 3; i++) {
        out << "-";
    }
    out << endl;

    if (city.extinctionLevelEvent) {
        out << "\x1b[31m" << "Extinction Level Event" << "\x1b[0m" << endl;
        if (city.humans <= 0) {
            out << GameSpecification::MACOS_RED_COLOR << "Zombies win!" << GameSpecification::MACOS_RESET_COLOR << endl;
        } else if (city.zombies <= 0) {
            out << GameSpecification::MACOS_BLUE_COLOR << "Humans win!" << GameSpecification::MACOS_RESET_COLOR << endl;
        }
    }

    return out;
}

vector<Position> City::adjacent(Position position, const vector<DirectionOffset> &directions, const set<char> &identifiers) {
    vector<Position> positions;

    for (DirectionOffset offset : directions) {
        Position positionAtOffset = Position(position.getX() + offset.getX(), position.getY() + offset.getY());

        if (!withinBounds(positionAtOffset)) {
            continue;
        }
        Organism *organism = organismAt(positionAtOffset);

        if (identifiers.find(organism->identifier()) != identifiers.end()) {
            positions.push_back(positionAtOffset);
        }
    }
    return positions;
}

Position City::randomAdjacentWithPriority(Position position, const vector<DirectionOffset> &directions,
                                 const set<char> &identifiers, char prioritizedIdentifier) {
    vector<Position> adjacentPositions = adjacent(position, directions, identifiers);

    vector<Position> prioritizedPositions;

    for (Position adjacentPosition : adjacentPositions) {
        Organism *organism = organismAt(adjacentPosition);

        if (organism->identifier() == prioritizedIdentifier) {
            prioritizedPositions.push_back(adjacentPosition);
        }
    }
    if (!prioritizedPositions.empty()) {
        return prioritizedPositions[rand() % prioritizedPositions.size()];
    }
    if (adjacentPositions.empty()) {
        throw NoPositionAvailableException();
    }
    return adjacentPositions[rand() % adjacentPositions.size()];
}

Position City::randomAdjacent(Position position, const vector<DirectionOffset> &directions,
                              const set<char> &identifiers) {
    vector<Position> adjacentPositions = adjacent(position, directions, identifiers);

    if (adjacentPositions.empty()) {
        throw NoPositionAvailableException();
    }
    return adjacentPositions[rand() % adjacentPositions.size()];
}

bool City::withinBounds(Position position) {
    return position.getX() >= 0 && position.getX() < tiles && position.getY() >= 0 && position.getY() < tiles;
}

int City::getHumans() const {
    return humans;
}

int City::getZombies() const {
    return zombies;
}

void City::setHumans(int humans) {
    City::humans = humans;
}

void City::setZombies(int zombies) {
    City::zombies = zombies;
}

bool City::isExtinctionLevelEvent() const {
    return extinctionLevelEvent;
}

int City::getTick() const {
    return tick;
}
