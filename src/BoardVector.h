//
// Created by xsan on 28.05.2021.
//

#ifndef SIMPLE_CHESS_BOARDVECTOR_H
#define SIMPLE_CHESS_BOARDVECTOR_H


class BoardVector {
private:
    int x;
public:
    int getX() const;

    int getY() const;

private:
    int y;
public:
    BoardVector(int x, int y);
    BoardVector(char x, int y);

    BoardVector();
};


#endif //SIMPLE_CHESS_BOARDVECTOR_H
