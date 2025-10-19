
#include "Cheese.h"

Cheese::Cheese(float x, float y, float sizeX, float sizeY)
    : StaticGameObject(x, y, sizeX, sizeY) {
    setObjTexture(CHEESE);
}

void Cheese::colide(GameObject& otherObject)
{
}

void Cheese::colide(Mouse& otherObject)
{
    markForDeletion();
}

void Cheese::colide(SmartCat& otherObject)
{
}

void Cheese::colide(Gift& otherObject)
{
}

void Cheese::colide(Cheese& otherObject)
{
}

void Cheese::colide(Key& otherObject)
{
}

void Cheese::colide(Wall& otherObject)
{
}

void Cheese::colide(Door& otherObject)
{
}

void Cheese::colide(DumbCat& otherObject)
{
}

void Cheese::colide(Addlife& otherObject)
{
}

void Cheese::colide(Freeze& otherObject)
{
}

void Cheese::colide(Newtime& otherObject)
{
}
