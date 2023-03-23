//
//  GameState.hpp
//  Galaga
//
//  Created by Jake Houts on 3/14/23.
//

#ifndef GameState_hpp
#define GameState_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include "../Assets/LTexture.hpp"
#include "Player.hpp"
#include "Wasp.hpp"
#include "Butterfly.hpp"

/*
------------------------------------------------------------
GameState (Bass Class)
------------------------------------------------------------
*/
class GameState
{
public:
    static Player player;
    
    //State transitions
    virtual bool enter() = 0;
    virtual bool exit() = 0;

    //Main loop functions
    virtual void handleEvent( SDL_Event &e ) = 0;
    virtual void update() = 0;
    virtual void render() = 0;
    virtual void checkCollision() = 0;

    //Make sure to call child destructors
    virtual ~GameState(){};
};


/*
------------------------------------------------------------
MenuState (Main Menu Screen)
------------------------------------------------------------
*/
class MenuState : public GameState {
public:
    //static accessor
    static MenuState *get();
    
    //Transitions
    bool enter();
    bool exit();
    
    //Main loop functions
    void handleEvent( SDL_Event& e );
    void update();
    void render();
    void checkCollision();

private:
    //Static instance
    static MenuState sMenuState;

    //Private constructor
    MenuState();
    
    LTexture *logo;
    LTexture *player1;
    LTexture *player2;
    LTexture *marker;
    
    int scrollingOffset;
    bool select;
};


/*
------------------------------------------------------------
StartState (Playing the Starting Music)
------------------------------------------------------------
*/
class StartState : public GameState {
public:
    //static accessor
    static StartState *get();
    
    //Transitions
    bool enter();
    bool exit();
    
    //Main loop functions
    void handleEvent( SDL_Event& e );
    void update();
    void render();
    void checkCollision();

private:
    //Static instance
    static StartState sStartState;

    //Private constructor
    StartState();
    
    //time when entering play state
    float startTime;
    
    //LTexture for ready
    LTexture *ready;
};

/*
------------------------------------------------------------
StartState (Playing the Starting Music)
------------------------------------------------------------
*/
class LevelOne : public GameState {
public:
    //static accessor
    static LevelOne *get();
    
    //Transitions
    bool enter();
    bool exit();
    
    //Main loop functions
    void handleEvent( SDL_Event& e );
    void update();
    void render();
    void checkCollision();
    static void cleanUp();
    
private:
    //Static instance
    static LevelOne sLevelOne;

    //Private constructor
    LevelOne();
    
    //time when entering play state
    float startTime;
    
    //pointer to our static player
    Player *player;
    
    //pointers to bullets
    Bullet *playerBullets[2];
    
    //current index of next bullet
    int nextBullet;
    
    //enemy
    Wasp *wasps[5];
    Butterfly *b[5];
    Butterfly *butterflies[5];
    
};



/*
------------------------------------------------------------
ExitState (Hollow Class)
------------------------------------------------------------
*/
class ExitState : public GameState {
public:
    //Static accessor
    static ExitState *get();

    //Transitions
    bool enter();
    bool exit();

    //Main loop functions
    void handleEvent( SDL_Event &e );
    void update();
    void render();
    void checkCollision();

private:
    //Static instance
    static ExitState sExitState;

    //Private constructor
    ExitState();
};


extern GameState *nextState;
extern GameState *currentState;

void setNextState( GameState* newState );
void changeState();
bool globalCheckCollision(SDL_Rect A, SDL_Rect B);

#endif /* GameState_hpp */
