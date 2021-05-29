//
// Created by xsan on 28.05.2021.
//

#ifndef SIMPLE_CHESS_PAWN_H
#define SIMPLE_CHESS_PAWN_H

#include "../Data.h"
#include "../ChessPiece.h"

class Pawn : public ChessPiece{
public:
    Pawn(const BoardVector &position, Color col);

    bool isPossibleToMove() override;

};


#endif //SIMPLE_CHESS_PAWN_H
