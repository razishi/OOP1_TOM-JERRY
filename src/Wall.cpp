#include "Wall.h"
#include "iostream"
Wall::Wall(float x, float y, float sizeX, float sizeY)
    : StaticGameObject(x, y, sizeX, sizeY) {
    setObjTexture(WALL);
}

void Wall::colide(GameObject& otherObject)
{
    otherObject.colide(*this);

}

void Wall::colide(Mouse& otherObject)
{

}


void Wall::colide(SmartCat& otherObject)
{
}

void Wall::colide(Gift& otherObject)
{
}

void Wall::colide(Cheese& otherObject)
{
}

void Wall::colide(Key& otherObject)
{
}

void Wall::colide(Wall& wall)
{
}

void Wall::colide(Door& otherObject)
{
}

void Wall::colide(DumbCat& otherObject)
{
}

void Wall::colide(Addlife& otherObject)
{
}

void Wall::colide(Freeze& otherObject)
{
}

void Wall::colide(Newtime& otherObject)
{
}


