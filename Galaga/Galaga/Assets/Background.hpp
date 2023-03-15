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
    
    //red stars
    LTexture redStars;
    
    //blue stars
    LTexture blueStars;
    
    //scrolling offset for red stars
    float redPos;
    
    //scrolling offset for blue stars
    float bluePos;
};

#endif /* background_hpp */
