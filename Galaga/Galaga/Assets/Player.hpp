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

class Player {
public:
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
    int xPos, yPos;
    
    LTexture *playerTexture;
    
    float xVel;
    
    
};

#endif /* Player_hpp */
