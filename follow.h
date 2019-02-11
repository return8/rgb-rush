#ifndef FOLLOW_H_INCLUDED
#define FOLLOW_H_INCLUDED
#include"player.h"
#include"led.h"
#include"menu.h"
#include <SFML/Graphics.hpp>

using namespace sf;

bool collision_of_two(Player* player, Player* enemy){
    if ((player->getPos().x < enemy->getPos().x + 30.0) &&
			(player->getPos().x + 30.0 > enemy->getPos().x )&&
			(player->getPos().y < enemy->getPos().y + 30.0) &&
			(30.0 + player->getPos().y > enemy->getPos().y))
			return true;
};



void update(Player* player, Player* enemy, Player *enemy2 ,const int* level){

    if (enemy->getPos().y > player->getPos().y) {
        enemy->move_up();
        if(enemy->collision(level)||collision_of_two(enemy,enemy2)) {
                enemy->move_down();
        }
    }else{
        enemy->move_down();
        if(enemy->collision(level)||collision_of_two(enemy,enemy2)) {
                enemy->move_up();
        }
    }

    if (enemy->getPos().x > player->getPos().x) {
        enemy->move_left();
        if(enemy->collision(level)||collision_of_two(enemy,enemy2)) {
                enemy->move_right();
        }
    }else{
        enemy->move_right();
        if(enemy->collision(level)||collision_of_two(enemy,enemy2)) {
                enemy->move_left();
        }
    }
}



int level_select(const int *level_1,const int *level_2,const int *level_3,const int** level, int i,Player *player){
        switch(i){
                case 0:
                    *level = level_1;
                    if (player->getPos().y > 480){
                        player->setPos(sf::Vector2f(512,32));
                        i++;
                    }
                    break;
                case 1:
                    *level = level_2;
                    if (player->getPos().y > 480){
                        player->setPos(sf::Vector2f(512,32));
                        i++;
                    }else if(player->getPos().y < 32){
                        player->setPos(sf::Vector2f(512,480));
                        i--;
                    }
                    break;
                case 2:
                    *level = level_3;
                    if (player->getPos().y < 32){
                        player->setPos(sf::Vector2f(512,480));
                        i--;
                    }
                    break;
            }
            return i;
};



int manage_menu(sf::RenderWindow &window, int level_reached){
    bool ignore_key=false;
    Menu menu(window.getSize().x, window.getSize().y,level_reached);
    while(window.isOpen()||ignore_key){
        sf::Event event;
        ignore_key=false;
        while(window.pollEvent(event)){

            switch(event.type){

            case sf::Event::KeyReleased:
                if(event.key.code==sf::Keyboard::Up){
                    menu.MoveUp();
                    break;
                }
                else if(event.key.code==sf::Keyboard::Down){
                    menu.MoveDown();
                    break;
                }
                else if(event.key.code==sf::Keyboard::Return){
                    window.close();
                    break;
                }
                else ignore_key=true;

            case sf::Event::Closed:
                if (!ignore_key) {window.close();}
				break;
            }
        }
        window.clear();
        menu.draw(window);
        window.display();

    }
    return menu.GetPressedItem();
};


#endif // FOLLOW_H_INCLUDED
