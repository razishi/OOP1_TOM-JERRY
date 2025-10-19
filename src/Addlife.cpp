#include "Addlife.h"


Addlife::Addlife(float x, float y, float sizeX, float sizeY)
    : StaticGameObject(x, y, sizeX, sizeY) {
    setObjTexture(ADDLIFE);
}

void Addlife::colide(GameObject& otherObject)
{
}

void Addlife::colide(Mouse& otherObject)
{
    markForDeletion();

}

void Addlife::colide(SmartCat& otherObject)
{
}

void Addlife::colide(Gift& otherObject)
{
}

void Addlife::colide(Cheese& otherObject)
{
}

void Addlife::colide(Key& otherObject)
{
}

void Addlife::colide(Wall& otherObject)
{
}

void Addlife::colide(Door& otherObject)
{
}

void Addlife::colide(DumbCat& otherObject)
{
}

void Addlife::colide(Addlife& otherObject)
{
}

void Addlife::colide(Freeze& otherObject)
{
}

void Addlife::colide(Newtime& otherObject)
{
}
