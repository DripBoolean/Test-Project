#include <iostream>
#include <SFML/Graphics.hpp>
#include "Vec2.h"
#include "Root.h"
#include "Circle.h"

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080
#define ASPECT_RATIO ((float)SCREEN_HEIGHT / (float)SCREEN_WIDTH)

int main() {
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "I got no roots - Demi Lovato");

    sf::View view;
    view.setCenter(0.f, 10.f);
    view.setSize(100.f, 100.f * ASPECT_RATIO);

    sf::Clock clock;

    Root mainRoot(Vec2<float>(0.f, 0.f), Vec2<float>(0.f, 0.1f));

    while (window.isOpen())
    {   
        clock.restart();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            mainRoot.rotate(-0.03);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            mainRoot.rotate(0.03);
        }

        mainRoot.move();
        window.setView(view);
        window.clear();
        mainRoot.draw(window);
        window.display();
        while(clock.getElapsedTime().asSeconds() < 1.0 / 60.0) {}
    }

    return 0;
	
}