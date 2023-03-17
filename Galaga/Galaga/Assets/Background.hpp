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
    //texture for the black background
    LTexture black;
    
    //Texture for each of the colored stars, should probs put these all in one texture in the future
    LTexture blueStars;
    LTexture redStars;
    LTexture greenStars;
    LTexture yellowStars;
    
    //array of stars I am rendering to the screen
    Star stars[80];
};

#endif /* background_hpp */
