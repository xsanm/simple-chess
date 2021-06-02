//
// Created by xsan on 28.05.2021.
//

#include "Knight.h"

bool Knight::isPossibleToMove() {
    return false;
}

Knight::Knight(BoardVector position, Color color, std::string textureUrl) : ChessPiece(position, color, textureUrl) {

}

std::vector<BoardVector> Knight::possibleMoves(const std::vector<ChessPiece *> &pieces) {
    std::vector<BoardVector> result = Knight::attackingMoves(pieces);
    result.push_back(this->position);
    return result;
}

std::vector<BoardVector> Knight::attackingMoves(const std::vector<ChessPiece *> &pieces) {
    std::vector<BoardVector> result;

    int y = position.getY();
    int x = position.getX();
    std::vector<BoardVector> possibilities;
    possibilities.push_back(BoardVector(x + 1, y + 2));
    possibilities.push_back(BoardVector(x + 1, y - 2));
    possibilities.push_back(BoardVector(x - 1, y + 2));
    possibilities.push_back(BoardVector(x - 1, y - 2));
    possibilities.push_back(BoardVector(x + 2, y + 1));
    possibilities.push_back(BoardVector(x + 2, y - 1));
    possibilities.push_back(BoardVector(x - 2, y + 1));
    possibilities.push_back(BoardVector(x - 2, y - 1));

    for (int i = 0; i < possibilities.size(); i++)
        if (possibilities[i].isOnBoardd()) {
            bool canMove = true;
            for (int j = 0; j < pieces.size(); j++) {
                if (pieces[j]->getPosition() == possibilities[i]) {
                    if (pieces[j]->getColor() == color) canMove = false;
                }
            }
            if (canMove) {
                result.push_back(possibilities[i]);
            }
        }

    return result;
}
