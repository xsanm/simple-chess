//
// Created by xsan on 28.05.2021.
//

#ifndef SIMPLE_CHESS_ROOK_H
#define SIMPLE_CHESS_ROOK_H


#include "../ChessPiece.h"

class Rook : public ChessPiece {
public:
    bool isPossibleToMove() override;

    std::vector<BoardVector> possibleMoves(const std::vector<ChessPiece *> &pieces) override;

    Rook(BoardVector position, Color color, std::string textureUrl);
};


#endif //SIMPLE_CHESS_ROOK_H
