//
// Created by xsan on 28.05.2021.
//

#include "Rook.h"

Rook::Rook(BoardVector position, Color color, std::string textureUrl) : ChessPiece(position, color, textureUrl) {

}

bool Rook::isPossibleToMove() {
    return false;
}
