//
// Created by xsan on 28.05.2021.
//

#ifndef SIMPLE_CHESS_BOARD_H
#define SIMPLE_CHESS_BOARD_H

#include <SFML/Graphics.hpp>
#include "ChessPiece.h"
#include "Data.h"

class Board {
private:
    sf::Texture boardTexture;
    sf::Texture darkSquare;
    sf::Texture lightSquare;
    std::vector<sf::Sprite> boardTextures;
    sf::Sprite sBoard;
    std::vector<ChessPiece *> pieces;
public:
    const std::vector<sf::Sprite> &getBoardTextures() const;

    const std::vector<ChessPiece *> &getPieces() const;

    const sf::Sprite &getSBoard() const;

    Board();

    void generatePieces();

    void generateBoard();
};


#endif //SIMPLE_CHESS_BOARD_H
