//
// Created by xsan on 28.05.2021.
//

#include <iostream>
#include "GameEngine.h"
#include "Board.h"
#include <SFML/Graphics.hpp>
#include "Data.h"
#include <unistd.h>
#include "Connector.h"

using namespace sf;
using namespace std;

void GameEngine::start() {
    Board board = Board();
    board.generateBoard();
    board.generatePieces();

    vector<BoardVector> availablePositions;
    bool isWhite = true;
    Texture t;
    t.loadFromFile("images/backgorund.png");
    Sprite s = Sprite(t);
    s.setScale(Vector2f(0.987, 0.987));

    vector<ChessPiece *> &pieces = board.getPieces();


    float dx = 0, dy = 0;
    bool isMove = false;
    int size = 64;
    Vector2f oldPos, newPos;
    ChessPiece *toMove = nullptr;

    cout << "Game Starting" << endl;
    RenderWindow window(VideoMode(560, 560), "Simple chess");

    //while game
    while (window.isOpen()) {
        //engine move
        if (!isWhite) {
            string next = Connector::getNextMove(board.getGamePosition());
            if (next.length() != 4) {
                cout << "END" << endl;
                sleep(1000);
            }
            //cout << "Next best " << next << endl;
            BoardVector from = BoardVector(int(next[0] - 'a' + 1), next[1] - '0');
            BoardVector to = BoardVector(int(next[2] - 'a' + 1), next[3] - '0');
            //cout << "From -> to " << from.toString() << " " << to.toString() << endl;

            for (int i = 0; i < pieces.size(); i++) {
                if (pieces[i]->getPosition() == from) {
                    ChessPiece *tmpPiece = pieces[i];

                    newPos = Vector2f(SquareSize * (to.getX() - 1) + SquareOffset + 3,
                                      SquareSize * (8 - to.getY()) + SquareOffset);
                    board.makeMove(tmpPiece, to);
                    tmpPiece->getSPiece().setPosition(newPos);
                    isWhite = !isWhite;
                }
            }
        }

        Vector2i pos = Mouse::getPosition(window);
        Event e;
        while (window.pollEvent(e)) {
            if (e.type == Event::Closed)
                window.close();

            //drag piece
            if (e.type == Event::MouseButtonPressed)
                if (e.key.code == Mouse::Left) {

                    for (int i = 0; i < pieces.size(); i++) {
                        Sprite f = pieces[i]->getSPiece();
                        if (f.getGlobalBounds().contains(pos.x, pos.y)) {
                            if (isWhite && pieces[i]->getColor() != white ||
                                !isWhite && pieces[i]->getColor() != black) {
                                isMove = false;
                                continue;
                            }
                            isMove = true;
                            toMove = pieces[i];
                            dx = pos.x - f.getPosition().x;
                            dy = pos.y - f.getPosition().y;
                            oldPos = f.getPosition();
                            availablePositions = pieces[i]->possibleMoves(pieces);
                            board.generateBoard(availablePositions);
                        }
                    }
                }
            //drop piece
            if (e.type == Event::MouseButtonReleased) {
                if (e.key.code == Mouse::Left) {
                    Vector2f p = toMove->getSPiece().getPosition() + Vector2f(SquareSize / 2, SquareSize / 2);
                    newPos = Vector2f(SquareSize * int(p.x / SquareSize) + SquareOffset + 3,
                                      SquareSize * int(p.y / SquareSize) + SquareOffset);

                    BoardVector newPosition = BoardVector((int) ((newPos.x - 11) / size + 1),
                                                          8 - (newPos.y - SquareOffset) / size);

                    if (!isMove) continue;
                    bool isPossible = false;
                    for (int i = 0; i < availablePositions.size(); i++) {
                        if (availablePositions[i] == newPosition) {
                            isPossible = true;
                        }
                    }
                    if (!isPossible) {
                        isMove = false;
                        toMove->getSPiece().setPosition(oldPos);
                        continue;
                    }

                    if (board.makeMove(toMove, newPosition)) {
                        toMove->getSPiece().setPosition(newPos);
                        isWhite = !isWhite;
                        //pieces = board.getPieces();
                        cout << Connector::getNextMove(board.getGamePosition()) << endl;
                    } else {
                        toMove->getSPiece().setPosition(oldPos);
                    }

                    board.generateBoard();
                    isMove = false;
                }
            }
        }

        if (isMove)
            toMove->getSPiece().setPosition(pos.x - dx, pos.y - dy);

        //draw graphics
        window.clear();
        window.draw(s);
        const vector<Sprite> &boardSquares = board.getBoardTextures();
        for (int i = 0; i < boardSquares.size(); i++) {
            window.draw(boardSquares[i]);
        }
        for (int i = 0; i < pieces.size(); i++) {
            window.draw(pieces[i]->getSPiece());
        }
        window.display();
    }
}

