//
//  Enemy.hpp
//  Galaga
//
//  Created by Jake Houts on 3/19/23.
//

#ifndef Enemy_hpp
#define Enemy_hpp

#include "LTexture.hpp"

class EnemyState;

class Enemy {
public:
    //Main loop functions
    virtual void handleEvent( SDL_Event &e ) = 0;
    virtual void update() = 0;
    virtual void render() = 0;
    virtual void setNextState() {}
    virtual void changeState(EnemyState *update) {}
    virtual void setTexture(LTexture *t) {}
    virtual void setAnimation(SDL_Rect &r) {}
    virtual void kill() {}
    virtual float getX() { return xPos; }
    virtual float getY() { return yPos; }
    virtual void setX(float x) { xPos = x; }
    virtual void setY(float y) { yPos = y; }

    //Make sure to call child destructors
    virtual ~Enemy() {}
    
private:
    float xPos, yPos;
};

class EnemyState {
public:
    virtual ~EnemyState() {}
    virtual void update(Enemy &enemy) {}
    
    //State transitions
    virtual void enter(Enemy &enemy) {}
    virtual void exit(Enemy &enemy) {}
};

#endif /* Enemy_hpp */
