//
// Created by Jason MacK on 2021-11-29.
//

#include "Space.h"
#include <iostream>

Space::Space(Position position, City *city) : Organism(position, city) {

}

Space::Space(const Space &space) = default;

Space::~Space() {
    std::cout << "Deleting space at (" << position << ")" << std::endl;
};

void Space::act() {

}

void Space::move() {

}

char Space::identifier() {
    return GameSpecification::IDENTIFIER_SPACE;
}

void Space::reset() {

}
