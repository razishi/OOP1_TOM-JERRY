#pragma once

#include "MovingGameObject.h"
#include "Sounds.h"

class Mouse : public MovingGameObject {
public:
	Mouse(float x, float y, float size_x, float size_y, float speed, int lives);
	void updateMovement(sf::RenderWindow* target);
	void update(sf::RenderWindow* target);
	int getKeyNum() const;
	void colide(GameObject& otherObject);
	void colide(Mouse& otherObject);
	void colide(SmartCat& otherObject);
	void colide(Gift& otherObject);
	bool DeleteCat() const;
	void DeletedCat();
	void colide(Cheese& otherObject);
	void colide(Key& otherObject);
	void colide(Wall& wall); // Add this line
	void colide(Door& otherObject);
	void colide(DumbCat& otherObject);
	void colide(Addlife& otherObject);
	void colide(Freeze& otherObject);
	void colide(Newtime& otherObject);
	int getTime() const;
	int getCheese() const;
	int getScore() const;
	int getLive() const;
	
	bool hasCollidedWithFreeze() const;
	void resetFreezeCollision() ;

private:

	float m_originalSpeed;
	bool m_isCollidingWithWall = false;
	int m_lives = 3;
	sf::RectangleShape m_MouseShape;
	Textures m_texture;
	int  m_score = 0;
	int  m_time = 0;
	int  m_counterChees = 0;
	bool m_hasCollidedWithFreeze = false;
	bool m_CatDelete;

};