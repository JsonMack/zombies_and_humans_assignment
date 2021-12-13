//
// Created by Jason MacK on 2021-11-27.
//

#include "Organism.h"

Organism::Organism() : position(), moved(false), city(nullptr) {

}

Organism::Organism(Position position, City *city): position(position), city(city), moved(false) {

}

Organism::Organism(const Organism &organism) {
    //TODO inspect overloading = for position
    this->position = organism.position;
    this->city = organism.city;
    this->moved = organism.moved;
}

Organism &Organism::operator=(const Organism &right) {
    //TODO inspect overloading = for position
    this->position = right.position;
    this->city = right.city;
    this->moved = right.moved;

    return *this;
}

Organism::~Organism() = default;

void Organism::setPosition(Position position) {
    this->position = position;
}

bool Organism::isActable() const {
    return actable;
}

void Organism::setActable(bool actable) {
    Organism::actable = actable;
}

const Position &Organism::getPosition() const {
    return position;
}






