//
//  Butterfly.hpp
//  Galaga
//
//  Created by Jake Houts on 3/20/23.
//

#ifndef Butterfly_hpp
#define Butterfly_hpp

#include "Enemy.hpp"
#include "Globals.h"

/*
 Butterfly state defines what state the Butterfly is in. Different state will point me to different handling.
 */
class ButterflyState;

class Butterfly : public Enemy {
public:
    //constructor
    Butterfly(int x, int y);
    
    //destructor
    ~Butterfly();
    
    //handle input
    void handleEvent(SDL_Event &e);
    
    //update position
    void update();
    
    //render pc
    void render();
    
    //set the enemy to its next state
    void setNextState(EnemyState *newState);
    
    //update the state if needed
    void changeState();
    
    void kill() { alive = false; }
    
    //check collision with collider
    bool checkCollision(SDL_Rect collider);
    
    //change to death animation
    void timeToDie() { butterflyTexture = &enemyDeathSheet; }
    
    //get and set collision box
    SDL_Rect getCollider() { return butterflyCollider; }
    void setCollider(SDL_Rect r) { butterflyCollider = r; }
    
    //getters and setters for position
    float getX() { return xPos; }
    float getY() { return yPos; }
    void setX(float x) { xPos = x; }
    void setY(float y) { yPos = y; }
    
    bool isAlive() { return alive; }
    void setAlive(bool a) { alive = a; }
    //
    void setAnimation(SDL_Rect &r) { animation = &r; }
    void setTexture(LTexture *t) { butterflyTexture = t; }
    
    void changeState(ButterflyState *b);
    
private:
    //texture of the player
    LTexture *butterflyTexture;
    
    //Enemy collision box
    SDL_Rect butterflyCollider;
    
    //current state of wasp
    ButterflyState *butterflyState;
    
    //current animation from sprite sheet
    SDL_Rect *animation;
    
    //position of the player
    float xPos, yPos;
    
    //flag for if the enemy should be cleaned up
    bool alive;
    
    //enemy current state and next state pointers
    EnemyState *currentEnemyState;
    EnemyState *nextEnemyState;
};

class ButterflyState {
public:
    virtual ~ButterflyState() {}
    virtual void enter(Butterfly &b) {}
    virtual void handleInput(Butterfly &b, SDL_Event &e) {}
    virtual void update(Butterfly &b) {}
    virtual ButterflyState *checkCollision(SDL_Rect A, SDL_Rect B) { return NULL; }
};

class IdleButterflyState : public ButterflyState {
public:
    //constructor
    IdleButterflyState();
    
    //destructor
    ~IdleButterflyState();
    
    //handle input for a wasp
    void handleInput(Butterfly &b, SDL_Event &e);
    
    //update wasp postion
    void update(Butterfly &b);
    
    //enter the IdleState
    void enter(Butterfly &b);
    
    //check if enemy collides with collider
    ButterflyState *checkCollision(SDL_Rect A, SDL_Rect B);
    
private:
    //time when the state starts
    Uint32 startTime;
    
    //amount of frames we play
    int currentFrame;
    
    //
    bool swap;
};

class DeathButterflyState : public ButterflyState {
public:
    //constructor
    DeathButterflyState();
    
    //destructor
    ~DeathButterflyState();
    
    //enter the DeathState
    void enter(Butterfly &b);
    
    //handle input for a wasp
    void handleInput(Butterfly &b, SDL_Event &e);
    
    //update wasp postion
    void update(Butterfly &b);
    
    //check if enemy collides with collider
    ButterflyState *checkCollision(SDL_Rect A, SDL_Rect B);
    
private:
    //time when the state starts
    Uint32 startTime;
    
    //amount of frames we play
    int currentFrame;
};

class MoveButterflyState : public ButterflyState {
public:
    //constructor
    MoveButterflyState(float x, float y) : finalX(x), finalY(y) {}
    
    //destructor
    ~MoveButterflyState();
    
    //enter the DeathState
    void enter(Butterfly &b);
    
    //handle input for a wasp
    void handleInput(Butterfly &b, SDL_Event &e);
    
    //update wasp postion
    void update(Butterfly &b);
    
    //check if enemy collides with collider
    ButterflyState *checkCollision(SDL_Rect A, SDL_Rect B);
    
private:
    
    //time when the state starts
    Uint32 startTime;
    
    //amount of frames we play
    int currentFrame;
    
    //final position of where you want the butterfly
    float finalX, finalY;
    
    //movement angle
    float movementAngle;
    
    //flag to see if the enemy arrives
    bool arrived;
};


#endif /* Butterfly_hpp */
