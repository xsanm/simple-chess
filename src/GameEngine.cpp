//
// Created by xsan on 28.05.2021.
//

#include <iostream>
#include "GameEngine.h"
#include "Board.h"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

void GameEngine::start() {

    Board board = Board();
    board.generateBoard();
    board.generatePieces();
    vector<BoardVector> availablePositions;

    const std::vector<ChessPiece *> &pieces = board.getPieces();
//    for(int i = 0; i < pieces.size(); i++) {
//        std::cout << pieces[i]->getPosition().getX() << " " << pieces[i]->getPosition().getY() << '\n';
//    }


    Vector2f offset(0, 0);
    float dx = 0, dy = 0;
    bool isMove = false;
    int size = 64;
    Vector2f oldPos, newPos;
    ChessPiece *toMove;

    std::cout << "Game Starting" << std::endl;
    sf::RenderWindow window(sf::VideoMode(512, 512), "Simple chess");

    while (window.isOpen()) {
        Vector2i pos = Mouse::getPosition(window) - Vector2i(offset);
        Event e;
        while (window.pollEvent(e)) {
            if (e.type == Event::Closed)
                window.close();



            //drag and drop
            if (e.type == Event::MouseButtonPressed)
                if (e.key.code == Mouse::Left) {
//                    vector<BoardVector> vec;
//                    vec.push_back(BoardVector(1, 1));
//                    vec.push_back(BoardVector(2, 1));
//                    vec.push_back(BoardVector(4, 4));
                    //board.generateBoard(vec);

                    for (int i = 0; i < pieces.size(); i++) {
                        Sprite f = pieces[i]->getSPiece();
                        if (f.getGlobalBounds().contains(pos.x, pos.y)) {
                            isMove = true;
                            toMove = pieces[i];
                            dx = pos.x - f.getPosition().x;
                            dy = pos.y - f.getPosition().y;
                            oldPos = f.getPosition();
                            availablePositions = pieces[i]->possibleMoves(pieces);
                            //std::cout << vec[0].getX() << " " << vec[0].getY() << '\n';


                            board.generateBoard(availablePositions);
                        }
                    }
                    // const vector<Sprite> &boardSquares = board.getBoardTextures();
                    //std::cout << boardSquares[18].getScale().x;
//                    for (int i = 0; i < boardSquares.size(); i++) {
//                        window.draw(boardSquares[i]);
//                    }
//                    window.display();

                }

            if (e.type == Event::MouseButtonReleased) {
                if (e.key.code == Mouse::Left) {
                    Vector2f p = toMove->getSPiece().getPosition() + Vector2f(SquareSize / 2, SquareSize / 2);
                    newPos = Vector2f(SquareSize * int(p.x / SquareSize) + SquareOffset + 3, SquareSize * int(p.y / SquareSize) + SquareOffset);

                    BoardVector newPosition = BoardVector((int)((newPos.x - 11) / size + 1), 8 - (newPos.y - SquareOffset) / size);
                    //std::cout << (newPos.x - 11) / size << '\n';
                    //toMove->move(newPosition);
                    bool isPossible = false;
                    for(int i = 0; i < availablePositions.size(); i++) {
                        if(availablePositions[i] == newPosition) {
                            isPossible = true;
                        }
                    }
                    if(!isPossible) {
                        isMove = false;
                        toMove->getSPiece().setPosition(oldPos);
                        continue;
                    }
                    toMove->move(newPosition);
                    if (isMove) {
                        board.generateBoard();
                    }
                    isMove = false;


                    toMove->getSPiece().setPosition(newPos);
                }
            }

        }


        if (Keyboard::isKeyPressed(Keyboard::Space)) {

        }


        if (isMove)
            toMove->getSPiece().setPosition(pos.x - dx, pos.y - dy);

        window.clear();

        const vector<Sprite> &boardSquares = board.getBoardTextures();
        for (int i = 0; i < boardSquares.size(); i++) {
            window.draw(boardSquares[i]);
        }
        //window.draw(board.getSBoard());
        //std::cout << pieces.size() << std::endl;
        for (int i = 0; i < pieces.size(); i++) {
            window.draw(pieces[i]->getSPiece());
        }

        window.display();
    }
}

