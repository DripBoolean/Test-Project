#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <SFML/Audio.hpp>
#include <vector>
using namespace std;

enum assets {
    MOVING_ROOT_SFX,
    ASSETS_LENGTH // always keep as last one
};

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
};