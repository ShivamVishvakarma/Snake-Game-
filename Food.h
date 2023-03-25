#pragma once
#include<SFML/Graphics.hpp>
class Food
{
private:
	int size = 20;
	sf::RectangleShape food;
	sf::RenderWindow* win;
	int xpos;
	int ypos;
public:
	Food(sf::RenderWindow&);
	void draw();
	void move();
	int random(int, int);
	int getXpos();
	int getYpos();
};