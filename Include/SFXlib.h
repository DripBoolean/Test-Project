#pragma once
#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <SFML/Audio.hpp>
#include <vector>
using namespace std;

enum assets {
    MOVING_ROOT_SFX,
    ROOT_DEATH_SFX,
    DRINKING_WATER_SFX,
    ENEMY_SPAWN_SFX,
    ENEMY_DEATH_SFX,
    NEEDLE_SHOT_SFX,
    NEEDLE_HIT_SFX,
    PLAYER_DEATH_SFX,
    ASSETS_LENGTH // always keep as last one
};

/**
 * @brief SFXlib is a  class that stores sound vectors and sound buffer arrays.
 *        It is able to play multiple sounds at once without cutting other sounds out.
 * 
 */
class SFXlib
{
private:

/**
 * @brief Vector containing type sf::Sound
 * 
 */
vector<sf::Sound> sound;

/**
 * @brief Array containing type sf::SoundBuffer; array is length of ASSETS_LENGTH (number of enums)
 * 
 */
sf::SoundBuffer buffer_array[ASSETS_LENGTH];

/**
 * @brief Map containing enumerated integers that represent different .wav files
 * 
 */
map<int, string> SFX = {{assets::MOVING_ROOT_SFX, "assets/growing_root.wav",},
                        {assets::ROOT_DEATH_SFX, "assets/root_death.wav",},
                        {assets::DRINKING_WATER_SFX, "assets/drinking_water.wav",},
                        {assets::ENEMY_SPAWN_SFX, "assets/enemy_spawn.wav",},
                        {assets::ENEMY_DEATH_SFX, "assets/enemy_death.wav",},
                        {assets::NEEDLE_SHOT_SFX, "assets/needle_shot.wav",},
                        {assets::NEEDLE_HIT_SFX, "assets/needle_hit.wav",},
                        {assets::PLAYER_DEATH_SFX, "assets/player_death.wav",},
                                                        };
public:
    /**
     * @brief Construct a new SFXlib object
     * 
     */
    SFXlib();

    /**
     * @brief Loads buffer for selected sound effect map and adds it to buffer array.
     *        Function should be called once at beggining of main
     * 
     * @param SFX_selection int (probably enumurated) that represents mapped .wav file
     */
    void load(int SFX_selection);

    /**
     * @brief First checks if any sound is playing currently. If it is, it moves to next
     *        sound type in vector until it finds one that is not playing in specified buffer
     *        and plays that one. If there are no sounds in the buffer, 
     *        it will add one and play it.
     * 
     * @param SFX_selection int (probably enumurated) that represents mapped .wav file
     */
    void play_SFX(int SFX_selection);

    /**
     * @brief Calls load function for all integers in enum.
     * 
     */
    void load_all();
};