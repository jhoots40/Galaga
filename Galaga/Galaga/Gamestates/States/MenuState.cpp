//
//  MenuState.cpp
//  Galaga
//
//  Created by Jake Houts on 3/14/23.
//

#include "../GameState.hpp"
#include "../../Globals.h"

MenuState* MenuState::get()
{
    return &sMenuState;
}

bool MenuState::enter()
{
    //loading success flag
    bool success = true;
    
    return success;
}
    
bool MenuState::exit()
{
    return true;
}

void MenuState::handleEvent( SDL_Event& e )
{

}

void MenuState::update()
{

}

void MenuState::render()
{

}

MenuState MenuState::sMenuState;

MenuState::MenuState()
{

}
