//
//  PlayState.cpp
//  Galaga
//
//  Created by Jake Houts on 3/17/23.
//

#include "GameState.hpp"
#include "Constants.h"
#include "../../Globals.h"

StartState* StartState::get()
{
    return &sStartState;
}

bool StartState::enter()
{
    //loading success flag
    bool success = true;
    
    //create player
    
    //play sound
    Mix_PlayChannel( -1, introMusic, 0 );
    
    //load text to screen
    ready = new LTexture();
    SDL_Color red = {255, 0, 0};
    ready->loadFromRenderedText("START", red);
    
    //declare a function pointer to our callback
    //void (*done)(int) = &catchChannelDone;
    //Mix_ChannelFinished(done);
    
    //done with pointer so set to null;
    //done = NULL;
    
    //set startTime
    startTime = pastCount;
    
    return success;
}
    
bool StartState::exit()
{
    //free player
    //player = NULL;
    
    return true;
}

void StartState::handleEvent( SDL_Event& e )
{
    //player->handleEvent(e);
    
}

void StartState::update()
{
    //player->update();
    if(SDL_GetTicks() - startTime > 7000) {
        setNextState( LevelOne::get() );
    }
}

void StartState::render()
{
    //player->render();
    //if(currentLevel) currentLevel->render();
    ready->render((SCREEN_WIDTH - ready->getWidth()) / 2, (SCREEN_HEIGHT - ready->getHeight()) / 2);
}

void StartState::checkCollision() {
    
}

StartState StartState::sStartState;

StartState::StartState()
{
    
}
