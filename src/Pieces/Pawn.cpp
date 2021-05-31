//
// Created by xsan on 28.05.2021.
//

#include <iostream>
#include "Pawn.h"

bool Pawn::isPossibleToMove() {
    return false;
}

Pawn::Pawn(BoardVector position1, Color color1, std::string textureUrl1) : ChessPiece(position1, color1, textureUrl1) {
    isFirst = true;
}

std::vector<BoardVector> Pawn::possibleMoves(const std::vector<ChessPiece *> &pieces) {
    std::vector<BoardVector> result = Pawn::attackingMoves(pieces);
    result.push_back(this->position);
    //std::cout << "Hello ";
    int y = position.getY();
    int y2 = position.getY();
    int x = position.getX();
    y = color == white ? y + 1 : y - 1;
    y2 = color == white ? y2 + 2 : y2 - 2;

    bool possibleForward = true;
    bool possibleDoubleForward = isFirst;
    for (int j = 0; j < pieces.size(); j++) {
        if (possibleForward && pieces[j]->getPosition() == BoardVector(x, y)) {
            possibleForward = false;
        }
        if (possibleDoubleForward && pieces[j]->getPosition() == BoardVector(x, y2)) {
            possibleDoubleForward = false;
        }
    }
    if (possibleForward) {
        //std::cout << x << ' ' <<  y << std::endl;
        result.push_back(BoardVector(x, y));
    }
    if (possibleDoubleForward) {
        //std::cout << x << ' ' <<  y << std::endl;
        result.push_back(BoardVector(x, y2));
    }
    return result;
}

void Pawn::move(BoardVector position) {

    //std::cout << this->position.getX() << " " << this->position.getY() << '\n';
    //std::cout << position.getX() << " " << position.getY() << '\n';
    if ((!(position == this->position)) && isFirst) {
        isFirst = false;
    }
    ChessPiece::move(position);
}

std::vector<BoardVector> Pawn::attackingMoves(const std::vector<ChessPiece *> &pieces) {
    std::vector<BoardVector> result;
    int y = position.getY();
    int x = position.getX();
    y = color == white ? y + 1 : y - 1;

    for (int j = 0; j < pieces.size(); j++) {
        if (pieces[j]->getPosition() == BoardVector(x + 1, y) && pieces[j]->getColor() != color) {
            result.push_back(BoardVector(x + 1, y));
        }
        if (pieces[j]->getPosition() == BoardVector(x - 1, y) && pieces[j]->getColor() != color) {
            result.push_back(BoardVector(x - 1, y));
        }
    }

    return result;
}




