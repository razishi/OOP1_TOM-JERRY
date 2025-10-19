#include "Key.h"
#include"iostream"
Key::Key(float x, float y, float sizeX, float sizeY)
    : StaticGameObject(x, y, sizeX, sizeY) {
    setObjTexture(KEY);
}



void Key::colide(GameObject& otherObject)
{
    otherObject.colide(*this);

}

void Key::colide(Mouse& otherObject)
{
    
        markForDeletion();
    

}

void Key::colide(SmartCat& otherObject)
{
}

void Key::colide(Gift& otherObject)
{
}

void Key::colide(Cheese& otherObject)
{
}

void Key::colide(Key& otherObject)
{
}

void Key::colide(Wall& otherObject)
{
}

void Key::colide(Door& otherObject)
{
}

void Key::colide(DumbCat& otherObject)
{
}

void Key::colide(Addlife& otherObject)
{
}

void Key::colide(Freeze& otherObject)
{
}

void Key::colide(Newtime& otherObject)
{
}
