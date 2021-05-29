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
                    const std::vector<ChessPiece *> &pieces = board.getPieces();
                    for (int i = 0; i < pieces.size(); i++) {
                        Sprite f = pieces[i]->getSPiece();
                        if (f.getGlobalBounds().contains(pos.x, pos.y)) {
                            isMove = true;
                            toMove = pieces[i];
                            dx = pos.x - f.getPosition().x;
                            dy = pos.y - f.getPosition().y;
                            oldPos = f.getPosition();
                        }
                    }
                }

            if (e.type == Event::MouseButtonReleased) {
                if (e.key.code == Mouse::Left) {
                    isMove = false;
                    Vector2f p = toMove->getSPiece().getPosition() + Vector2f(size / 2, size / 2);
                    newPos = Vector2f(size * int(p.x / size) + 11, size * int(p.y / size) + 8);

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
        const std::vector<ChessPiece *> &pieces = board.getPieces();
        //std::cout << pieces.size() << std::endl;
        for (int i = 0; i < pieces.size(); i++) {
            window.draw(pieces[i]->getSPiece());
        }

        window.display();
    }
}

