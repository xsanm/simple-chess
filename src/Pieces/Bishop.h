//
// Created by xsan on 28.05.2021.
//

#ifndef SIMPLE_CHESS_BISHOP_H
#define SIMPLE_CHESS_BISHOP_H


#include "../ChessPiece.h"

class Bishop : public ChessPiece {
public:
    bool isPossibleToMove() override;
    Bishop(BoardVector position, Color color, std::string textureUrl);


};


#endif //SIMPLE_CHESS_BISHOP_H
