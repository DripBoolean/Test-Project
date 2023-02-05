#include <iostream>
#include <iterator>
#include <map>
#include <SFML/Audio.hpp>
#include <exception>
#include "SFXlib.h"
using namespace std;

SFXlib::SFXlib()
{
}

void SFXlib::load(int SFX_selection)
{
    sf::SoundBuffer new_buffer;
    buffer_array[SFX_selection] = new_buffer;
    if(!buffer_array[SFX_selection].loadFromFile(SFX[SFX_selection]))
        throw std::runtime_error("Linked file was not found by compiler.");
}

void SFXlib::play_SFX(int SFX_selection)
{
    for(int i = 0; i < sound.size(); i++)
    {
        if(sound[i].getStatus() == 2)
            continue;
        sound[i].setBuffer(buffer_array[SFX_selection]);
        sound[i].play();
        return;
    }
    sf::Sound new_sound;
    sound.push_back(new_sound);
    sound.back().setBuffer(buffer_array[SFX_selection]);
    sound.back().play();
}