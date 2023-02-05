#include <iostream>
#include <SFML/Graphics.hpp>
#include "Vec2.h"
#include "Root.h"
#include "Circle.h"
#include "Obstacles.h"
#include "Screen.h"
#include "Enemy.h"
#include "Map.h"

#define FPS 60.f

Vec2<float> Enemy::target = Vec2<float>(0.f, -10.f);

int main() {
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "I got no roots - Demi Lovato");

    sf::View view;
    sf::Clock clock;
    sf::Clock total_time;

    Map map;

    Root main_root(Vec2<float>(0.f, 0.f), Vec2<float>(0.f, 0.1f));

    
    std::vector<Enemy> enemies;

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
            main_root.rotate(-0.03);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            main_root.rotate(0.03);
        }

        view = main_root.get_view();

        if(total_time.getElapsedTime().asSeconds() > Enemy::spawn_time) {
            if(rand() % (int)(Enemy::spawn_chance * FPS) == 0) {
                enemies.push_back(Enemy(view));
            }
        }

        for(Enemy& enemy : enemies) {
            enemy.update();
        }

        main_root.move();
        main_root.harvest(map);
        window.setView(view);
        window.clear();
        
        map.draw(window);

        main_root.draw(window);

        for(Enemy& enemy : enemies) {
            enemy.draw(window);
        }

        window.display();
        while(clock.getElapsedTime().asSeconds() < 1.0 / FPS) {}
    }

    return 0;
	
}