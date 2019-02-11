#include "player.h"

void Player::move_up(){
    player.move({0, -movespeed});
};

void Player::move_down(){
    player.move({0, movespeed});
};

void Player::move_left(){
    player.move({-movespeed, 0});
};

void Player::move_right(){
    player.move({movespeed, 0});
};

Player::Player(int x,int y){
    player.setSize(sf::Vector2f(30,30));
    player.setPosition(x,y);
};

void Player::drawTo(sf::RenderWindow &window){
    window.draw(player);
};

void Player::setPos(sf::Vector2f newPos){
    player.setPosition(newPos);
};




bool Player::collision(const int* tiles){

sf::Vector2u tileSize(32,32);
unsigned int width = 32;
unsigned int height= 16;

 for (unsigned int i = 0; i < width; ++i){
    for (unsigned int j = 0; j < height; ++j){
        int tileNumber = tiles[i + j * width];
        if (tileNumber!=0){
            int bottom = j*tileSize.y+tileSize.y;
            int top = j*tileSize.y;
            int left = i*tileSize.x;
            int right = i*tileSize.x + tileSize.x;
            if(this->right()>left && this->left()<right && this->top()<bottom && this->bottom()>top )
                return true;
        }
    };
 };
 return false;
};
