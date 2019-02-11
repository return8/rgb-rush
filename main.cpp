#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include "player.h"
#include "map.h"
#include "menu.h"
#include "follow.h"
#include "board.h"
#include <iostream>
#include <fstream>
#include "led.h"
#include "image.h"
#include <unistd.h>
using namespace std;

#define PLAYER_SPEED 0.3
#define ENEMY_SPEED 0.15

const int level_1[]={
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,0,1,0,0,0,0,0,1,1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,
1,0,1,1,1,1,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,
1,0,0,1,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,
1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,1,
1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1,0,1,1,1,1,0,0,0,1,
1,0,1,0,0,1,1,1,0,0,1,1,1,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,
1,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,
1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,0,1,0,1,
1,0,1,0,1,0,0,0,1,0,0,1,1,1,0,1,0,0,1,0,1,0,0,0,1,0,1,1,0,1,0,1,
1,0,0,0,1,0,0,1,0,0,0,0,0,1,0,1,0,0,1,0,1,0,1,1,1,0,0,1,0,1,0,1,
1,0,0,0,1,0,0,1,0,1,1,1,0,1,0,1,0,0,1,0,1,0,0,0,0,1,0,1,0,1,0,1,
1,0,1,1,1,1,0,1,0,0,0,1,0,0,0,1,0,0,1,0,1,1,1,1,0,1,0,1,0,1,0,1,
1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1
};

const int level_2[]={
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,1,1,0,1,
1,0,1,1,1,1,0,1,1,1,1,1,0,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,1,
1,0,0,1,0,0,0,1,0,0,0,1,0,1,0,1,1,1,1,0,1,0,0,0,0,0,0,1,0,1,0,1,
1,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,1,
1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,1,1,1,1,0,1,0,1,1,1,1,0,0,0,1,
1,0,1,0,0,1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,
1,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,
1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,1,
1,0,1,0,1,0,0,0,1,0,0,1,1,1,0,1,0,0,0,0,1,0,0,0,1,0,1,1,0,1,0,1,
1,0,0,0,1,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,1,0,1,1,1,0,0,1,0,1,0,1,
1,0,0,0,1,0,0,1,0,1,1,1,0,1,0,1,0,0,1,0,1,0,0,0,0,1,0,1,0,1,0,1,
1,0,1,1,1,1,0,1,0,0,0,1,0,0,0,1,0,0,1,0,1,1,1,1,0,1,0,1,0,1,0,1,
1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1
};
const int level_3[]={
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,1,1,0,1,
1,0,1,1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,1,
1,0,0,1,0,0,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,0,0,0,0,1,0,1,0,1,
1,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,1,0,1,0,1,0,0,1,0,0,0,1,
1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,1,1,1,1,0,1,0,1,1,1,1,0,0,0,1,
1,0,1,0,0,1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,
1,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,
1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,1,
1,0,1,0,1,0,0,0,1,0,0,1,1,1,0,1,0,0,0,0,1,0,0,0,1,0,1,1,0,1,0,1,
1,0,0,0,1,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,1,0,1,1,1,0,0,1,0,1,0,1,
1,0,0,0,1,0,0,1,0,1,1,1,0,1,0,1,0,0,1,0,1,0,0,0,0,1,0,1,0,1,0,1,
1,0,1,1,1,1,0,1,0,0,0,1,0,0,0,1,0,0,1,0,1,1,1,1,0,1,0,1,0,1,0,1,
1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
};

int main()
{
    bool RESTART=false;

    do{
        RESTART=false;

        // Create the main window
        sf::RenderWindow app(sf::VideoMode(1024, 512), "SFML window");
        bool IN=0;
        int k[3]={0,0,0};

        //Create enemies and player;
        Player enemy[6]={{128,64},{512,128},{692,64},{128,64},{128,64},{960,430}};
        Player player(32,64);
        player.setCol(sf::Color::White);
        player.set_move_speed(PLAYER_SPEED);
        for(int x=0; x<6; x++){
            enemy[x].setCol(sf::Color::Magenta);
            enemy[x].set_move_speed(ENEMY_SPEED);
        };

        //Create 3 main led;
        Led led[3]={{sf::Color::Red},{sf::Color::Blue},{sf::Color::Green}};

        //Create a board of color targets;
        Board board[7]={{sf::Color::Red,1,0,0},{sf::Color::Blue,0,0,1},
        {sf::Color::Magenta,1,0,1},{sf::Color::Green,0,1,0},{sf::Color::Yellow,1,1,0},
        {sf::Color::Cyan,0,1,1},{sf::Color::White,1,1,1}};
        for(int x=0;x<7; x++)board[x].setPos(32*x+384); //full board on top of the screen;

        //create maps based on levels.
        TileMap map[3];
        if (!map[0].load("tileset.png", sf::Vector2u(32, 32), level_1, 32, 16)) return -1;
        if (!map[1].load("tileset.png", sf::Vector2u(32, 32), level_2, 32, 16)) return -1;
        if (!map[2].load("tileset.png", sf::Vector2u(32, 32), level_3, 32, 16)) return -1;
        const int* level;

        int i=0; // i shows the current map (1,2,3);
        int epipedo=0;
        // Start the game loop
        while (app.isOpen())
        {
            //select map based on players position.
            i=level_select(level_1,level_2,level_3,&level,i,&player);

            sf::Event event;

            while (app.pollEvent(event)){
                if (event.type == sf::Event::Closed)
                    app.close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                player.move_up();
                if(player.collision(level)) player.move_down();
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                player.move_down();
                if(player.collision(level)) player.move_up();
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                player.move_left();
                if(player.collision(level)) player.move_right();
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                player.move_right();
                if(player.collision(level)) player.move_left();
            }

            update (&player, &enemy[2*i+1], &enemy[2*i], level);
            update (&player, &enemy[2*i], &enemy[2*i+1], level);

            if (player.getPos().x > 959){
                if( (352 < player.getPos().y && player.getPos().y <384)&&(!IN) ){
                    IN = 1;
                    k[i]++;
                    if (k[i]%2==1){
                        led[i].on();
                    }else{
                        led[i].off();
                    }
                }
            }else IN=0;

            if(board[epipedo].update(led[0].stat(),led[2].stat(),led[1].stat())) epipedo++;


            // Clear screen
            app.clear();

            app.draw(map[i]);
            for(int j=0; j<=epipedo; j++){
                //draw all board states reached by now.
                board[j].drawTo(app);
            }
            enemy[2*i+1].drawTo(app);
            enemy[2*i].drawTo(app);
            player.drawTo(app);
            led[i].drawTo(app);
            // Update the window
            app.display();


            //check when game ends;
            bool END1=collision_of_two(&player,&enemy[2*i]);
            bool END2=collision_of_two(&player,&enemy[2*i+1]);
            bool END3=(epipedo==7);
            if (END1||END2||END3){
                switch(manage_menu(app,epipedo)){
                case 0: RESTART=true;
                case 1: app.close();
                case 2: app.close();
                }
            };

        }

    }while(RESTART);

    return EXIT_SUCCESS;
};
