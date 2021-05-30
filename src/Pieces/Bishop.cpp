//
// Created by xsan on 28.05.2021.
//

#include "Bishop.h"

bool Bishop::isPossibleToMove() {
    return false;
}

Bishop::Bishop(BoardVector position, Color color, std::string textureUrl) : ChessPiece(position, color, textureUrl) {

}



std::vector<BoardVector> Bishop::possibleMoves(const std::vector<ChessPiece *> &pieces) {
    std::vector<BoardVector> result;
    result.push_back(this->position);
    int y = position.getY();
    int x = position.getX();
    for (int i = 1; i <= 8; i++) {
        BoardVector possibility = BoardVector(x + i, y + i);
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
    for (int i = 1; i <= 8; i++) {
        BoardVector possibility = BoardVector(x + i, y - i);
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
    for (int i = 1; i <= 8; i++) {
        BoardVector possibility = BoardVector(x - i, y + i);
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
    for (int i = 1; i <= 8; i++) {
        BoardVector possibility = BoardVector(x - i, y - i);
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
