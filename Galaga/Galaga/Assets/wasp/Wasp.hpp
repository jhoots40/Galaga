//
//  Wasp.hpp
//  Galaga
//
//  Created by Jake Houts on 3/20/23.
//

#ifndef Wasp_hpp
#define Wasp_hpp

#include "Enemy.hpp"

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
    
    //get collision box
    SDL_Rect getCollider() { return waspCollider; }
    
    //texture of the player
    LTexture *waspTexture;
    
    //position of the player
    float xPos, yPos;
    
private:
    
    //Enemy collision box
    SDL_Rect waspCollider;
    
    //current state of wasp
    WaspState *waspState;

};

class WaspState {
public:
    virtual ~WaspState() {}
    virtual void enter(Wasp &wasp) {}
    virtual void handleInput(Wasp &wasp, SDL_Event &e) {}
    virtual void update(Wasp &wasp) {}
    virtual void render(Wasp &wasp) {}
    virtual WaspState *checkCollision(SDL_Rect A, SDL_Rect B) { return NULL; }
};

class IdleState : public WaspState {
public:
    //constructor
    IdleState();
    
    //destructor
    ~IdleState();
    
    //handle input for a wasp
    void handleInput(Wasp &wasp, SDL_Event &e);
    
    //update wasp postion
    void update(Wasp &wasp);
    
    //render wasp to screen
    void render(Wasp &wasp);
    
    //enter the IdleState
    void enter(Wasp &wasp);
    
    //check if enemy collides with collider
    WaspState *checkCollision(SDL_Rect A, SDL_Rect B);
};

class DeathState : public WaspState {
public:
    //constructor
    DeathState();
    
    //destructor
    ~DeathState();
    
    //enter the DeathState
    void enter(Wasp &wasp);
    
    //handle input for a wasp
    void handleInput(Wasp &wasp, SDL_Event &e);
    
    //update wasp postion
    void update(Wasp &wasp);
    
    //render wasp to screen
    void render(Wasp &wasp);
    
    //check if enemy collides with collider
    WaspState *checkCollision(SDL_Rect A, SDL_Rect B);
};
#endif /* Wasp_hpp */
