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
#include "DeathState.hpp"

LevelOne* LevelOne::get()
{
    return &sLevelOne;
}

bool LevelOne::enter()
{
    //loading success flag
    bool success = true;
    
    //set player pointer to static player
    player = &GameState::player;
    
    //create the wasps
    //wasps[0] = new Wasp(50, 200);
    //wasps[1] = new Wasp(150, 200);
    //wasps[2] = new Wasp(250, 200);
    //wasps[3] = new Wasp(350, 200);
    //wasps[4] = new Wasp(450, 200);
    
    //create the butteflies
    b[0] = new Butterfly(100, 200);
    b[1] = new Butterfly(200, 200);
    b[2] = new Butterfly(300, 200);
    b[3] = new Butterfly(400, 200);
    b[4] = new Butterfly(500, 200);
    
    //create the bosses
    
    //startTime = pastCount;
    
    return success;
}
    
bool LevelOne::exit()
{
    //free player
    player = NULL;
    
    //free butterflies
    for(int i = 0; i < 5; i++) {
        if(b[i]) {
            delete b[i];
            b[i] = NULL;
        }
    }
    
    //free wasps
    for(int i = 0; i < 5; i++) {
        if(wasps[i]) {
            delete wasps[i];
            wasps[i] = NULL;
        }
    }
    
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
    //handle event for player
    player->handleEvent(e);
    
    
    //there is not event handling for the enemies but the functionality is there if needed
    
    /*for(int i = 0; i < 5; i++) {
        if(wasps[i]) wasps[i]->handleEvent(e);
    }
    
    for(int i = 0; i < 5; i++) {
        if(butterflies[i]) butterflies[i]->handleEvent(e);
    }*/
    
    
    //if player presses space fire one of the two bullets if available
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
    //update player
    player->update();
    
    //update wasps
    for(int i = 0; i < 5; i++) {
        if(wasps[i]) wasps[i]->update();
    }
    
    //update butterflies
    for(int i = 0; i < 5; i++) {
        if(b[i]) b[i]->update();
    }
    
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

void LevelOne::checkCollision() {
    for(int i = 0; i < 2; i++) {
        if(playerBullets[i]) {
            
            //collision box for current bullet
            SDL_Rect currentBullet = playerBullets[i]->getCollider();
            
            for(int j = 0; j < 5; j++) {
                if(b[j]) {
                    
                    //collision box for current butterfly
                    SDL_Rect currentButterfly = b[j]->getCollider();
                    if(globalCheckCollision(currentBullet, currentButterfly)) {
                        //bullet collided to we free it
                        delete playerBullets[i];
                        playerBullets[i] = NULL;
                        //tell enemy to play the death animation
                        b[j]->setNextState(new DeathState());
                    }
                }
            }
        }
    }
}

void LevelOne::render()
{
    //render player
    player->render();
    
    //render butterflies
    for(int i = 0; i < 5; i++) {
        if(b[i]) b[i]->render();
    }
    
    //render wasps
    for(int i = 0; i < 5; i++) {
        if(wasps[i]) wasps[i]->render();
    }
    
    //render bullets
    for(int i = 0; i < 2; i++) {
        if(playerBullets[i]) {
            playerBullets[i]->render();
        }
    }
    
    
    //update enemy states if needed
    for(int i = 0; i < 5; i++) {
        if(b[i]) b[i]->changeState();
    }
    
    
    //CLEAN UP ENEMIES
    
    //this is the end of our game loop
    //dont wanna define a helper function rn so we will clean up dead enemies here
    for(int i = 0; i < 5; i++) {
        //clean wasps if they exist and theyre dead
        if(wasps[i]) {
            if(!wasps[i]->isAlive()) {
                delete wasps[i];
                wasps[i] = NULL;
            }
        }
        //claen butterflies if they exist and theyre dead
        if(b[i]) {
            if(!b[i]->isAlive()) {
                delete b[i];
                b[i] = NULL;
            }
        }
    }
    
}

LevelOne LevelOne::sLevelOne;

LevelOne::LevelOne()
{
    
}


