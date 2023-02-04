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

vector<sf::Sound> sound;
sf::SoundBuffer buffer_array[ASSETS_LENGTH];

map<int, string> SFX = {{assets::MOVING_ROOT_SFX, "assets/growing_root.wav",},
                                                        };

public:
    SFXlib();
    void load(int SFX_selection);
    void play_SFX(int SFX_selection);
};