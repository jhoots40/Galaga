//
//  Player.cpp
//  Galaga
//
//  Created by Jake Houts on 3/17/23.
//

#include "Player.hpp"
#include "Constants.h"
#include "Globals.h"

//constructor
Player::Player() {
    xPos = STARTING_XPOS;
    yPos = STARTING_YPOS;
    playerTexture = &playerShip;
    xVel = 0;
}

//destructor
Player::~Player() {
    //never allocated playerTexture in this scope
    playerTexture = NULL;
}

//handle input
void Player::handleEvent(SDL_Event &e) {
    
}

//update position
void Player::update() {
}

//render pc
void Player::render() {
    playerTexture->render(xPos, yPos);
}
