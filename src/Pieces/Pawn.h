//
// Created by xsan on 28.05.2021.
//

#ifndef SIMPLE_CHESS_PAWN_H
#define SIMPLE_CHESS_PAWN_H

#include "../Data.h"
#include "../ChessPiece.h"

class Pawn : public ChessPiece{
private:
    bool isFirst;
public:
    Pawn(BoardVector position1, Color color1, std::string textureUrl1);

    bool isPossibleToMove() override;

    void move(BoardVector position) override;

    std::vector<BoardVector> possibleMoves(const std::vector<ChessPiece *> &pieces) override;

    std::vector<BoardVector> attackingMoves(const std::vector<ChessPiece *> &pieces) override;
};


#endif //SIMPLE_CHESS_PAWN_H
