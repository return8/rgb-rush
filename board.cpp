#include "board.h"

Board::Board(sf::Color c, bool x,bool y,bool z){
    r=x;
    g=y;
    b=z;
    done=false;
    element.setSize(sf::Vector2f(32,32));
    element.setFillColor(c);
};

void Board::setPos(int x){
    element.setPosition(x,0);
    };

bool Board::update(bool x,bool y,bool z){
    if (x==r&&y==g&&z==b){
        done=true;
        return true;
    }else return false;
};

void Board::drawTo(sf::RenderWindow &window){
    window.draw(element);
};

