#include "Door.h"

Door::Door(float x, float y, float sizeX, float sizeY)
    : StaticGameObject(x, y, sizeX, sizeY) {
    setObjTexture(DOOR);
    m_TotalKeys = 0;
}


void Door::KeyCount(int Count) {
    m_TotalKeys = Count;

}
void Door::colide(GameObject& otherObject)
{
    otherObject.colide(*this);

}

void Door::colide(Mouse& otherObject)
{
    if(m_TotalKeys > 0 )
    markForDeletion();

}

void Door::colide(SmartCat& otherObject)
{
}

void Door::colide(Gift& otherObject)
{
}

void Door::colide(Cheese& otherObject)
{
}

void Door::colide(Key& otherObject)
{
}

void Door::colide(Wall& otherObject)
{
}

void Door::colide(Door& otherObject)
{
}

void Door::colide(DumbCat& otherObject)
{
}

void Door::colide(Addlife& otherObject)
{
}

void Door::colide(Freeze& otherObject)
{
}

void Door::colide(Newtime& otherObject)
{
}




