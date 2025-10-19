#pragma once
#include "GameObject.h"

class MovingGameObject : public GameObject {
public:
	MovingGameObject(float x, float y, float size_x, float size_y, float speed);
	
private:
	sf::Vector2f m_startPosition;
	sf::Vector2f m_direction = sf::Vector2f(0, 0);
	static sf::Vector2f m_catPosition;
	float m_speed;

protected:
	int m_TotalKeys;
	sf::Vector2f m_lastPosition;
	sf::Vector2f m_InitPosition;
	float m_InitSizeX;
	float m_InitSizeY;
	float m_Speednes;
};
