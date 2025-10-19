#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <Globals.h>


const int SOUND_NUM = 3;

class Sounds {
public:
    Sounds();
    ~Sounds();
    static Sounds& getInstance();
    void playSound(Songs SongNum);
    void pauseSound(Songs SongNum);

private:

    std::string m_soundNames[SOUND_NUM] = { "CheeseEat.wav" , "MenuMusic.wav","GamePlay.wav" };

    sf::SoundBuffer m_buffers[SOUND_NUM];
    sf::Sound m_sound;
    sf::Sound m_sounds[SOUND_NUM];
};
