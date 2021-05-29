//
// Created by xsan on 28.05.2021.
//

#include "ChessPiece.h"

const BoardVector &ChessPiece::getPosition() const {
    return position;
}

const sf::Texture &ChessPiece::getT1() const {
    return t1;
}

Color ChessPiece::getColor() const {
    return color;
}

ChessPiece::ChessPiece(BoardVector position) {
    this->position = position;
}

void ChessPiece::move(BoardVector) {

}

std::vector<BoardVector> ChessPiece::possibleMoves() {
    return std::vector<BoardVector>();
}

const sf::Sprite &ChessPiece::getSPiece() const {
    return sPiece;
}