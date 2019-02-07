#include "Menu.h"
#include <string>
#include <sstream>
using namespace std;

Menu::Menu(float width, float height, int level_reached)
{
	if (!font.loadFromFile("ARIALI.ttf"))
	{
		// handle error
	}

	menu[0].setFont(font);
	menu[0].setColor(sf::Color::Red);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setColor(sf::Color::White);
	menu[1].setString("Options");
	menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setColor(sf::Color::White);
	menu[2].setString("Exit");
	menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

    ostringstream os;
    os << "REACHED LEVEL " << level_reached;
    string s = os.str();
	score[0].setFont(font);
	score[0].setColor(sf::Color::Green);
	score[0].setString(s);
	score[0].setPosition(sf::Vector2f(width / 10, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

    score[1].setFont(font);
	score[1].setColor(sf::Color::Green);
	if (level_reached==7) score[1].setString(" Well done!!!");
	else score[1].setString("..Game Over..");
	score[1].setPosition(sf::Vector2f(width / 8, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));



	selectedItemIndex = 0;
}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
	window.draw(score[0]);
	window.draw(score[1]);
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setColor(sf::Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setColor(sf::Color::Red);
	}
}
