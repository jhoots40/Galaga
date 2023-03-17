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
#include <sys/time.h>

Star::Star(LTexture *L, int x, int y){
    //pointer to correct star texture
    starColor = L;
    
    xPos = x;
    yPos = y;
    
    //speed will randomly be 100, 200, 300, 400 pixels/sec
    speed = ((rand() % 4) + 1) * 100;
    
    //blinktype makes it so 20 percent of stars will not blink
    blink = true;
    blinkType = rand() % 5;
    
    //offset of time for blinking
    offset = rand() % 1000;
}

Star::Star() {
    //default constructor
    starColor = NULL;
    xPos = 0;
    yPos = 0;
    speed = 0.0f;
    blink = false;
    blinkType = 0;
    offset = 0;
}

void Star::update() {
    
    //update speed according to the deltaTime variable and star speed
    yPos += speed * dt;
    
    //if yPos is bigger than the screen bring it back
    if( yPos > SCREEN_HEIGHT ) {
        yPos = yPos - 800;
    }
    
    //collect time
    struct timeval time_now{};
    gettimeofday(&time_now, nullptr);
    time_t ms = ((time_now.tv_sec * 1000) + (time_now.tv_usec / 1000));
    
    //counts from 0-750 in millseconds
    //if we are between 0 - 500 ms we show the star
    //else we don't show the star
    if(((ms + offset) % 750) < 500) {
        blink = true;
    } else {
        blink = false;
    }
}

void Star::render() {
    //render star at current position if blink is true or its blink type is 0
    if(blink || blinkType == 0) starColor->render(xPos, yPos);

}

Star::~Star() {
    //nullify pointer
    starColor = NULL;
}
