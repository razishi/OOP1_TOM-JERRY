#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>



class Textures {
public:
    static Textures& getInstance();
    sf::Texture* getObjTexture(int Num);
    ~Textures();
    void LoadTextures(sf::Texture& clockTexture, sf::Texture& heartTexture, sf::Texture& levelTexture,
        sf::Texture& scoreTexture);
    void CreateSprites(sf::Sprite& clockSprite, sf::Sprite& heartSprite, sf::Sprite& levelSprite, sf::Sprite& scoreSprite,
        const sf::Texture& clockTexture, const sf::Texture& heartTexture, const sf::Texture& levelTexture,
        const sf::Texture& scoreTexture);
    void SetSpritePositions(sf::Sprite& clockSprite, sf::Sprite& heartSprite, sf::Sprite& levelSprite,
        sf::Sprite& scoreSprite);
    void DrawSprites(sf::RenderWindow* target, const sf::Sprite& clockSprite, const sf::Sprite& heartSprite,
        const sf::Sprite& levelSprite,
        const sf::Sprite& scoreSprite);
    void CreateAndDrawText(sf::RenderWindow* target, const sf::Sprite& clockSprite, const sf::Sprite& heartSprite,
        const sf::Sprite& levelSprite, const sf::Sprite& scoreSprite) const;
    void updateLevel(int level);
    int GetLive();
    int getTime() const;
    Textures();
    void UpdateToolbar(sf::RenderWindow* target, int remainingTime);
    void updateScore(int score);
    int  Getscore() const;
    void updateLive(int live);
    void updateTime(int time);



private:
        std::string m_imgNames[15] = {
             "Smartcat.png",  "cheese.png", "door.png",
             "gift.png", "wall.png",  "key.png",
             "mouse1.png" , "DumbCat.png" ,"addheart.png","addtime.png","freeze.png",  "heart.png" ,  "clock.png" ,
             "scoreee.png" , "level.png" , 
               };
    sf::Texture m_textures[15];
    sf::Sprite m_clockSprite;
    sf::Sprite m_heartSprite;
    sf::Sprite m_levelSprite;
    sf::Sprite m_scoreSprite;
    sf::Text m_clockText;
    sf::Text m_levelText;
    sf::Text m_scoreText;
    sf::Text m_heartText;
    sf::Texture m_scoreTexture;
    sf::Texture m_clockTexture;
    sf::Texture m_levelTexture;
    sf::Texture m_heartTexture;
    int m_score = 0;
    int m_live = 3;
    int m_level ;
    int m_time = 0;
    sf::Font m_font;
};