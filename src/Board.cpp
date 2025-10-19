#include "Board.h"

Board::Board() 
{}

void Board::render(sf::RenderWindow* target) {
   
    for (size_t i = 0; i < m_staticObjects.size(); i++) {
        (*m_staticObjects[i]).render(target);
    }
 
    for (size_t i = 0; i < m_MovingObjects.size(); i++) {
        (*m_MovingObjects[i]).render(target);
    }
}

int  Board::GetCheese() const {
    return m_CounterCheese;
    
}



bool Board::loadMap(int Numlev) {
    m_level = Numlev; // Update the current level
    m_CounterCheese = 0;
    m_level++;
    clearObjects();
    std::string fileName = "Level" + std::to_string(Numlev) + ".txt";
    m_fileLev.open(fileName);
    int NUM_OF_CATS = 0;

    if (!m_fileLev) {
        return false;
    }
    m_fileLev >> m_rows >> m_cols;
    int scale = 800 / std::max(m_rows, m_cols);
    char c;
 
    for (int i = 0; i < m_rows; i++) {
        c = char(m_fileLev.get()); 
        for (int j = 0; j < m_cols; j++) {
            c = char(m_fileLev.get());
            if (c != ' ') {
                switch (c) {
                case '%':
                    m_MovingObjects.push_back(std::make_unique<Mouse>(
                        float(j * scale), float(i * scale + TOPWINDOW),
                        float(scale * PERCENT), float(scale * PERCENT),
                        MOUSESPEED , m_lives));
                    m_mouse = dynamic_cast<Mouse*>(m_MovingObjects.back().get());

                    break;

                case '^': 
                    NUM_OF_CATS++;
                    if (isPrime(NUM_OF_CATS))
                    {

                        m_MovingObjects.push_back(std::make_unique<DumbCat>(
                            float(j * scale), float(i * scale + TOPWINDOW),
                            float(scale * PERCENT), float(scale * PERCENT),
                            CATSPEED));
                    }
                    else
                    {
                        m_MovingObjects.push_back(std::make_unique<SmartCat>(
                            float(j * scale), float(i * scale + TOPWINDOW),
                            float(scale * PERCENT), float(scale * PERCENT),
                            CATSPEED));
                    }

                    break;

                case '#': 
                    m_staticObjects.push_back(std::make_unique<Wall>(
                        float(j * scale), float(i * scale + TOPWINDOW), scale,
                        scale));
                    break;
                case 'D':
                    m_staticObjects.push_back(std::make_unique<Door>(
                        float(j * scale), float(i * scale + TOPWINDOW), scale,
                        scale));
                    break;
                case 'F': 
                    m_staticObjects.push_back(std::make_unique<Key>(
                        float(j * scale), float(i * scale + TOPWINDOW), scale,
                        scale));
                    break;
                case '*': 
                    m_staticObjects.push_back(std::make_unique<Cheese>(
                        float(j * scale), float(i * scale + TOPWINDOW), scale,
                        scale));
                    m_CounterCheese++;
                    break;

                case '$': 
                    m_staticObjects.push_back(std::make_unique<Gift>(
                        float(j * scale), float(i * scale + TOPWINDOW), scale,

                        scale));
                    break;

                case '+':
                    m_staticObjects.push_back(std::make_unique<Addlife>(
                        float(j * scale), float(i * scale + TOPWINDOW), scale,
                        scale));
                    break;

                case 'e':
                    m_staticObjects.push_back(std::make_unique<Newtime>(
                        float(j * scale), float(i * scale + TOPWINDOW), scale,
                        scale));
                    break;
                case 's':
                    m_staticObjects.push_back(std::make_unique<Freeze>(
                        float(j * scale), float(i * scale + TOPWINDOW), scale,
                        scale));
                    break;
             
                
                }
            }
        }
    }

    m_fileLev.close();
    return true;
}



