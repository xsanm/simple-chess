//
// Created by xsan on 28.05.2021.
//

#include <string>
#include <iostream>
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

bool BoardVector::isOnBoardd() {
    return x >= 1 && x <= 8 && y >= 1 && y <= 8;
}

std::string BoardVector::toString() {
    std::string res = "";
    //std::cout << x << ' ' << y << '\n';
    res += char(x + 'a' - 1);
    res += char(y + '0');
    return res;
}


