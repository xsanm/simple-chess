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
    sf::Texture darkSquarePossible;
    sf::Texture lightSquare;
    sf::Texture lightSquarePossible;
    std::vector<sf::Sprite> boardTextures;
    sf::Sprite sBoard;
    std::vector<ChessPiece *> pieces;
    Color squareColors[9][9];

public:
    const std::vector<sf::Sprite> &getBoardTextures() const;

    const std::vector<ChessPiece *> &getPieces() const;

    const sf::Sprite &getSBoard() const;

    Board();

    void generatePieces();

    void generateBoard();
    void generateBoard(const std::vector<BoardVector>& possible);
    bool isCheck(Color col);

};


#endif //SIMPLE_CHESS_BOARD_H
