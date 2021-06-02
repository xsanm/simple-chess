//
// Created by xsan on 28.05.2021.
//

#ifndef SIMPLE_CHESS_BOARDVECTOR_H
#define SIMPLE_CHESS_BOARDVECTOR_H


class BoardVector {
private:
    int x;
    int y;

public:
    int getX() const;

    int getY() const;

    BoardVector(int x, int y);

    BoardVector(char x, int y);

    bool isOnBoardd();

    BoardVector();

    friend bool operator==(const BoardVector &a, const BoardVector &b);

    std::string toString() const;
};


#endif //SIMPLE_CHESS_BOARDVECTOR_H
