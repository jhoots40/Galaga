//
//  IdleWaspState.cpp
//  Galaga
//
//  Created by Jake Houts on 3/20/23.
//

#include "Wasp.hpp"
#include "GameState.hpp"
#include "Globals.h"

//constructor
IdleWaspState::IdleWaspState() {

}

//destructor
IdleWaspState::~IdleWaspState() {
}

void IdleWaspState::enter(Wasp &wasp) {
    startTime = SDL_GetTicks();
    currentFrame = 0;
    swap = true;
}

//handle input for a wasp
void IdleWaspState::handleInput(Wasp &wasp, SDL_Event &e)  {
    
}

//update wasp postion
void IdleWaspState::update(Wasp &wasp)  {
    if(SDL_GetTicks() - startTime > 500) {
        if(swap) {
            wasp.setAnimation(gWaspClips[0]);
            swap = false;
        }
        else {
            wasp.setAnimation(gWaspClips[1]);
            swap = true;
        }
        startTime = SDL_GetTicks();
    }
}

WaspState *IdleWaspState::checkCollision(SDL_Rect A, SDL_Rect B) {
    //something has collided with our wasp
    if(globalCheckCollision(A, B)) {
        return new DeathWaspState();
    }
    
    //else nothing happened so no state change
    return NULL;
}
