//
// Created by xsan on 28.05.2021.
//

#ifndef SIMPLE_CHESS_KNIGHT_H
#define SIMPLE_CHESS_KNIGHT_H


#include "../ChessPiece.h"

class Knight : public ChessPiece {
public:
    bool isPossibleToMove() override;
    Knight(BoardVector position, Color color, std::string textureUrl);
};


#endif //SIMPLE_CHESS_KNIGHT_H
