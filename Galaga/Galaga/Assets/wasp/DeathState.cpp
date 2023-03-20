//
//  DeathState.cpp
//  Galaga
//
//  Created by Jake Houts on 3/20/23.
//

#include "Wasp.hpp"
#include "Globals.h"

//constructor
DeathState::DeathState() {
    
}

//destructor
DeathState::~DeathState() {
    
}

void DeathState::enter(Wasp &wasp) {
    printf("Made it to the death state\n");
    wasp.waspTexture = &galagaLogo;
}

//handle input for a wasp
void DeathState::handleInput(Wasp &wasp, SDL_Event &e) {
    
}

//update wasp postion
void DeathState::update(Wasp &wasp) {
    
}

//render wasp to screen
void DeathState::render(Wasp &wasp) {
    wasp.waspTexture->render(wasp.xPos, wasp.yPos);
}

//check if enemy collides with collider
WaspState *DeathState::checkCollision(SDL_Rect A, SDL_Rect B) {
    return NULL;
}
