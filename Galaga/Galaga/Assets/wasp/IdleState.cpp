//
//  IdleState.cpp
//  Galaga
//
//  Created by Jake Houts on 3/20/23.
//

#include "Wasp.hpp"
#include "GameState.hpp"

//constructor
IdleState::IdleState() {
    
}

//destructor
IdleState::~IdleState() {
    
}

void IdleState::enter(Wasp &wasp) {
    
}

//handle input for a wasp
void IdleState::handleInput(Wasp &wasp, SDL_Event &e)  {
    
}

//update wasp postion
void IdleState::update(Wasp &wasp)  {
    
}

//render wasp to screen
void IdleState::render(Wasp &wasp)  {
    wasp.waspTexture->render(wasp.xPos, wasp.yPos);
}

WaspState *IdleState::checkCollision(SDL_Rect A, SDL_Rect B) {
    //something has collided with our wasp
    if(globalCheckCollision(A, B)) {
        return new DeathState();
    }
    
    //else nothing happened so no state change
    return NULL;
}
