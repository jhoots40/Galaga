//
//  Butterfly.cpp
//  Galaga
//
//  Created by Jake Houts on 3/20/23.
//

#include "Butterfly.hpp"
#include "IdleState.hpp"

//constructor
Butterfly::Butterfly(int x, int y) {
    xPos = x;
    yPos = y;
    butterflyTexture = &gButterflySheet;
    animation = &gButterflyClips[0];
    
    butterflyCollider.x = xPos + 4;
    butterflyCollider.y = yPos + 6;
    butterflyCollider.w = 26;
    butterflyCollider.h = 20;
    
    currentEnemyState = new IdleState();
    nextEnemyState = NULL;
    alive = true;
    
    butterflyState = new IdleButterflyState();
    
    
}

//destructor
Butterfly::~Butterfly() {
    butterflyTexture = NULL;
    animation = NULL;
    delete butterflyState;
    butterflyState = NULL;
}

//handle input
void Butterfly::handleEvent(SDL_Event &e) {
}

//update position
void Butterfly::update() {
    currentEnemyState->update(*this);
}


//render pc
void Butterfly::render() {
    butterflyTexture->render(xPos, yPos, animation);
}

bool Butterfly::checkCollision(SDL_Rect collider) {
    ButterflyState *state = butterflyState->checkCollision(butterflyCollider, collider);
    if(state != NULL) {
        delete butterflyState;
        butterflyState = state;
        butterflyState->enter(*this);
        return true;
    }
    return false;
}


void Butterfly::setNextState(EnemyState *newState)
{
    nextEnemyState = newState;
}

void Butterfly::changeState()
{
    //If the state needs to be changed
    if( nextEnemyState != NULL )
    {
        currentEnemyState->exit(*this);
        nextEnemyState->enter(*this);

        //Change the current state ID
        delete currentEnemyState;
        currentEnemyState = nextEnemyState;
        nextEnemyState = NULL;
    }
}
