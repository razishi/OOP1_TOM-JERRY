#include "Textures.h"


Textures& Textures::getInstance() {
    static Textures instance;
    return instance;
}

Textures::Textures() {
    for (int i = 0; i < 15; i++) {
        m_textures[i].loadFromFile(m_imgNames[i]);
    }

}


void Textures::updateScore(int score)
{
    m_score = score;
}


void Textures::updateLive(int live)
{
    m_live = live;
}

int Textures::GetLive()
{
    return m_live;
}

void Textures::updateTime(int time)
{
    m_time = time;
}
void Textures::updateLevel(int level)
{
    m_level = level;
}

int  Textures::Getscore() const
{
    return m_score;

}

sf::Texture* Textures::getObjTexture(int Num) {
    return &m_textures[Num];
}


Textures::~Textures() {}

void Textures::LoadTextures(sf::Texture& clockTexture, sf::Texture& heartTexture,
    sf::Texture& levelTexture, sf::Texture& scoreTexture) {
    if (!heartTexture.loadFromFile("heart.png")) {
        std::cerr << "Failed to load heart texture!" << std::endl;
    }
    if (!clockTexture.loadFromFile("clock.png")) {
        std::cerr << "Failed to load clock texture!" << std::endl;
    }
    if (!scoreTexture.loadFromFile("scoreee.png")) {
        std::cerr << "Failed to load score texture!" << std::endl;
    }
    if (!levelTexture.loadFromFile("level.png")) {
        std::cerr << "Failed to load level texture!" << std::endl;
    }
}

void Textures::CreateSprites(sf::Sprite& clockSprite, sf::Sprite& heartSprite, sf::Sprite& levelSprite,
    sf::Sprite& scoreSprite, const sf::Texture& clockTexture, const sf::Texture& heartTexture,
    const sf::Texture& levelTexture, const sf::Texture& scoreTexture) {
    clockSprite.setTexture(clockTexture);
    heartSprite.setTexture(heartTexture);
    levelSprite.setTexture(levelTexture);
    scoreSprite.setTexture(scoreTexture);

    float spriteScale = 0.1f;
    clockSprite.setScale(spriteScale, spriteScale);
    heartSprite.setScale(spriteScale, spriteScale);
    levelSprite.setScale(spriteScale, spriteScale);
    scoreSprite.setScale(spriteScale, spriteScale);
}

void Textures::SetSpritePositions(sf::Sprite& clockSprite, sf::Sprite& heartSprite,
    sf::Sprite& levelSprite, sf::Sprite& scoreSprite) {
    float offsetX = 0.1f;
    float offsetY = 0.1f;
    float spacing = 100.0f;
    clockSprite.setPosition(offsetX, offsetY);

    float spriteWidth = clockSprite.getTexture()->getSize().x * clockSprite.getScale().x;
    heartSprite.setPosition(offsetX + (spriteWidth + spacing) * 1.5, offsetY);
    levelSprite.setPosition(offsetX + (spriteWidth + spacing) * 3.1, offsetY);
    scoreSprite.setPosition(offsetX + (spriteWidth + spacing) * 4.5, offsetY);
}

void Textures::DrawSprites(sf::RenderWindow* target, const sf::Sprite& clockSprite,
    const sf::Sprite& heartSprite, const sf::Sprite& levelSprite, const sf::Sprite& scoreSprite) {
    target->draw(clockSprite);
    target->draw(heartSprite);
    target->draw(levelSprite);
    target->draw(scoreSprite);
}

void Textures::CreateAndDrawText(sf::RenderWindow* target, const sf::Sprite& clockSprite,
    const sf::Sprite& heartSprite, const sf::Sprite& levelSprite, const sf::Sprite& scoreSprite) const {

    sf::Text heartText(":" + std::to_string(m_live), m_font, 40);
    heartText.setFillColor(sf::Color::Black);
    heartText.setPosition(heartSprite.getPosition().x + heartSprite.getGlobalBounds().width + 10, heartSprite.getPosition().y);       
    sf::Text levelText(":" + std::to_string(m_level - 1), m_font, 40);
    levelText.setFillColor(sf::Color::Black);
    levelText.setPosition(levelSprite.getPosition().x + levelSprite.getGlobalBounds().width + 10, levelSprite.getPosition().y);

    sf::Text scoreText(":" + std::to_string(m_score), m_font, 40);
    scoreText.setFillColor(sf::Color::Black);
    scoreText.setPosition(scoreSprite.getPosition().x + scoreSprite.getGlobalBounds().width + 10, scoreSprite.getPosition().y);

    target->draw(heartText);
    target->draw(levelText);
    target->draw(scoreText);
}

void Textures::UpdateToolbar(sf::RenderWindow* target, int remainingTime) {
    sf::Texture clockTexture, heartTexture, levelTexture, scoreTexture;
    LoadTextures(clockTexture, heartTexture, levelTexture, scoreTexture);

    sf::Sprite clockSprite, heartSprite, levelSprite, scoreSprite;
    CreateSprites(clockSprite, heartSprite, levelSprite, scoreSprite, clockTexture, heartTexture, levelTexture, scoreTexture);
    SetSpritePositions(clockSprite, heartSprite, levelSprite, scoreSprite);
    DrawSprites(target, clockSprite, heartSprite, levelSprite, scoreSprite);



    // Create text for timer
    if (!m_font.loadFromFile("C:/Windows/Fonts/BRUSHSCI.ttf")) {
        std::cout << "No font is here" << std::endl;
    }
    sf::Text timerText(": " + std::to_string(remainingTime + m_time), m_font, 40);
    timerText.setFillColor(sf::Color::Black);
    timerText.setPosition(clockSprite.getPosition().x + clockSprite.getGlobalBounds().width + 10, clockSprite.getPosition().y);

    // Draw timer text
    target->draw(timerText);
    CreateAndDrawText(target, clockSprite, heartSprite, levelSprite, scoreSprite);
}



int Textures::getTime() const {
    std:: cout << m_time;
    return m_time;
}