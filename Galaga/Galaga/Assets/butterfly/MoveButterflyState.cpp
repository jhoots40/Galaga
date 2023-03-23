//
//  MoveButterflyState.cpp
//  Galaga
//
//  Created by Jake Houts on 3/22/23.
//

#include "Butterfly.hpp"
#include <math.h>

//destructor
MoveButterflyState::~MoveButterflyState() {
    
}

//enter the DeathState
void MoveButterflyState::enter(Butterfly &b) {
    printf("x: %lf, y: %lf\n", finalX, finalY);
    float startingX = b.getX();
    float startingY = b.getY();
    
    movementAngle = atan((finalY - startingY) / (finalX - startingX));
    
    printf("%lf\n", movementAngle);
    
    arrived = false;
}

//handle input for a wasp
void MoveButterflyState::handleInput(Butterfly &b, SDL_Event &e) {
    
}

//update wasp postion
void MoveButterflyState::update(Butterfly &b) {
    //x = cos(0);
    //y = sin(0);
    float newX = b.getX();
    float newY = b.getY();
    newX += cos(movementAngle) * 100 * dt * -1;
    newY += sin(movementAngle) * 100 * dt * -1;
    
    b.setX(newX);
    b.setY(newY);
    
    if((int) newX == (int) finalX && (int) newY == (int) finalY) {
        arrived = true;
    }
}

//check if enemy collides with collider
ButterflyState *MoveButterflyState::checkCollision(SDL_Rect A, SDL_Rect B) {
    if(arrived) return new IdleButterflyState();
    return NULL;
}
