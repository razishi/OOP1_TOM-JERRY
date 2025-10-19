
#include "DumbCat.h"

DumbCat::DumbCat(float x, float y, float sizeX, float sizeY, float speed)
    : MovingGameObject(x, y, sizeX, sizeY, speed) {
    setObjTexture(DUMPCAT);
    m_Speednes = speed;
    m_TotalKeys = 0;
    m_isWall = false; 
    m_InitPosition = getPostion();

}

void DumbCat::updateMovement(sf::RenderWindow* target) {
    sf::Vector2f movement(0.f, 0.f);

    // Save the current position
    m_lastPosition = getPostion();

    // Move left and right along the same Y-axis
    if (direction == Direction::Left) {
        movement.x -= m_Speednes;
        if (m_isWall) { // Check if it hits the left boundary
            direction = Direction::Right;
            m_isWall = false;
            return;// Change direction
        }
    }
    else if (direction == Direction::Right) {
        movement.x += m_Speednes;
        if (m_isWall) { // Check if it hits the right boundary
            direction = Direction::Left;
            m_isWall = false;
            return;// Change direction
        }
    }

    if (movement.x != 0.f || movement.y != 0.f) {
        move(movement);
        // This will update the position of the DumbCat object
    }
}


void DumbCat::update(sf::RenderWindow* target) {
    this->updateMovement(target);
}


void DumbCat::colide(GameObject& otherObject)
{
    otherObject.colide(*this);

}

void DumbCat::colide(Mouse& otherObject)
{
    UpdatePostion(m_InitPosition);

}

void DumbCat::colide(SmartCat& otherObject)
{
}

void DumbCat::colide(Gift& otherObject)
{
}

void DumbCat::colide(Cheese& otherObject)
{

}

void DumbCat::colide(Key& otherObject)
{

}

void DumbCat::colide(Wall& otherObject)
{
    m_isWall = true;
    UpdatePostion(m_lastPosition);

}

void DumbCat::colide(Door& otherObject)
{
    UpdatePostion(m_lastPosition);

}

void DumbCat::colide(DumbCat& otherObject)
{
}

void DumbCat::colide(Addlife& otherObject)
{
}

void DumbCat::colide(Freeze& otherObject)
{
}

void DumbCat::colide(Newtime& otherObject)
{
}

