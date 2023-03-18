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
