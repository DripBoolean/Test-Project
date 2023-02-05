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

#define FPS 60.f

Vec2<float> Enemy::target = Vec2<float>(0.f, -10.f);

int main() {
    srand(time(0));
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "I got no roots - Demi Lovato");

    sf::Texture dirt_texture;
    if(!dirt_texture.loadFromFile("assets/Dirt.png")) throw std::runtime_error("bro");
    dirt_texture.setRepeated(true);
    
    sf::Texture sky_texture;
    if(!sky_texture.loadFromFile("assets/Sky.jpg")) throw std::runtime_error("bro");

    sf::Sprite dirt;
    dirt.setTexture(dirt_texture);
    dirt.setTextureRect({0, 0, 10000, 5000});
    dirt.setScale(0.2f, 0.2f);
    dirt.setPosition(sf::Vector2f(-1000.f, 0.f));

    sf::Sprite sky;
    sky.setTexture(sky_texture);
    sky.setTextureRect( {-100, -100, 100, (int)(100 * ASPECT_RATIO)} );
    sky.setPosition(0.f, 0.f);

    sf::View view;
    sf::View background_view;
    background_view.setSize(100.f, 100.f * ASPECT_RATIO);
    background_view.setCenter(0.f, 0.f);
    sf::Clock clock;
    sf::Clock total_time;

    Map map;
    SFXlib jukebox;
    jukebox.load_all();

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
        
        window.clear(sf::Color(255, 150, 50, 255));
        window.setView(background_view);
        window.draw(sky);

        window.setView(view);
        window.draw(dirt);
        
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