
#include "SmartCat.h"

SmartCat::SmartCat(float x, float y, float sizeX, float sizeY, float speed)
    : MovingGameObject(x, y, sizeX, sizeY, speed) {
    setObjTexture(SMARTCAT);
    m_Moved = false;
    m_Blocked = false; 
    m_Speednes = speed;
    m_InitPosition = getPostion();

}

void SmartCat::updateMovement(sf::RenderWindow* target, sf::Vector2f mouseLocation) {
    sf::Vector2f movement(0.f, 0.f);

    // Save the current position
    m_lastPosition = getPostion();

    std::vector<std::pair<float, int>> directions = {
        {distance(mouseLocation, {getPostion().x, getPostion().y - 1}), 0}, // left
        {distance(mouseLocation, {getPostion().x, getPostion().y + 1}), 1}, // right
        {distance(mouseLocation, {getPostion().x + 1, getPostion().y}), 2}, // Down
        {distance(mouseLocation, {getPostion().x - 1, getPostion().y}), 3}  // Up
    };

    std::sort(directions.begin(), directions.end());

    for (auto& dir : directions) {
        switch (dir.second) {
        case 0:
            movement.x -= m_Speednes;
            break;
        case 1:
            movement.x += m_Speednes;
            break;
        case 2:
            movement.y += m_Speednes;
            break;
        case 3:
            movement.y -= m_Speednes;
            break;
        }

        // Check if the new position is closer to the mouse
        sf::Vector2f newPosition = getPostion() + movement * m_Speednes;
        if (distance(mouseLocation, newPosition) < distance(mouseLocation, getPostion())) {
            move(movement * m_Speednes);
            break;
        }
        else {
            // Reset movement if not closer
            movement = sf::Vector2f(0.f, 0.f);
        }
    }
}



float SmartCat::distance(sf::Vector2f v1, sf::Vector2f v2) const
{
	return std::hypot(v1.x - v2.x, v1.y - v2.y);
}


void SmartCat::update(sf::RenderWindow* target, sf::Vector2f mouseLocation) {
    this->updateMovement(target,mouseLocation);
}


void SmartCat::colide(GameObject& otherObject)
{
    otherObject.colide(*this);

}

void SmartCat::colide(Mouse& otherObject)
{
    UpdatePostion(m_InitPosition);


}

void SmartCat::colide(SmartCat& otherObject)
{
    m_Blocked = true;
    UpdatePostion(m_lastPosition);
}

void SmartCat::colide(Gift& otherObject)
{
}

void SmartCat::colide(Cheese& otherObject)
{

}

void SmartCat::colide(Key& otherObject)
{

}

void SmartCat::colide(Wall& otherObject)
{
    m_Blocked = true; 
    UpdatePostion(m_lastPosition);


}

void SmartCat::colide(Door& otherObject)
{
    m_Blocked = true;
    UpdatePostion(m_lastPosition);

}

void SmartCat::colide(DumbCat& otherObject)
{
}

void SmartCat::colide(Addlife& otherObject)
{
}

void SmartCat::colide(Freeze& otherObject)
{
}

void SmartCat::colide(Newtime& otherObject)
{
}

