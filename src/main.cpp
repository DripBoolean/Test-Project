#include <iostream>
#include <SFML/Graphics.hpp>
#include "Vec2.h"
#include "Root.h"
#include "Circle.h"
#include "Obstacles.h"
#include "Screen.h"
#include "Enemy.h"
#include "SFXlib.h"
#include <SFML/Audio.hpp>
#include "Map.h"
#include "Plant.h"
//#include "OSTlib.h"

#define FPS 60.f

Vec2<float> Enemy::target = Vec2<float>(0.f, -10.f);

int main() {
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "I got no roots - Demi Lovato");

    sf::View view;
    sf::Clock clock;
    sf::Clock total_time;

    Map map;
    SFXlib jukebox;
    jukebox.load_all();

    //OSTlib vinyl;
    //vinyl.play(music_assets::MAIN_OST, 2, 100, false);

    sf::Music music;
    if (!music.openFromFile("assets/Roots.ogg"))
        return -1; // error
    music.play();
    music.setLoop(false);

    Plant bulber;
    
    std::vector<Enemy> enemies;
    std::vector<Projectile> projectiles;

    while (window.isOpen())
    {   
        clock.restart();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if(event.key.code == sf::Keyboard::Space) {
                    bulber.shoot_projectile(projectiles);
                }
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            bulber.rotate_left();
            //jukebox.play_SFX(assets::MOVING_ROOT_SFX);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            bulber.rotate_right();
            //jukebox.play_SFX(assets::MOVING_ROOT_SFX);
        }

        view = bulber.get_view();

        if(total_time.getElapsedTime().asSeconds() > Enemy::spawn_time) {
            if(rand() % (int)(Enemy::spawn_chance * FPS) == 0) {
                enemies.push_back(Enemy(view));
                jukebox.play_SFX(assets::ENEMY_SPAWN_SFX);
            }
        }

        for(Enemy& enemy : enemies) {
            enemy.update();
        }

        for(Projectile& projectile : projectiles) {
            projectile.update();
        } 

        handle_collision(projectiles, enemies);

        bulber.update(map);
        window.setView(view);
        window.clear();
        
        map.draw(window);

        bulber.draw(window);

        for(Enemy& enemy : enemies) {
            enemy.draw(window);
        }

        for(Projectile& projectile : projectiles) {
            projectile.draw(window);
        }

        window.display();
        while(clock.getElapsedTime().asSeconds() < 1.0 / FPS) {}
    }

    return 0;
	
}