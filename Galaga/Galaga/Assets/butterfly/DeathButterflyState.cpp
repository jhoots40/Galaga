//
//  DeathButterflyState.cpp
//  Galaga
//
//  Created by Jake Houts on 3/21/23.
//

#include "Butterfly.hpp"

//constructor
DeathButterflyState::DeathButterflyState() {
    currentFrame = 1;
    
}

//destructor
DeathButterflyState::~DeathButterflyState() {
    
}

void DeathButterflyState::enter(Butterfly &b) {
    b.timeToDie();
    b.setAnimation(enemyDeathClips[0]);
    startTime = SDL_GetTicks();
}

//handle input for a wasp
void DeathButterflyState::handleInput(Butterfly &b, SDL_Event &e) {
}

//update wasp postion
void DeathButterflyState::update(Butterfly &b) {
    if(SDL_GetTicks() - startTime > 50) {
        if(currentFrame < 5) {
            b.setAnimation(enemyDeathClips[currentFrame++]);
            startTime = SDL_GetTicks();
        }
        else {
            b.setAlive(false);
        }
    }
}

//check if enemy collides with collider
ButterflyState *DeathButterflyState::checkCollision(SDL_Rect A, SDL_Rect B) {
    return NULL;
}
