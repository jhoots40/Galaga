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
    
    //set next bullet index to start of array
    nextBullet = 0;
}

//destructor
Player::~Player() {
    //never allocated playerTexture in this scope
    playerTexture = NULL;
    bullets[0] = NULL;
    bullets[1] = NULL;
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
            case SDLK_SPACE:
                if(bullets[nextBullet] == NULL) {
                    bullets[nextBullet] = new Bullet(xPos + (playerTexture->getWidth() / 2), yPos);
                    Mix_PlayChannel( -1, fireSound, 0 );
                    nextBullet = !nextBullet;
                }
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
    
    //update bullets
    for(int i = 0; i < 2; i++) {
        if(bullets[i]) {
            bullets[i]->update();
        }
    }
    
}

//render pc
void Player::render() {
    //render player
    playerTexture->render(xPos, yPos);
    
    for(int i = 0; i < 2; i++) {
        if(bullets[i]) {
            //render bullets
            bullets[i]->render();
            
            //if bullet is not on screen delete it
            if(!bullets[i]->isOnScreen()) {
                delete bullets[i];
                bullets[i] = NULL;
            }
        }
    }
    
    
}
