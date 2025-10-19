#include "Mouse.h"
#include<iostream>

Mouse::Mouse(float x, float y, float sizeX, float sizeY, float speed, int lives)
    : MovingGameObject(x, y, sizeX, sizeY, speed), m_lives(lives) {
    setObjTexture(MOUSE);
    m_Speednes = speed;
    m_InitSizeX = sizeX;
    m_InitSizeY = sizeY;
    m_TotalKeys = 0;
    m_InitPosition = getPostion();
    m_CatDelete = false;


}

void Mouse::updateMovement(sf::RenderWindow* target) {
    getMiddle(m_InitSizeX, m_InitSizeY);
    sf::Vector2f movement(0.f, 0.f);

    float rotation = 0.f;

    // Save the current position
    m_lastPosition = getPostion();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        movement.x -= m_Speednes;
        rotation = 90.f;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        movement.x += m_Speednes;
        rotation = 270.f;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        movement.y -= m_Speednes;
        rotation = 180.f;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        movement.y += m_Speednes;
        rotation = 0.f;
    }

    if (movement.x != 0.f || movement.y != 0.f) {
        SetRotation(rotation);
        move(movement); // This will update the position of the Mouse object
    }
}

int Mouse::getKeyNum() const
{
    return m_TotalKeys;
}


void Mouse::update(sf::RenderWindow* target) {
    this->updateMovement(target);
}


void Mouse::colide(GameObject& otherObject)
{
    otherObject.colide(*this);
}

void Mouse::colide(Mouse& otherObject)
{
    
}



void Mouse::colide(SmartCat& otherObject)
{
    m_lives--;
    UpdatePostion(m_InitPosition);
    m_texture.updateLive(m_lives);
}

void Mouse::colide(Gift& otherObject)
{
    m_score = m_score + 5;
    m_texture.updateScore(m_score);
    m_CatDelete = true;

}

bool Mouse::DeleteCat() const
{
    return m_CatDelete;
}

void Mouse::DeletedCat()
{
    m_CatDelete = false;
}

void Mouse::colide(Cheese& otherObject)
{
    Sounds::getInstance().playSound(Songs::EAT);
    m_score = m_score + 10;
    m_texture.updateScore(m_score);
    m_counterChees++;

}

void Mouse::colide(Key& otherObject)
{
    m_TotalKeys++;
}

void Mouse::colide(Wall& otherObject) {
    UpdatePostion(m_lastPosition);
}

void Mouse::colide(Door& otherObject)
{
    if (m_TotalKeys > 0)
    {
        m_TotalKeys--;
        m_score = m_score + 2;
        m_texture.updateScore(m_score);
    }
    else
    {
        UpdatePostion(m_lastPosition);

    }
}

void Mouse::colide(DumbCat& otherObject)
{
    m_lives--;
    UpdatePostion(m_InitPosition);
    m_texture.updateLive(m_lives);


}

void Mouse::colide(Addlife& otherObject)
{
    m_lives++;
}

bool Mouse::hasCollidedWithFreeze() const {
    return m_hasCollidedWithFreeze;
}

void Mouse::resetFreezeCollision() {
    m_hasCollidedWithFreeze = false;
}

void Mouse::colide(Freeze& otherObject) {
    m_hasCollidedWithFreeze = true;
}

void Mouse::colide(Newtime& otherObject)
{
    m_time += 5;
}

int Mouse::getScore() const {
    return m_score;
}



int Mouse::getLive() const {
    return 	 m_lives;
}

int Mouse::getTime() const {
    return 	 m_time;
}


int Mouse::getCheese() const {
    return  m_counterChees;
    
}