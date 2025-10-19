#include "Controller.h"

Controller::Controller() {

    Sounds::getInstance().playSound(Songs::GAMEPLAY);

    m_window.setFramerateLimit(144);
    m_board.loadMap(1);

}


void Controller::run() {
    while (m_window.isOpen()) {

        update();
        render();

    }
}




void Controller::update() {
    while (m_window.pollEvent(m_event)) {
        if (m_event.type == sf::Event::Closed)
            m_window.close();
    }

    m_board.update(&m_window);
    if (m_timerClock.getElapsedTime().asSeconds() >= 1) {
        if (m_remainingTime + m_board.getMouse()->getTime() > 0) {
            m_remainingTime--;
        }
        m_timerClock.restart();
    }

}
void Controller::render() {
    m_window.clear();
    // Check if the mouse has lost all lives
    if (texture.GetLive() == 0) {
        // Load the lose texture and display it
        sf::Texture loseTexture;
        if (loseTexture.loadFromFile("lose.jpg")) {
            sf::Sprite loseSprite(loseTexture);
            m_window.draw(loseSprite);
        }
    }
    // Check if the time is 0
    else if (m_remainingTime <= 0) {
        // Load the lose texture and display it
        sf::Texture loseTexture;
        if (loseTexture.loadFromFile("lose.jpg")) {
            sf::Sprite loseSprite(loseTexture);
            m_window.draw(loseSprite);
        }
    }
    else if (m_board.GetCheese() == m_board.getMouse()->getCheese()) {
        // Attempt to load the next level
        if (!m_board.loadMap(++m_currentlevel)) {
            // If the next level couldn't be loaded, display the win screen
            sf::Texture winTexture;
            if (winTexture.loadFromFile("win.jpg")) {
                sf::Sprite winSprite(winTexture);
                m_window.draw(winSprite);
            }
        }
        else {
            m_remainingTime = 30; // Reset the timer for the new level
        }
    }
    else {
        // Render the background and other game elements
        sf::Texture backgroundTexture;
        if (backgroundTexture.loadFromFile("TTom.jpg")) {
            sf::Sprite backgroundSprite(backgroundTexture);
            m_window.draw(backgroundSprite);
        }

        m_board.render(&m_window);
        m_board.update(&m_window);

        // Update toolbar with timer
        texture.updateScore(m_board.getMouse()->getScore());
        texture.updateLive(m_board.getMouse()->getLive());
        texture.updateLevel(m_board.getLevel());
        texture.updateTime(m_board.getMouse()->getTime());
        texture.UpdateToolbar(&m_window, m_remainingTime);
    }

    // Display everything on the window
    m_window.display();
}
