#pragma once

#include <iostream>
#include "Board.h"
#include "Globals.h"
#include "Textures.h"
#include <string>
#include "Sounds.h"

class Controller {
public:
    Controller();
    void run();
    void update();
    void render();

private:
    sf::RenderWindow m_window =
        sf::RenderWindow(sf::VideoMode(800, 850), "TOM&JERY",
            sf::Style::Close | sf::Style::Titlebar);
    sf::Event m_event;
    Board m_board;
    int m_remainingTime = 120;
    sf::Clock m_timerClock;
    Textures texture;
    std::vector<std::string> m_playlist; // Store level file names
    sf::Clock m_winTimer; // Timer for win screen display
    bool m_showWinScreen; // Flag to indicate if win screen should be displayed
    int  m_currentlevel = 0;


};