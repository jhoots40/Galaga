//
//  Star.cpp
//  Galaga
//
//  Created by Jake Houts on 3/16/23.
//

#include "../Constants.h"
#include "Star.hpp"
#include "LTexture.hpp"
#include "../Globals.h"
#include <cstdlib>
#include <sys/time.h>
#include <iostream>

Star::Star(LTexture *L, int x, int y){
    //initialize variables
    starColor = L;
    xPos = x;
    yPos = y;
    speed = ((rand() % 4) + 1) * 100;
    blink = rand() % 2;
    blinkType = 0;
}

Star::Star() {
    //default constructor
    starColor = NULL;
    xPos = 0;
    yPos = 0;
    speed = 0.0f;
}

void Star::update() {
    //update speed according to the deltaTime variable and star speed
    yPos += speed * dt;
    //if yPos is bigger than the screen bring it back
    if( yPos > SCREEN_HEIGHT ) {
        yPos = yPos - 800;
    }
    
    struct timeval time_now{};
    gettimeofday(&time_now, nullptr);
    time_t ms = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
    if(blinkType == 0) {
        blink = true;
    }
    else if(blinkType == 1) {
        
    }
    else if(blinkType == 2) {
        
    }
    else if(blinkType == 3) {
        
    } else {
        fprintf(stderr, "blinkType is invalid");
    }
    
}

void Star::render() {
    //render star at current position
    if(blink) starColor->render(xPos, yPos);

}

Star::~Star() {
    starColor = NULL;
}
