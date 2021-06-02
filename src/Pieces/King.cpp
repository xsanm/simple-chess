//
// Created by xsan on 28.05.2021.
//

#include <iostream>
#include "King.h"

bool King::isPossibleToMove() {
    return false;
}

King::King(BoardVector position, Color color, std::string textureUrl) : ChessPiece(position, color, textureUrl) {
    isFirst = true;
}

std::vector<BoardVector> King::possibleMoves(const std::vector<ChessPiece *> &pieces) {
    std::vector<BoardVector> result = King::attackingMoves(pieces);
    result.push_back(this->position);

    if (isFirst && color == white) {
        BoardVector v1 = BoardVector(6, 1);
        BoardVector v2 = BoardVector(7, 1);
        bool isPossibleRight = true;
        for (int i = 0; i < pieces.size(); i++) {
            if (pieces[i]->getPosition() == v1 || pieces[i]->getPosition() == v2) {
                isPossibleRight = false;
                break;
            }
        }
        if (isPossibleRight) {
            result.push_back(v2);
        }
    }
    if (isFirst && color == white) {
        BoardVector v1 = BoardVector(2, 1);
        BoardVector v2 = BoardVector(3, 1);
        BoardVector v3 = BoardVector(4, 1);
        bool isPossibleLeft = true;
        for (int i = 0; i < pieces.size(); i++) {
            if (pieces[i]->getPosition() == v1 || pieces[i]->getPosition() == v2 || pieces[i]->getPosition() == v3) {
                isPossibleLeft = false;
                break;
            }
        }
        if (isPossibleLeft) {
            result.push_back(v2);
        }
    }
    return result;
}

std::vector<BoardVector> King::attackingMoves(const std::vector<ChessPiece *> &pieces) {
    std::vector<BoardVector> result;

    int y = position.getY();
    int x = position.getX();
    std::vector<BoardVector> possibilties;
    possibilties.push_back(BoardVector(x + 1, y + 1));
    possibilties.push_back(BoardVector(x + 1, y));
    possibilties.push_back(BoardVector(x + 1, y - 1));
    possibilties.push_back(BoardVector(x - 1, y + 1));
    possibilties.push_back(BoardVector(x - 1, y));
    possibilties.push_back(BoardVector(x - 1, y - 1));
    possibilties.push_back(BoardVector(x, y + 1));
    possibilties.push_back(BoardVector(x, y));
    possibilties.push_back(BoardVector(x, y - 1));

    for (int i = 0; i < possibilties.size(); i++)
        if (possibilties[i].isOnBoardd()) {
            bool canMove = true;
            for (int j = 0; j < pieces.size(); j++) {
                if (pieces[j]->getPosition() == possibilties[i]) {
                    if (pieces[j]->getColor() == color) canMove = false;
                }
            }
            for (int j = 0; j < pieces.size(); j++)
                if (pieces[j]->getColor() != color && !pieces[j]->amIKing()) {
                    std::vector<BoardVector> attacking = pieces[j]->attackingMoves(pieces);
                    for (int k = 0; k < attacking.size(); k++) {
                        if (attacking[k] == possibilties[i])
                            canMove = false;
                    }
                }

            if (canMove) {
                result.push_back(possibilties[i]);
            }
        }

    return result;
}

bool King::amIKing() {
    return true;
}

void King::move(BoardVector position) {
    if ((!(position == this->position)) && isFirst) {
        isFirst = false;
    }
    ChessPiece::move(position);
}

