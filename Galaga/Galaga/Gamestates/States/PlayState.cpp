//
//  PlayState.cpp
//  Galaga
//
//  Created by Jake Houts on 3/17/23.
//

#include "GameState.hpp"

#include "../../Globals.h"

PlayState* PlayState::get()
{
    return &sPlayState;
}

bool PlayState::enter()
{
    //loading success flag
    bool success = true;
    
    player = new Player();
    
    //play sound
    Mix_PlayChannel( -1, introMusic, 0 );
    
    //declare a function pointer to our callback
    void (*done)(int) = &catchChannelDone;
    Mix_ChannelFinished(done);
    
    //done with pointer so set to null;
    done = NULL;
    
    return success;
}
    
bool PlayState::exit()
{
    //free player
    delete player;
    player = NULL;
    
    return true;
}

void PlayState::handleEvent( SDL_Event& e )
{
    player->handleEvent(e);
}

void PlayState::update()
{
    player->update();
}

void PlayState::render()
{
    player->render();
}

PlayState PlayState::sPlayState;

PlayState::PlayState()
{
    
}

void PlayState::catchChannelDone(int chan)
{
    setNextState( MenuState::get() );
}
