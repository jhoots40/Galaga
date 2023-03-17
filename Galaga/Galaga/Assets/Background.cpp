//
//  background.cpp
//  Galaga
//
//  Created by Jake Houts on 3/14/23.
//
#include "Constants.h"
#include "Background.hpp"
#include "Globals.h"

//constructor
Background::Background() {

    //Load black background
    if( !black.loadFromFile( "resources/black.png" ) )
    {
        fprintf(stderr, "Failed to load \"resources/black.png\"\n" );
        exit(1);
    }
    
    //Load a green star texture
    if( !greenStars.loadFromFile( "resources/greenStar.png" ) )
    {
        fprintf(stderr, "Failed to load \"resources/greenStar.png\"\n" );
        exit(1);
    }
    
    //Load a yellow star texture
    if( !yellowStars.loadFromFile( "resources/yellowStar.png" ) )
    {
        fprintf(stderr, "Failed to load \"resources/yellowStar.png\"\n" );
        exit(1);
    }
    
    //Load a red star texture
    if( !redStars.loadFromFile( "resources/redStar.png" ) )
    {
        fprintf(stderr, "Failed to load \"resources/redStar.png\"\n" );
        exit(1);
    }
    
    //Load a blue star texture
    if( !blueStars.loadFromFile( "resources/blueStar.png" ) )
    {
        fprintf(stderr, "Failed to load \"resources/blueStar.png\"\n" );
        exit(1);
    }

    //assign the stars to a random x and y position and color
    for (int i = 0; i < 80; i++) {
        if (i < 20) {
            stars[i] = Star(&redStars, rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT);
        } else if (i < 40) {
            stars[i] = Star(&blueStars, rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT);
        } else if (i < 60) {
            stars[i] = Star(&greenStars, rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT);
        } else {
            stars[i] = Star(&yellowStars, rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT);
        }
    }
    
}

//deconstructor
Background::~Background() {
    // free memory used by stars array
    for (int i = 0; i < 80; i++) {
        // call the destructor of each Star object to free its memory
        stars[i].~Star();
    }
    
    //free memory from textures
    black.~LTexture();
    blueStars.~LTexture();
    redStars.~LTexture();
    greenStars.~LTexture();
    yellowStars.~LTexture();
}

//update the position of the stars
void Background::update() {
    for(int i = 0; i < 80; i++) {
        stars[i].update();
    }
}

//render the background
void Background::render() {
    //render black background
    black.render( 0, 0 );
    
    //render stars
    for(int i = 0; i < 80; i++) {
        stars[i].render();
    }
}
