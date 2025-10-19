#include "GameObject.h"

GameObject::GameObject(float x, float y, float sizeX, float sizeY) {
	m_position = sf::Vector2f(x, y);
	m_shape.setPosition(x, y);
	m_shape.setSize(sf::Vector2f(sizeX, sizeY));

}

void GameObject::render(sf::RenderWindow* picture) const
{
	picture->draw(m_shape);
}

void GameObject::setObjTexture(int objectsID) {
	m_shape.setTexture(Textures::getInstance().getObjTexture(objectsID));
}

sf::RectangleShape GameObject::getShape()
{
	return m_shape;
}

void GameObject::move(const sf::Vector2f& offset) {
	m_shape.move(offset);
}

void GameObject::SetRotation(float rotation) {
	m_shape.setRotation(rotation);
}
void GameObject::getMiddle(float sizeX, float sizeY)
{
	m_shape.setOrigin(sizeX / 2, sizeY / 2);
}

sf::Vector2f  GameObject::getPostion()
{
	return m_shape.getPosition();
}

void GameObject::UpdatePostion(sf::Vector2f lastPosition)
{
	m_shape.setPosition(lastPosition);
}


bool GameObject::intersects(const GameObject& otherObject) const {
	return m_shape.getGlobalBounds().intersects(otherObject.m_shape.getGlobalBounds());
}




