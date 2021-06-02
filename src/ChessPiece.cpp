//
// Created by xsan on 28.05.2021.
//

#include <iostream>
#include "ChessPiece.h"

const BoardVector &ChessPiece::getPosition() const {
    return position;
}


Color ChessPiece::getColor() const {
    return color;
}

ChessPiece::ChessPiece(BoardVector position) {
    this->position = position;
}

void ChessPiece::move(BoardVector position) {
    this->position = position;
}


sf::Sprite &ChessPiece::getSPiece() {
    return sPiece;
}

ChessPiece::ChessPiece(BoardVector position, Color color, std::string textureURL) {
    this->position = position;
    this->color = color;
    this->t1.loadFromFile(textureURL);
    sPiece = sf::Sprite(this->t1);
    sPiece.setScale(sf::Vector2f(0.4, 0.4));
    sPiece.setPosition(SquareSize * (position.getX() - 1) + SquareOffset + 3, SquareSize * (8 - position.getY()) + SquareOffset);
}

std::vector<BoardVector> ChessPiece::possibleMoves(const std::vector<ChessPiece *> &pieces) {
    return std::vector<BoardVector>();
}

int ChessPiece::checkSquare(const std::vector<ChessPiece *> &pieces, BoardVector possibility, Color color) { //0 no, 1 free, 2 beat
    if(!possibility.isOnBoardd()) return 0;
    for (int j = 0; j < pieces.size(); j++) {
        if (pieces[j]->getPosition() == possibility) {
            if (pieces[j]->getColor() == color) return 0;
            else return 2;
        }
    }
    return 1;
}

std::vector<BoardVector> ChessPiece::attackingMoves(const std::vector<ChessPiece *> &pieces) {
    return std::vector<BoardVector>();
}

bool ChessPiece::amIKing() {
    return false;
}


