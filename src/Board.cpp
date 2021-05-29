//
// Created by xsan on 28.05.2021.
//

#include "Board.h"
#include "Pieces/Pawn.h"
#include <SFML/Graphics.hpp>

Board::Board() {

    darkSquare.loadFromFile("images/square brown dark_png_128px.png");
    lightSquare.loadFromFile("images/square brown light_png_128px.png");

    int size = 64;

    bool isDark = false;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            sf::Sprite sp;
            if (isDark) {
                sp = sf::Sprite(darkSquare);
            } else {
                sp = sf::Sprite(lightSquare);
            }
            sp.setScale(sf::Vector2f(0.5, 0.5));
            sp.setPosition(size * i, size * j);
            isDark = !isDark;
            this->boardTextures.push_back(sp);
        }
        isDark = !isDark;
    }


    this->boardTexture.loadFromFile("images/board.png");
    sBoard = sf::Sprite(this->boardTexture);

    for (char c = 'a'; c <= 'h'; c++) {
        Pawn *pawn = new Pawn(BoardVector(c, 2), white);
        this->pieces.push_back(pawn);
    }
}

const sf::Sprite &Board::getSBoard() const {
    return sBoard;
}

void Board::generatePieces() {

}

const std::vector<ChessPiece *> &Board::getPieces() const {
    return pieces;
}

const std::vector<sf::Sprite> &Board::getBoardTextures() const {
    return boardTextures;
}
