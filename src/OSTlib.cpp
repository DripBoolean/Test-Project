#include <iostream>
#include <iterator>
#include <map>
#include <SFML/Audio.hpp>
#include <exception>
#include "OSTlib.h"
using namespace std;

OSTlib::OSTlib()
{
}

// void OSTlib::load_OST(int OST_selection)
// {
//     sf::Music new_music;
//     vinyl_storage.push_back(new_music);
//     if (!new_music.openFromFile(OST_list[OST_selection]))
//     {
//         cout << OST_selection << endl;
//         throw std::runtime_error("Linked file {SFX_selection} was not found by compiler.");
//     }
// }

// void OSTlib::play_OST(int OST_selection, int pitch, int volume, bool isLooping)
// {
//     vinyl_storage[OST_selection].setPosition(0, 1, 10); // change its 3D position
//     vinyl_storage[OST_selection].setPitch(pitch);           // increase the pitch
//     vinyl_storage[OST_selection].setVolume(volume);         // reduce the volume
//     vinyl_storage[OST_selection].setLoop(isLooping);         // make it loop
//     for(int i = 0; i < vinyl_storage.size(); i++)
//     {
//         if(vinyl_storage[i].getStatus() == 2)
//             return;
//     }
//     vinyl_storage[OST_selection].play();
// }

void OSTlib::play(int OST_selection, int pitch, int volume, bool isLooping)
{
    sf::Music music;
    if (!music.openFromFile(OST_list[OST_selection]))
    {
        cout << OST_selection << endl;
        throw std::runtime_error("Linked file {OST_selection} was not found by compiler.");
    }  
    music.setPosition(0, 1, 10); // change its 3D position
    music.setPitch(pitch);           // increase the pitch
    music.setVolume(volume);         // reduce the volume
    music.setLoop(isLooping);         // make it loop
    // Play it
    music.play();
}