void Board::update(sf::RenderWindow* target)
{
    m_mouse->update(target);

    if (m_mouse->hasCollidedWithFreeze()) {
        startFreezeEffect();
        m_mouse->resetFreezeCollision();
    }

    if (m_catsFrozen && m_freezeTimer.getElapsedTime().asSeconds() >= 5) {
        m_catsFrozen = false;
    }

    // Update all DumbCat and SmartCat objects and check for collisions
    for (auto& movingObject : m_MovingObjects) {


        // Check for collision with the Mouse
        if (movingObject.get() != m_mouse && movingObject->intersects(*m_mouse)) {
            movingObject->colide(*m_mouse);
            m_mouse->colide(*movingObject);
        }

        DumbCat* dumbCat = dynamic_cast<DumbCat*>(movingObject.get());
        SmartCat* smartCat = dynamic_cast<SmartCat*>(movingObject.get());

        if (!m_catsFrozen) {
            if (dumbCat) {
                dumbCat->update(target);
            }
            else if (smartCat) {
                smartCat->update(target, m_mouse->getPostion());
            }
        }

        // Check for collisions with other moving objects
        for (auto& otherMovingObject : m_MovingObjects) {
            if (movingObject.get() != otherMovingObject.get() && movingObject->intersects(*otherMovingObject)) {
                movingObject->colide(*otherMovingObject);
                otherMovingObject->colide(*movingObject);
            }
        }

        // Check for collisions with static objects
        for (const auto& staticObject : m_staticObjects) {
            if (movingObject->intersects(*staticObject)) {
                movingObject->colide(*staticObject);

                Wall* wall = dynamic_cast<Wall*>(staticObject.get());
                Door* door = dynamic_cast<Door*>(staticObject.get());
                Key* key = dynamic_cast<Key*>(staticObject.get());
                 Addlife* addlife = dynamic_cast<Addlife*>(staticObject.get());
                 Gift* gift = dynamic_cast<Gift*>(staticObject.get());
                 Newtime* newtime = dynamic_cast<Newtime*>(staticObject.get());
                 Cheese* chesee = dynamic_cast<Cheese*>(staticObject.get());
                 Freeze* freeze = dynamic_cast<Freeze*>(staticObject.get());
                 if (wall) {
                    movingObject->colide(*wall);
                }
                else if (door) {
                    door->KeyCount(m_mouse->getKeyNum());
                    movingObject->colide(*door);
                }
                else if (key) {
                    movingObject->colide(*key);
                }
                else if (addlife) {
                    movingObject->colide(*addlife);
                 }

                else if (gift) {
                        movingObject->colide(*gift);
                   }

                else if (newtime) {
                    movingObject->colide(*newtime);
                }
                else if (chesee) {
                     

                     movingObject->colide(*chesee);
                 }
                else if (freeze)
                 {
                     movingObject->colide(*freeze);

                 }
            }
        }
    }
    if (m_mouse->DeleteCat()) {
        removeCat();
    }


    // Remove static objects marked for deletion
    auto it = m_staticObjects.begin();
    while (it != m_staticObjects.end()) {
        if ((*it)->isMarkedForDeletion()) {
            it = m_staticObjects.erase(it);
        }
        else {
            ++it;
        }
    }
}

void Board::clearObjects() {

    m_MovingObjects.clear();
    m_staticObjects.clear();

}


bool Board::isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= std::sqrt(n); ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

Mouse* Board::getMouse() const
{
    return m_mouse;
}


void Board::removeCat() {
    for (auto it = m_MovingObjects.begin(); it != m_MovingObjects.end(); ++it) {
        if (dynamic_cast<SmartCat*>(it->get()) || dynamic_cast<DumbCat*>(it->get())) {
            m_MovingObjects.erase(it);
            m_mouse->DeletedCat();
            break; // Remove only one cat
        }
    }
}

void Board::startFreezeEffect() {
    m_catsFrozen = true;
    m_freezeTimer.restart();
}

bool Board::isCatsFrozen() const {
    return m_catsFrozen;
}


int Board::getLevel() const
{
    return m_level;
}