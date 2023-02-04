#include <iostream>
#include <SFML/Graphics.hpp>
#include "Vec2.h"
#include "Root.h"
#include "Circle.h"
#include "Obstacles.h"

int main() {

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    Circle test_circle(Vec2<float>(100.f, 100.f), 100.f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        test_circle.draw(window, sf::Color::Green);
        window.display();
    }

    return 0;
	
}