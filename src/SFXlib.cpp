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
    sf::Sound new_sound;
    sound.push_back(new_sound);
    sf::SoundBuffer new_buffer;
    buffer_array[SFX_selection] = new_buffer;
    if(!buffer_array[SFX_selection].loadFromFile(SFX[SFX_selection]))
        throw std::runtime_error("Linked file was not found by compiler.");
    sound[SFX_selection].setBuffer(buffer_array[SFX_selection]);
    sound[SFX_selection].play();
}

void SFXlib::play_SFX(int SFX_selection)
{
    cout << sound[SFX_selection].getStatus() << endl;
}