#include "Play.h"

//------------------------------------
// Constructor
Play::Play() : m_window(sf::VideoMode(1300, 800), "Tom&Jerry", sf::Style::Close | sf::Style::Titlebar),
m_menu(m_window.getSize().x, m_window.getSize().y)
{
    CreatMenu();
}

//------------------------------------
// Method to create the menu and handle menu events
void Play::CreatMenu()
{
    // Play the start sound
    Sounds::getInstance().playSound(Songs::START);

    // Create background shape and texture
    sf::RectangleShape Pbackground;
    Pbackground.setSize(sf::Vector2f(1300, 800));
    sf::Texture back_texture;
    back_texture.loadFromFile("background.png");
    Pbackground.setTexture(&back_texture);

    // Loop for handling menu events
    while (m_window.isOpen())
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            // Check for window close event
            if (event.type == sf::Event::Closed)
                m_window.close();

            // Check for mouse button release event
            if (event.type == sf::Event::MouseButtonReleased)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    // Get selected menu option
                    int selectedMenu = m_menu.MenuPressed();
                    if (selectedMenu != -1) {
                        // Handle selected menu option
                        switch (selectedMenu)
                        {
                        case 0: // Play
                        {
                            // Pause the start sound and close the menu window
                            Sounds::getInstance().pauseSound(Songs::START);
                            m_window.close();
                            // Start the game by creating and running a controller instance
                            auto play = Controller();
                            play.run();
                            break;
                        }
                        case 1: // About
                        {
                            // Create and display an about window
                            sf::RenderWindow ABOUT(sf::VideoMode(1300, 800), "ABOUT");
                            sf::RectangleShape aboutBackground;
                            aboutBackground.setSize(sf::Vector2f(1300, 800));
                            sf::Texture aboutTexture;
                            aboutTexture.loadFromFile("ABOUT.jpg");
                            aboutBackground.setTexture(&aboutTexture);
                            while (ABOUT.isOpen())
                            {


                                m_window.clear();
                                m_window.close();

                                sf::Event aevent;
                                while (ABOUT.pollEvent(aevent))
                                {
                                    if (aevent.type == sf::Event::Closed)
                                    {
                                        ABOUT.close();
                                    }
                                    if (aevent.type == sf::Event::KeyPressed)
                                    {
                                        if (aevent.key.code == sf::Keyboard::Escape)
                                        {
                                            ABOUT.close();

                                        }
                                    }
                                }
                                ABOUT.clear();
                                ABOUT.draw(aboutBackground); // Draw the about background
                                ABOUT.display();
                            }
                            m_window.create(sf::VideoMode(1300, 800), "Tom&Jerry", sf::Style::Close | sf::Style::Titlebar);
                            break;
                        }
                        case 2: // Exit
                            // Close the menu window
                            m_window.close();
                            break;
                        }
                    }
                }
            }
        }

        // Update mouse position for menu highlight
        sf::Vector2f mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(m_window));
        m_menu.update(mousePos);

        // Draw menu and background
        m_window.clear();
        m_window.draw(Pbackground);
        m_menu.draw(m_window);
        m_window.display();
    }
}