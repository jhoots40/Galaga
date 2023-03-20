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
    //set starting position and velocity
    xPos = STARTING_XPOS;
    yPos = STARTING_YPOS;
    xVel = 0;
    
    //set player texture;
    playerTexture = &playerShip;
    
    //set collision box
    playerCollider.x = xPos;
    playerCollider.y = yPos;
    playerCollider.w = playerShip.getWidth();
    playerCollider.h = playerShip.getHeight();
}

//destructor
Player::~Player() {
    //never allocated playerTexture in this scope
    playerTexture = NULL;
}

//handle input
void Player::handleEvent(SDL_Event &e) {
    //if a key is pressed down
    if(e.type == SDL_KEYDOWN && e.key.repeat == 0)
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_RIGHT: xVel += PLAYER_VEL; break;
            case SDLK_LEFT: xVel -= PLAYER_VEL; break;
        }
    }
    
    //if a key is released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_RIGHT: xVel -= PLAYER_VEL; break;
            case SDLK_LEFT: xVel += PLAYER_VEL; break;
        }
    }
}
    
//update position
void Player::update() {
    //update player position
    xPos += (xVel * dt);
    if(xPos < 0 || xPos + playerTexture->getWidth() > SCREEN_WIDTH) {
        xPos -= (xVel * dt);
    }
    
    //update player collision box
    playerCollider.x = xPos;
}

//render pc
void Player::render() {
    //render player
    playerTexture->render(xPos, yPos);
}
