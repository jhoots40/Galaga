//
//  IdleButterflyState.cpp
//  Galaga
//
//  Created by Jake Houts on 3/20/23.
//

#include "Butterfly.hpp"
#include "GameState.hpp"

//constructor
IdleButterflyState::IdleButterflyState() {

}

//destructor
IdleButterflyState::~IdleButterflyState() {
    
}

void IdleButterflyState::enter(Butterfly &b) {
    startTime = SDL_GetTicks();
    currentFrame = 0;
    swap = true;
}

//handle input for a wasp
void IdleButterflyState::handleInput(Butterfly &b, SDL_Event &e)  {
    
}

//update wasp postion
void IdleButterflyState::update(Butterfly &b)  {
    if(SDL_GetTicks() - startTime > 500) {
        if(swap) {
            b.setAnimation(gButterflyClips[0]);
            swap = false;
        }
        else {
            b.setAnimation(gButterflyClips[1]);
            swap = true;
        }
        startTime = SDL_GetTicks();
    }
}

ButterflyState *IdleButterflyState::checkCollision(SDL_Rect A, SDL_Rect B) {
    //something has collided with our wasp
    if(globalCheckCollision(A, B)) {
        return new MoveButterflyState(0.0f, 0.0f);
    }
    
    //else nothing happened so no state change
    return NULL;
}
