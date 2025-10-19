#pragma once
#include "MovingGameObject.h"


class SmartCat : public MovingGameObject {
private:
    bool m_Moved;
    bool m_Blocked;
  
public:
    SmartCat(float x, float y, float sizeX, float sizeY, float speedChac);
    void updateMovement(sf::RenderWindow* target, sf::Vector2f mouseLocation);
    void update(sf::RenderWindow* target , sf::Vector2f mouseLocation);

    float distance(sf::Vector2f v1, sf::Vector2f v2) const;

    void colide(GameObject& otherObject);
    void colide(Mouse& otherObject);
    void colide(SmartCat& otherObject);
    void colide(Gift& otherObject);
    void colide(Cheese& otherObject);
    void colide(Key& otherObject);
    void colide(Wall& wall); // Add this line
    void colide(Door& otherObject);
    void colide(DumbCat& otherObject);
    void colide(Addlife& otherObject);
    void colide(Freeze& otherObject);
    void colide(Newtime& otherObject);



};