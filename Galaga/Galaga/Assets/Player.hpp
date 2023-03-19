//
//  Player.hpp
//  Galaga
//
//  Created by Jake Houts on 3/17/23.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include "LTexture.hpp"
#include "Bullet.hpp"

class Player {
public:
    //player speed
    static const int PLAYER_VEL = 250;
    
    //constructor
    Player();
    
    //destructor
    ~Player();
    
    //handle input
    void handleEvent(SDL_Event &e);
    
    //update position
    void update();
    
    //render pc
    void render();
    
private:
    //position of the player
    float xPos, yPos;
    
    //texture of the player
    LTexture *playerTexture;
    
    //current velocity of the player
    float xVel;
    
    //bullets available to the player
    Bullet *bullets[2];
    
    //keeps track of which index the next bullet will be stored
    int nextBullet;
    
    //Players collision box
    SDL_Rect playerCollider;
};

#endif /* Player_hpp */
