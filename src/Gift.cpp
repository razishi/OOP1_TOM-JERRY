
#include "Gift.h"

Gift::Gift(float x, float y, float sizeX, float sizeY)
    : StaticGameObject(x, y, sizeX, sizeY) {
    setObjTexture(GIFT);
}

void Gift::colide(GameObject& otherObject)
{
    otherObject.colide(*this);

}

void Gift::colide(Mouse& otherObject)
{
    markForDeletion();

}

void Gift::colide(SmartCat& otherObject)
{
}

void Gift::colide(Gift& otherObject)
{
}

void Gift::colide(Cheese& otherObject)
{
}

void Gift::colide(Key& otherObject)
{
}

void Gift::colide(Wall& otherObject)
{
}

void Gift::colide(Door& otherObject)
{
}

void Gift::colide(DumbCat& otherObject)
{
}

void Gift::colide(Addlife& otherObject)
{
}

void Gift::colide(Freeze& otherObject)
{
}

void Gift::colide(Newtime& otherObject)
{
}
