//
// Created by xsan on 28.05.2021.
//

#ifndef SIMPLE_CHESS_CHESSPIECE_H
#define SIMPLE_CHESS_CHESSPIECE_H

#include "Data.h"
#include "BoardVector.h"

class ChessPiece {

private:

protected:
    BoardVector position;
    sf::Texture t1;
    sf::Sprite sPiece;
    Color color;

public:
    void setSPiece(const sf::Sprite &sPiece);

    sf::Sprite &getSPiece();

    const BoardVector &getPosition() const;

    const sf::Texture &getT1() const;

    Color getColor() const;

    explicit ChessPiece(BoardVector position);

    ChessPiece(BoardVector position, Color color, std::string textureURL);

    virtual void move(BoardVector position);

    virtual bool isPossibleToMove() = 0;

    virtual bool amIKing();

    virtual std::vector<BoardVector> possibleMoves(const std::vector<ChessPiece *> &pieces);
    virtual std::vector<BoardVector> attackingMoves(const std::vector<ChessPiece *> &pieces);

    int checkSquare(const std::vector<ChessPiece *> &vector, BoardVector vector1, Color color);
};


#endif //SIMPLE_CHESS_CHESSPIECE_H
