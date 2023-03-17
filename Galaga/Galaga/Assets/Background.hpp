//
//  background.hpp
//  Galaga
//
//  Created by Jake Houts on 3/14/23.
//

#ifndef Background_hpp
#define Background_hpp

#include <stdio.h>
#include "LTexture.hpp"
#include "Star.hpp"

class Background {
public:
    //constructor
    Background();
    
    //deconstructor
    ~Background();
    
    //update the position of the stars
    void update();
    
    //render the stars
    void render();
    
private:
    //black background
    LTexture black;
    
    LTexture blueStars;
    
    LTexture redStars;
    
    LTexture greenStars;
    
    LTexture yellowStars;
    
    Star stars[100];
    
    //scrolling offset for red stars
    int redPos;
    
    //scrolling offset for blue stars
    int bluePos;
};

#endif /* background_hpp */
