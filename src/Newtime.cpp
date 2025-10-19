#include "Newtime.h"


Newtime::Newtime(float x, float y, float sizeX, float sizeY)
    : StaticGameObject(x, y, sizeX, sizeY) {
    setObjTexture(NEWTIME);
}

void Newtime::colide(GameObject& otherObject)
{
    otherObject.colide(*this);

}

void Newtime::colide(Mouse& otherObject)
{
    markForDeletion();

}

void Newtime::colide(SmartCat& otherObject)
{
}

void Newtime::colide(Gift& otherObject)
{
}

void Newtime::colide(Cheese& otherObject)
{
}

void Newtime::colide(Key& otherObject)
{
}

void Newtime::colide(Wall& otherObject)
{
}

void Newtime::colide(Door& otherObject)
{
}

void Newtime::colide(DumbCat& otherObject)
{
}

void Newtime::colide(Addlife& otherObject)
{
}

void Newtime::colide(Freeze& otherObject)
{
}

void Newtime::colide(Newtime& otherObject)
{
}
