#pragma once

#include "StaticGameObject.h"
class Wall : public StaticGameObject {
public:
    Wall(float x, float y, float size_x, float size_y);

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
