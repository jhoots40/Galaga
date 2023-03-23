//
//  Wasp.hpp
//  Galaga
//
//  Created by Jake Houts on 3/20/23.
//

#ifndef Wasp_hpp
#define Wasp_hpp

#include "Enemy.hpp"
#include "Globals.h"

class WaspState;

class Wasp : public Enemy {
public:
    //constructor
    Wasp(int x, int y);
    
    //destructor
    ~Wasp();
    
    //handle input
    void handleEvent(SDL_Event &e);
    
    //update position
    void update();
    
    //render pc
    void render();
    
    //check collision with collider
    bool checkCollision(SDL_Rect collider);
    
    //set the enemy to its next state
    virtual void setNextState() {}
    
    //update the state if needed
    virtual void changeState(EnemyState *update) {}
    
    //change to death animation
    void timeToDie() { waspTexture = &enemyDeathSheet; xPos -= 14; yPos -= 16; }
    
    //get collision box
    SDL_Rect getCollider() { return waspCollider; }
    
    //getters and setters for position
    float getX() { return xPos; }
    float getY() { return yPos; }
    void setX(float x) { xPos = x; }
    void setY(float x) { xPos = x; }
    
    bool isAlive() { return alive; }
    void setAlive(bool a) { alive = a; }
    //
    void setAnimation(SDL_Rect &r) { animation = &r; }
    
private:
    //texture of the player
    LTexture *waspTexture;
    
    //Enemy collision box
    SDL_Rect waspCollider;
    
    //current state of wasp
    WaspState *waspState;
    
    //current animation from sprite sheet
    SDL_Rect *animation;
    
    //position of the player
    float xPos, yPos;
    
    //flag for if the enemy should be cleaned up
    bool alive;

};

class WaspState {
public:
    virtual ~WaspState() {}
    virtual void enter(Wasp &wasp) {}
    virtual void handleInput(Wasp &wasp, SDL_Event &e) {}
    virtual void update(Wasp &wasp) {}
    virtual WaspState *checkCollision(SDL_Rect A, SDL_Rect B) { return NULL; }
};

class IdleWaspState : public WaspState {
public:
    //constructor
    IdleWaspState();
    
    //destructor
    ~IdleWaspState();
    
    //handle input for a wasp
    void handleInput(Wasp &wasp, SDL_Event &e);
    
    //update wasp postion
    void update(Wasp &wasp);
    
    //enter the IdleState
    void enter(Wasp &wasp);
    
    //check if enemy collides with collider
    WaspState *checkCollision(SDL_Rect A, SDL_Rect B);
    
private:
    //time when the state starts
    Uint32 startTime;
    
    //amount of frames we play
    int currentFrame;
    
    //
    bool swap;
};

class DeathWaspState : public WaspState {
public:
    //constructor
    DeathWaspState();
    
    //destructor
    ~DeathWaspState();
    
    //enter the DeathState
    void enter(Wasp &wasp);
    
    //handle input for a wasp
    void handleInput(Wasp &wasp, SDL_Event &e);
    
    //update wasp postion
    void update(Wasp &wasp);
    
    //check if enemy collides with collider
    WaspState *checkCollision(SDL_Rect A, SDL_Rect B);
    
private:
    //time when the state starts
    Uint32 startTime;
    
    //amount of frames we play
    int currentFrame;
};
#endif /* Wasp_hpp */
