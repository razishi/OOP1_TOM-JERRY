#pragma once
#include "MovingGameObject.h"
#include "Globals.h"




class DumbCat : public MovingGameObject {
private:
    Direction direction = Direction::Right; // Start moving to the right
    bool m_isWall;
public:
    DumbCat(float x, float y, float sizeX, float sizeY, float speed);
    void updateMovement(sf::RenderWindow* target);
    void update(sf::RenderWindow* target);
    
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