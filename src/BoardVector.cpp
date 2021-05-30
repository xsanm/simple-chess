//
// Created by xsan on 28.05.2021.
//

#include "BoardVector.h"

BoardVector::BoardVector(char x, int y) {
    this->x = x - 'a' + 1;
    this->y = y;
}

BoardVector::BoardVector(int x, int y) {
    this->x = x;
    this->y = y;
}

BoardVector::BoardVector() {}

int BoardVector::getX() const {
    return x;
}

int BoardVector::getY() const {
    return y;
}

bool operator==(const BoardVector &lhs, const BoardVector &rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y;
}


