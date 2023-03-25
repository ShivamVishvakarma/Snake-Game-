#include <SFML/Graphics.hpp>
#include"Snake.h"
#include"Food.h"
#include<string>
#include<sstream>


std::string toString(int num)
{
    std::stringstream ss;
    ss << num;
    return ss.str();
}


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Snake Game!");
    window.setFramerateLimit(60);

    Snake snake(window);
    Food food(window);

    int check = -1;

    
   
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type = sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Up && snake.getDirection()!=3) 
                    snake.moveUp();
                if (event.key.code == sf::Keyboard::Right && snake.getDirection() != 4)
                    snake.moveRight();
                if (event.key.code == sf::Keyboard::Down && snake.getDirection() != 1)
                    snake.moveDown();
                if (event.key.code == sf::Keyboard::Left && snake.getDirection() != 2)
                    snake.moveLeft();
            }
        }
       
        check = snake.checkCollision(food.getXpos(), food.getYpos());
        if (check == 1)
        {
            food.move();
        }
        else if (check == 0)
            break;
        window.clear();
        snake.run();
        food.draw();

        window.display();
        sf::sleep(sf::seconds(0.2));
    }

    return 0;
}