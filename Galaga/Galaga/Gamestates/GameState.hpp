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

/*
------------------------------------------------------------
GameState (Bass Class)
------------------------------------------------------------
*/
class GameState
{
public:
    //State transitions
    virtual bool enter() = 0;
    virtual bool exit() = 0;

    //Main loop functions
    virtual void handleEvent( SDL_Event &e ) = 0;
    virtual void update() = 0;
    virtual void render() = 0;

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
PlayState (Playing the Game)
------------------------------------------------------------
*/
class PlayState : public GameState {
public:
    //static accessor
    static PlayState *get();
    
    static void catchChannelDone(int chan);
    
    //Transitions
    bool enter();
    bool exit();
    
    //Main loop functions
    void handleEvent( SDL_Event& e );
    void update();
    void render();
    
    int finishMusic();

private:
    //Static instance
    static PlayState sPlayState;

    //Private constructor
    PlayState();
    
    //Main Player
    Player *player;
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

#endif /* GameState_hpp */
