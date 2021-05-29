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

sf::Sprite &ChessPiece::getSPiece() {
    return sPiece;
}

void ChessPiece::setSPiece(const sf::Sprite &sPiece) {
    ChessPiece::sPiece = sPiece;
}

ChessPiece::ChessPiece(BoardVector position, Color color, std::string textureURL) {
    this->color = color;
    this->t1.loadFromFile(textureURL);
    sPiece = sf::Sprite(this->t1);
    sPiece.setScale(sf::Vector2f(0.4, 0.4));
    sPiece.setPosition(SquareSize * (position.getX() - 1) + SquareOffset + 3, SquareSize * (8 - position.getY()) + SquareOffset);
}

