//
//  LevelOne.cpp
//  Galaga
//
//  Created by Jake Houts on 3/19/23.
//

#include "GameState.hpp"
#include "Constants.h"
#include "../../Globals.h"
#include "Enemy.hpp"

LevelOne* LevelOne::get()
{
    return &sLevelOne;
}

bool LevelOne::enter()
{
    //loading success flag
    bool success = true;
    
    //create player
    player = &GameState::player;
    wasp = new Wasp(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    
    startTime = pastCount;
    
    return success;
}
    
bool LevelOne::exit()
{
    //free player
    player = NULL;
    
    //free bullets if they exist
    for(int i = 0; i < 2; i++) {
        if(playerBullets[i]) {
            delete playerBullets[i];
            playerBullets[i] = NULL;
        }
    }
    
    return true;
}

void LevelOne::handleEvent( SDL_Event& e )
{
    player->handleEvent(e);
    
    if(e.type == SDL_KEYDOWN && e.key.repeat == 0)
    {
        if(e.key.keysym.sym == SDLK_SPACE) {
            if(playerBullets[nextBullet] == NULL) {
                playerBullets[nextBullet] = new Bullet(player->getX() + 16, STARTING_YPOS - 16);
                Mix_PlayChannel( -1, fireSound, 0 );
                nextBullet = !nextBullet;
            }
        }
    }
    
}

void LevelOne::update()
{
    player->update();
    
    //update bullets
    for(int i = 0; i < 2; i++) {
        if(playerBullets[i]) {
            playerBullets[i]->update();
            
            //if bullet is not on screen delete it
            if(!playerBullets[i]->isOnScreen()) {
                delete playerBullets[i];
                playerBullets[i] = NULL;
            }
        }
    }
}

void LevelOne::render()
{
    player->render();
    wasp->render();
    
    //render bullets
    for(int i = 0; i < 2; i++) {
        if(playerBullets[i]) {
            playerBullets[i]->render();
        }
    }
}

void LevelOne::checkCollision() {
    for(int i = 0; i < 2; i++) {
        if(playerBullets[i]) {
            //if a bullet collides with a wasp
            if(wasp->checkCollision(playerBullets[i]->getCollider())) {
                delete playerBullets[i];
                playerBullets[i] = NULL;
            }
        }
    }
}

LevelOne LevelOne::sLevelOne;

LevelOne::LevelOne()
{
    
}



