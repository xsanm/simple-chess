//
// Created by xsan on 28.05.2021.
//

#include <iostream>
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

void ChessPiece::move(BoardVector position) {
    this->position = position;
}


sf::Sprite &ChessPiece::getSPiece() {
    return sPiece;
}

void ChessPiece::setSPiece(const sf::Sprite &sPiece) {
    ChessPiece::sPiece = sPiece;
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
    //std::cout << "Hello22 ";
    return std::vector<BoardVector>();
}


