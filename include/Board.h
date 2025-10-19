#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include "Globals.h"
#include "Cheese.h"
#include "SmartCat.h"
#include "DumbCat.h"
#include "Door.h"
#include "Gift.h"
#include "Key.h"
#include "Mouse.h"
#include "Wall.h"
#include "Addlife.h"
#include "Freeze.h"
#include "Newtime.h"



class Board {
public:
	Board();
	void render(sf::RenderWindow* target);
	bool loadMap(int levelNum);
	void update(sf::RenderWindow* target);
	Mouse* getMouse() const;
	int getLevel() const;
	int  GetCheese() const;
	void removeCat();
	void startFreezeEffect();
	bool isCatsFrozen() const;


private:
	std::ifstream m_fileLev;
	std::vector<std::unique_ptr<MovingGameObject>> m_MovingObjects;
	std::vector<std::unique_ptr<StaticGameObject>> m_staticObjects;
	int m_rows = 0, m_cols = 0;
	void clearObjects();
	int m_lives = 3;
	int m_level = 0;
	int m_CounterCheese = 0;
	Mouse* m_mouse;
	DumbCat* m_DumbiCat;
	bool isPrime(int n);
	bool m_catsFrozen = false;
	sf::Clock m_freezeTimer;




};
