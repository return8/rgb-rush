#include "led.h"

Led::Led(sf::Color c){
    led.setSize(sf::Vector2f(20,20));
    led.setOutlineThickness(6);
    led.setPosition(998,358);
    led.setFillColor(c);
    color = c;
    status=false;

};
void Led::on(){
    led.setOutlineColor(color);
    status=true;
};

void Led::off(){
    led.setOutlineColor(sf::Color::White);
    status=false;
};



void Led::drawTo(sf::RenderWindow &window){
    window.draw(led);
};
