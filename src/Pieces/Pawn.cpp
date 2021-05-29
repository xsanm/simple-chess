//
// Created by xsan on 28.05.2021.
//

#include "Pawn.h"

bool Pawn::isPossibleToMove() {
    return false;
}

Pawn::Pawn(const BoardVector &position, Color col) : ChessPiece(position) {
    this->color = color;
    if(col == black) {
        this->t1.loadFromFile("images/b_pawn_png_128px.png");
    } else {
        this->t1.loadFromFile("images/w_pawn_png_128px.png");
    }
    int offset = 8;
    int size = 64;
    sPiece = sf::Sprite(this->t1);
    sPiece.setScale(sf::Vector2f(0.4, 0.4));
    sPiece.setPosition(size * (position.getX() - 1) + offset + 3, size * (8 - position.getY()) + offset);
}
