#include "Freeze.h"


Freeze::Freeze(float x, float y, float sizeX, float sizeY)
    : StaticGameObject(x, y, sizeX, sizeY) {
    setObjTexture(FREEZE);
}

void Freeze::colide(GameObject& otherObject)
{
    otherObject.colide(*this);

}

void Freeze::colide(Mouse& otherObject)
{
    markForDeletion();

}

void Freeze::colide(SmartCat& otherObject)
{
}

void Freeze::colide(Gift& otherObject)
{
}

void Freeze::colide(Cheese& otherObject)
{
}

void Freeze::colide(Key& otherObject)
{
}

void Freeze::colide(Wall& otherObject)
{
}

void Freeze::colide(Door& otherObject)
{
}

void Freeze::colide(DumbCat& otherObject)
{
}

void Freeze::colide(Addlife& otherObject)
{
}

void Freeze::colide(Freeze& otherObject)
{
}

void Freeze::colide(Newtime& otherObject)
{
}
