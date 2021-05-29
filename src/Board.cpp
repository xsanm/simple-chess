//
// Created by xsan on 28.05.2021.
//

#include "Board.h"
#include "Pieces/Pawn.h"
#include <SFML/Graphics.hpp>
#include "Data.h"
#include "Pieces/Rook.h"
#include "Pieces/Bishop.h"
#include "Pieces/Knight.h"
#include "Pieces/King.h"
#include "Pieces/Queen.h"

Board::Board() {

    darkSquare.loadFromFile("images/square brown dark_png_128px.png");
    lightSquare.loadFromFile("images/square brown light_png_128px.png");

    int size = 64;




    this->boardTexture.loadFromFile("images/board.png");
    sBoard = sf::Sprite(this->boardTexture);


}

const sf::Sprite &Board::getSBoard() const {
    return sBoard;
}

void Board::generatePieces() {
    for (char c = 'a'; c <= 'h'; c++) {
        Pawn *pawnWhite = new Pawn(BoardVector(c, 2), white,
                                   std::string("images/w_pawn_png_128px.png"));
        this->pieces.push_back(pawnWhite);

        Pawn *pawnBlack = new Pawn(BoardVector(c, 7), black,
                                   std::string("images/b_pawn_png_128px.png"));
        this->pieces.push_back(pawnBlack);
    }

    Rook *r1 = new Rook(BoardVector('a', 1), white, std::string("images/w_rook_png_128px.png"));
    Rook *r2 = new Rook(BoardVector('h', 1), white, std::string("images/w_rook_png_128px.png"));
    Rook *r3 = new Rook(BoardVector('a', 8), black, std::string("images/b_rook_png_128px.png"));
    Rook *r4 = new Rook(BoardVector('h', 8), black, std::string("images/b_rook_png_128px.png"));
    pieces.push_back(r1);
    pieces.push_back(r2);
    pieces.push_back(r3);
    pieces.push_back(r4);

    Bishop *b1 = new Bishop(BoardVector('c', 1), white, std::string("images/w_bishop_png_128px.png"));
    Bishop *b2 = new Bishop(BoardVector('f', 1), white, std::string("images/w_bishop_png_128px.png"));
    Bishop *b3 = new Bishop(BoardVector('c', 8), black, std::string("images/b_bishop_png_128px.png"));
    Bishop *b4 = new Bishop(BoardVector('f', 8), black, std::string("images/b_bishop_png_128px.png"));
    pieces.push_back(b1);
    pieces.push_back(b2);
    pieces.push_back(b3);
    pieces.push_back(b4);

    Knight *k1 = new Knight(BoardVector('b', 1), white, std::string("images/w_knight_png_128px.png"));
    Knight *k2 = new Knight(BoardVector('g', 1), white, std::string("images/w_knight_png_128px.png"));
    Knight *k3 = new Knight(BoardVector('b', 8), black, std::string("images/b_knight_png_128px.png"));
    Knight *k4 = new Knight(BoardVector('g', 8), black, std::string("images/b_knight_png_128px.png"));
    pieces.push_back(k1);
    pieces.push_back(k2);
    pieces.push_back(k3);
    pieces.push_back(k4);

    King *king1 = new King(BoardVector('e', 1), white, std::string("images/w_king_png_128px.png"));
    King *king2 = new King(BoardVector('e', 8), black, std::string("images/b_king_png_128px.png"));
    pieces.push_back(king1);
    pieces.push_back(king2);

    Queen *queen1 = new Queen(BoardVector('d', 1), white, std::string("images/w_queen_png_128px.png"));
    Queen *queen2 = new Queen(BoardVector('d', 8), black, std::string("images/b_queen_png_128px.png"));
    pieces.push_back(queen1);
    pieces.push_back(queen2);
}

const std::vector<ChessPiece *> &Board::getPieces() const {
    return pieces;
}

const std::vector<sf::Sprite> &Board::getBoardTextures() const {
    return boardTextures;
}

void Board::generateBoard() {
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
            sp.setPosition(SquareSize * i, SquareSize * j);
            isDark = !isDark;
            this->boardTextures.push_back(sp);
        }
        isDark = !isDark;
    }
}
