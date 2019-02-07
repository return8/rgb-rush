#ifndef LED_H
#define LED_H
#include <SFML/Graphics.hpp>

class Led{

public:
    Led(sf::Color c);
    void drawTo(sf::RenderWindow &window);
    void on();
    void off();
    sf::Vector2f getPos(){return led.getPosition();}
    bool stat(){return status;};

private:
    sf::RectangleShape led;
    bool status;
    sf::Color color;
};
#endif // LED_H
