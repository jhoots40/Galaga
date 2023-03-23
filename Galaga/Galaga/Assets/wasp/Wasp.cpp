//
//  Wasp.cpp
//  Galaga
//
//  Created by Jake Houts on 3/19/23.
//

#include "Wasp.hpp"

//constructor
Wasp::Wasp(int x, int y) {
    xPos = x;
    yPos = y;
    waspTexture = &gWaspSheet;
    animation = &gWaspClips[0];
    
    waspCollider.x = xPos + 4;
    waspCollider.y = yPos + 6;
    waspCollider.w = 26;
    waspCollider.h = 20;
    
    waspState = new IdleWaspState();
    alive = true;
}

//destructor
Wasp::~Wasp() {
    waspTexture = NULL;
    animation = NULL;
    delete waspState;
    waspState = NULL;
}

//handle input
void Wasp::handleEvent(SDL_Event &e) {
    //printf("handling input");
    waspState->handleInput(*this, e);
}

//update position
void Wasp::update() {
    waspState->update(*this);
}


//render pc
void Wasp::render() {
    waspTexture->render(xPos, yPos, animation);
}

bool Wasp::checkCollision(SDL_Rect collider) {
    WaspState *state = waspState->checkCollision(waspCollider, collider);
    if(state != NULL) {
        delete waspState;
        waspState = state;
        waspState->enter(*this);
        return true;
    }
    return false;
}
