//
// Created by xsan on 28.05.2021.
//

#ifndef SIMPLE_CHESS_QUEEN_H
#define SIMPLE_CHESS_QUEEN_H


#include "../ChessPiece.h"

class Queen : public ChessPiece {
public:
    bool isPossibleToMove() override;

    std::vector<BoardVector> possibleMoves(const std::vector<ChessPiece *> &pieces) override;

    Queen(BoardVector position, Color color, std::string textureUrl);

    std::vector<BoardVector> attackingMoves(const std::vector<ChessPiece *> &pieces) override;
};


#endif //SIMPLE_CHESS_QUEEN_H
