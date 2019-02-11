#ifndef PLAYER_H
#define PLAYER_H


#include <SFML/Graphics.hpp>

class Player {

public:

    Player(int x,int y);
    void drawTo(sf::RenderWindow &window);
    void setPos(sf::Vector2f newPos);
    void setCol(sf::Color x){player.setFillColor(x);};
    sf::Vector2f getPos(){return player.getPosition();}
    void set_move_speed(float x){movespeed = x;};
    bool collision(const int* tiles);


    float left(){return player.getPosition().x;};
    float right(){return player.getPosition().x + 30;};
    float top(){return player.getPosition().y;};
    float bottom(){return player.getPosition().y+ 30;};

    void move_up();
    void move_down();
    void move_left();
    void move_right();

private:
    sf::RectangleShape player;
    float movespeed;
};

#endif // PLAYER_H
