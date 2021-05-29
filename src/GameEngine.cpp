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


    Vector2f offset(28,28);

    std::cout << "Game Starting" << std::endl;
    sf::RenderWindow window(sf::VideoMode(512, 512), "Simple chess");

    while (window.isOpen()){
        Vector2i pos = Mouse::getPosition(window) - Vector2i(offset);
        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
                window.close();

            ////move back//////
//            if (e.type == Event::KeyPressed)
//                if (e.key.code == Keyboard::BackSpace)
//                { if (position.length()>6) position.erase(position.length()-6,5); loadPosition();}

            /////drag and drop///////
//            if (e.type == Event::MouseButtonPressed)
//                if (e.key.code == Mouse::Left)
//                    for(int i=0;i<32;i++)
//                        if (f[i].getGlobalBounds().contains(pos.x,pos.y))
//                        {
//                            isMove=true; n=i;
//                            dx=pos.x - f[i].getPosition().x;
//                            dy=pos.y - f[i].getPosition().y;
//                            oldPos  =  f[i].getPosition();
//                        }
//
//            if (e.type == Event::MouseButtonReleased)
//                if (e.key.code == Mouse::Left)
//                {
//                    isMove=false;
//                    Vector2f p = f[n].getPosition() + Vector2f(size/2,size/2);
//                    newPos = Vector2f( size*int(p.x/size), size*int(p.y/size) );
//                    str = toChessNote(oldPos)+toChessNote(newPos);
//                    move(str);
//                    if (oldPos!=newPos) position+=str+" ";
//                    f[n].setPosition(newPos);
//                }
        }

        //comp move
        if (Keyboard::isKeyPressed(Keyboard::Space))
        {
            //str =  getNextMove(position);
//
//            oldPos = toCoord(str[0],str[1]);
//            newPos = toCoord(str[2],str[3]);
//
//            for(int i=0;i<32;i++) if (f[i].getPosition()==oldPos) n=i;
//
//            /////animation///////
//            for(int k=0;k<50;k++)
//            {
//                Vector2f p = newPos - oldPos;
//                f[n].move(p.x/50, p.y/50);
//                window.draw(sBoard);
//                for(int i=0;i<32;i++) f[i].move(offset);
//                for(int i=0;i<32;i++) window.draw(f[i]); window.draw(f[n]);
//                for(int i=0;i<32;i++) f[i].move(-offset);
//                window.display();
//            }
//
//            move(str);  position+=str+" ";
//            f[n].setPosition(newPos);
        }

        //if (isMove) f[n].setPosition(pos.x-dx,pos.y-dy);

        ////// draw  ///////
        window.clear();

        const vector<Sprite>& boardSquares = board.getBoardTextures();
        for(int i = 0; i < boardSquares.size(); i++) {
            window.draw(boardSquares[i]);
        }
        //window.draw(board.getSBoard());
        const std::vector<ChessPiece *>& pieces = board.getPieces();

        for(int i = 0; i < pieces.size(); i++) {
            window.draw(pieces[i]->getSPiece());
        }
        //for(int i=0;i<32;i++) f[i].move(offset);
        //for(int i=0;i<32;i++) window.draw(f[i]); window.draw(f[n]);
        //for(int i=0;i<32;i++) f[i].move(-offset);
        window.display();
    }
}
