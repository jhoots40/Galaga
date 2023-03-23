//
//  DeathState.cpp
//  Galaga
//
//  Created by Jake Houts on 3/22/23.
//

#include "Globals.h"
#include "DeathState.hpp"

//constructor
DeathState::DeathState() {
    
}

//destructor
DeathState::~DeathState() {
    
}

//enter the DeathState
void DeathState::enter(Enemy &enemy) {
    enemy.setX(enemy.getX() - 14);
    enemy.setY(enemy.getY() - 16);
    currentFrame = 0;
    enemy.setAnimation(enemyDeathClips[currentFrame]);
    enemy.setTexture(&enemyDeathSheet);
    startTime = SDL_GetTicks();
}

//exit the DeathState
void DeathState::exit(Enemy &enemy) {
    
}

//update wasp postion
void DeathState::update(Enemy &enemy) {
    if(SDL_GetTicks() - startTime > 50) {
        if(currentFrame < 5) {
            enemy.setAnimation(enemyDeathClips[currentFrame++]);
            startTime = SDL_GetTicks();
        }
        else {
            enemy.kill();
        }
    }
}
