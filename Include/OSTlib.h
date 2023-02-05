#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <SFML/Audio.hpp>
#include <vector>
using namespace std;

enum music_assets {
    MAIN_OST,
    MAIN_OST_FULL,
    MUSIC_LENGTH
};

class OSTlib
{

private:
    vector<sf::Music> vinyl_storage;
    map<int, string> OST_list = {{music_assets::MAIN_OST, "assets/Roots.ogg",},
};

public:
    OSTlib();
    void load_OST(int OST_selection);
    void play_OST(int OST_selection, int pitch, int volume, bool isLooping);
    void load_all();
    void play(int OST_selection, int pitch, int volume, bool isLooping);
};