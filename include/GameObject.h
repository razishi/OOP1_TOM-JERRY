#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Textures.h"
#include "Globals.h"
#include "Location.h"
class SmartCat;
class Door;
class Gift;
class Key;
class MovingGameObject;
class Mouse;
class StaticGameObject;
class Cheese;
class Wall;
class Addlife;
class DumbCat;
class Freeze;
class Newtime;


class GameObject {
public:
    GameObject(float x, float y, float size_x, float size_y);
    void render(sf::RenderWindow* picture) const;
    virtual ~GameObject() = default;
    void setObjTexture(int objectsID);
    sf::RectangleShape getShape();
    void move(const sf::Vector2f& offset);
    void SetRotation(float rotation);
    void getMiddle(float sizeX, float sizeY);
    sf::Vector2f  getPostion();
    void UpdatePostion(sf::Vector2f lastPosition);
    bool intersects(const GameObject& otherObject) const;

    void markForDeletion() { m_isMarkedForDeletion = true; }
    bool isMarkedForDeletion() const { return m_isMarkedForDeletion; }

    virtual void colide(GameObject& otherObject) = 0;
    virtual void colide(Mouse& otherObject) = 0;
    virtual void colide(SmartCat& otherObject) = 0;
    virtual void colide(Gift& otherObject) = 0;
    virtual void colide(Cheese& otherObject) = 0;
    virtual void colide(Key& otherObject) = 0;
    virtual void colide(Wall& wall) = 0; // Add this line
    virtual void colide(Door& otherObject) = 0;
    virtual void colide(DumbCat& otherObject) = 0;
    virtual void colide(Addlife& otherObject) = 0;
    virtual void colide(Freeze& otherObject) = 0;
    virtual void colide(Newtime& otherObject) = 0;



private:
    sf::Vector2f m_position;
    sf::Texture m_texture;
    sf::RectangleShape m_shape;
    bool m_isMarkedForDeletion = false;

};