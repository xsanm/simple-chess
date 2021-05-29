//
// Created by xsan on 28.05.2021.
//

#ifndef SIMPLE_CHESS_QUEEN_H
#define SIMPLE_CHESS_QUEEN_H


#include "../ChessPiece.h"

class Queen : public ChessPiece {
public:
    bool isPossibleToMove() override;
    Queen(BoardVector position, Color color, std::string textureUrl);
};


#endif //SIMPLE_CHESS_QUEEN_H
