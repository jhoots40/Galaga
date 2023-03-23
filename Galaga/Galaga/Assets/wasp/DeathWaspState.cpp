//
//  DeathWaspState.cpp
//  Galaga
//
//  Created by Jake Houts on 3/20/23.
//

#include "Wasp.hpp"
#include "Globals.h"

//constructor
DeathWaspState::DeathWaspState() {
    currentFrame = 1;
    
}

//destructor
DeathWaspState::~DeathWaspState() {
    
}

void DeathWaspState::enter(Wasp &wasp) {
    wasp.timeToDie();
    wasp.setAnimation(enemyDeathClips[0]);
    startTime = SDL_GetTicks();
}

//handle input for a wasp
void DeathWaspState::handleInput(Wasp &wasp, SDL_Event &e) {
}

//update wasp postion
void DeathWaspState::update(Wasp &wasp) {
    if(SDL_GetTicks() - startTime > 50) {
        if(currentFrame < 5) {
            wasp.setAnimation(enemyDeathClips[currentFrame++]);
            startTime = SDL_GetTicks();
        }
        else {
            wasp.setAlive(false);
        }
    }
}

//check if enemy collides with collider
WaspState *DeathWaspState::checkCollision(SDL_Rect A, SDL_Rect B) {
    return NULL;
}
