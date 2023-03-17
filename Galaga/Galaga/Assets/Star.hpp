//
//  Star.hpp
//  Galaga
//
//  Created by Jake Houts on 3/16/23.
//

#ifndef Star_hpp
#define Star_hpp

#include <stdio.h>
#include "LTexture.hpp"

class Star {
public:
    //constructor
    Star(LTexture *L, int x, int y);
    
    //default constructor
    Star();
    
    //deconstructor
    ~Star();
    
    //update the position of the star
    void update();
    
    //render the star
    void render();
    
private:
    //x and y pos
    int xPos, yPos;
    
    //speed of the star
    float speed;
    
    //should the star be printed or not
    bool blink;
    
    //pointer to the texture
    LTexture *starColor;
    
    //designates how the star will blink
    int blinkType;
    
    //time offset in ms
    int offset;
};

#endif /* Star_hpp */
