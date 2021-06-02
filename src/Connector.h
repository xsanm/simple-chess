//
// Created by xsan on 01.06.2021.
//

#ifndef SIMPLE_CHESS_CONNECTOR_H
#define SIMPLE_CHESS_CONNECTOR_H


#include <cstdio>
#include <iostream>
#include <string>
#include <array>
#include <memory>

class Connector {
public:
    static std::string getNextMove(std::string position);
};


#endif //SIMPLE_CHESS_CONNECTOR_H
