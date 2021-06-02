//
// Created by xsan on 28.05.2021.
//

#include "Rook.h"

Rook::Rook(BoardVector position, Color color, std::string textureUrl) : ChessPiece(position, color, textureUrl) {

}

bool Rook::isPossibleToMove() {
    return false;
}

std::vector<BoardVector> Rook::possibleMoves(const std::vector<ChessPiece *> &pieces) {
    std::vector<BoardVector> result = Rook::attackingMoves(pieces);
    result.push_back(this->position);
    return result;
}

std::vector<BoardVector> Rook::attackingMoves(const std::vector<ChessPiece *> &pieces) {
    std::vector<BoardVector> result;

    int y = position.getY();
    int x = position.getX();

    for (int i = x + 1; i <= 8; i++) {
        BoardVector possibility = BoardVector(i, y);
        int action = ChessPiece::checkSquare(pieces, possibility, color);

        if (action == 0)
            break;
        else if (action == 1)
            result.push_back(possibility);
        else {
            result.push_back(possibility);
            break;
        }
    }

    for (int i = x - 1; i >= 1; i--) {
        BoardVector possibility = BoardVector(i, y);
        int action = ChessPiece::checkSquare(pieces, possibility, color);

        if (action == 0)
            break;
        else if (action == 1)
            result.push_back(possibility);
        else {
            result.push_back(possibility);
            break;
        }
    }

    for (int i = y + 1; i <= 8; i++) {
        BoardVector possibility = BoardVector(x, i);
        int action = ChessPiece::checkSquare(pieces, possibility, color);

        if (action == 0)
            break;
        else if (action == 1)
            result.push_back(possibility);
        else {
            result.push_back(possibility);
            break;
        }
    }

    for (int i = y - 1; i >= 1; i--) {
        BoardVector possibility = BoardVector(x, i);
        int action = ChessPiece::checkSquare(pieces, possibility, color);

        if (action == 0)
            break;
        else if (action == 1)
            result.push_back(possibility);
        else {
            result.push_back(possibility);
            break;
        }
    }

    return result;
}
