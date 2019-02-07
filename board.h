#ifndef BOARD_H
#define BOARD_H
#include <SFML/Graphics.hpp>


class Board{

public:
    Board(sf::Color c, bool x,bool y,bool z);
    void setPos(int x);
    void drawTo(sf::RenderWindow &window);
    bool update(bool x,bool y,bool z);
    bool Done(){return done;};
    void on(){done=true;};

private:
    sf::RectangleShape element;
    bool r,g,b;
    bool done;
    sf::Color color;
};


#endif // BOARD_H
