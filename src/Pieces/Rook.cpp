//
// Created by xsan on 28.05.2021.
//

#include "Rook.h"

Rook::Rook(BoardVector position, Color color, std::string textureUrl) : ChessPiece(position, color, textureUrl) {

}

bool Rook::isPossibleToMove() {
    return false;
}

int checkSquare(const std::vector<ChessPiece *> &pieces, BoardVector possibility, Color color) { //0 no, 1 free, 2 beat

    for (int j = 0; j < pieces.size(); j++) {
        if (pieces[j]->getPosition() == possibility) {
            if (pieces[j]->getColor() == color) return 0;
            else return 2;
        }
    }
    return 1;
}

std::vector<BoardVector> Rook::possibleMoves(const std::vector<ChessPiece *> &pieces) {
    std::vector<BoardVector> result;
    result.push_back(this->position);
    int y = position.getY();
    int x = position.getX();


    for (int i = x + 1; i <= 8; i++) {
        BoardVector possibility = BoardVector(i, y);
        int action = checkSquare(pieces, possibility, color);

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
        int action = checkSquare(pieces, possibility, color);

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
        int action = checkSquare(pieces, possibility, color);

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
        int action = checkSquare(pieces, possibility, color);

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
