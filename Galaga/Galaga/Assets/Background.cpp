//
//  background.cpp
//  Galaga
//
//  Created by Jake Houts on 3/14/23.
//

#include "Background.hpp"
#include "Globals.h"

//constructor
Background::Background() {
    
    redPos = 0;
    bluePos = 0;
    
    //Load redStars
    if( !redStars.loadFromFile( "resources/redStars.png" ) )
    {
        fprintf(stderr, "Failed to load \"resources/redStars.png\"\n" );
        exit(1);
    }
    
    //Load blueStars
    if( !blueStars.loadFromFile( "resources/blueStars.png" ) )
    {
        fprintf(stderr, "Failed to load \"resources/blueStars.png\"\n" );
        exit(1);
    }
}

//deconstructor
Background::~Background() {
    redStars.free();
    blueStars.free();
}

//update the position of the stars
void Background::update() {
    //move stars downward at a pace of 100 pixels per second
    redPos += 100 * dt;
    if( redPos > redStars.getHeight() )
    {
        redPos = 0;
    }
    
    //move stars downward at a pace of 200 pixels per second
    bluePos += 200 * dt;
    if( bluePos > blueStars.getHeight() )
    {
        bluePos = 0;
    }
}

//render the stars
void Background::render() {
    //Render objects
    redStars.render( 0, redPos );
    redStars.render( 0, redPos - redStars.getHeight() );
    blueStars.render( 0, bluePos );
    blueStars.render( 0, bluePos - blueStars.getHeight() );

    //Update screen
    SDL_RenderPresent( gRenderer );
}
