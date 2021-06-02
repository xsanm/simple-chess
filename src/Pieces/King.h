//
// Created by xsan on 28.05.2021.
//

#ifndef SIMPLE_CHESS_KING_H
#define SIMPLE_CHESS_KING_H


#include "../ChessPiece.h"

class King : public ChessPiece {
private:
    bool isFirst;
public:
    bool isPossibleToMove() override;

    King(BoardVector position, Color color, std::string textureUrl);

    std::vector<BoardVector> possibleMoves(const std::vector<ChessPiece *> &pieces) override;

    void move(BoardVector position) override;

    bool amIKing() override;

    std::vector<BoardVector> attackingMoves(const std::vector<ChessPiece *> &pieces) override;
};


#endif //SIMPLE_CHESS_KING_H
