//
// Created by xsan on 28.05.2021.
//

#ifndef SIMPLE_CHESS_KING_H
#define SIMPLE_CHESS_KING_H


#include "../ChessPiece.h"

class King : public ChessPiece {
public:
    bool isPossibleToMove() override;
    King(BoardVector position, Color color, std::string textureUrl);
};


#endif //SIMPLE_CHESS_KING_H
