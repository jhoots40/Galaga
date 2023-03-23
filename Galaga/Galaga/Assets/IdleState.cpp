//
//  IdleState.cpp
//  Galaga
//
//  Created by Jake Houts on 3/22/23.
//

#include "IdleState.hpp"
#include "Globals.h"

//constructor
IdleState::IdleState() {
    
}

//destructor
IdleState::~IdleState() {
    
}

//update wasp postion
void IdleState::update(Enemy &enemy) {
    if(SDL_GetTicks() - startTime > 500) {
        if(swap) {
            enemy.setAnimation(gButterflyClips[0]);
            swap = false;
        }
        else {
            enemy.setAnimation(gButterflyClips[1]);
            swap = true;
        }
        startTime = SDL_GetTicks();
    }
}

//enter the IdleState
void IdleState::enter(Enemy &enemy) {
    startTime = SDL_GetTicks();
    currentFrame = 0;
    swap = true;
}

void IdleState::exit(Enemy &enemy) {
    
}
