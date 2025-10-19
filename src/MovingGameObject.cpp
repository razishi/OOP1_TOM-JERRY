#include "MovingGameObject.h"

MovingGameObject::MovingGameObject(float x, float y, float sizeX, float sizeY,
    float speed)
    : GameObject(x, y, sizeX, sizeY),
    m_startPosition(sf::Vector2f(x, y)),
    m_lastPosition(sf::Vector2f(x, y)),
    m_speed(speed) {}



