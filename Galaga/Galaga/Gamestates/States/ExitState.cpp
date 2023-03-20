//
//  ExitState.cpp
//  Galaga
//
//  Created by Jake Houts on 3/14/23.
//

#include "../GameState.hpp"

//Hollow exit state
ExitState* ExitState::get()
{
    return &sExitState;
}

bool ExitState::enter()
{
    return true;
}
    
bool ExitState::exit()
{
    return true;
}

void ExitState::handleEvent( SDL_Event& e )
{

}

void ExitState::update()
{

}

void ExitState::render()
{

}

void ExitState::checkCollision() {
    
}

ExitState ExitState::sExitState;

ExitState::ExitState()
{

}
