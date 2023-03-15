//
//  MenuState.cpp
//  Galaga
//
//  Created by Jake Houts on 3/14/23.
//

#include "../GameState.hpp"
#include "../Globals.h"

//Hollow exit state
MenuState* MenuState::get()
{
    return &sMenuState;
}

bool MenuState::enter()
{
    //loading success flag
    bool success = true;
    
    //Load redStars
    if( !redStars.loadFromFile( "resources/redStars.png" ) )
    {
        fprintf(stderr, "Failed to load \"resources/redStars.png\"\n" );
        success = false;
    }
    
    //Load blueStars
    if( !blueStars.loadFromFile( "resources/blueStars.png" ) )
    {
        fprintf(stderr, "Failed to load \"resources/blueStars.png\"\n" );
        success = false;
    }
    
    return success;
}
    
bool MenuState::exit()
{
    return true;
}

void MenuState::handleEvent( SDL_Event& e )
{

}

void MenuState::update()
{

}

void MenuState::render()
{
    ++scrollingOffset;
    if( scrollingOffset > redStars.getHeight() )
    {
        scrollingOffset = 0;
    }
    
    scrollingOffset2 = scrollingOffset2 + 2;
    if( scrollingOffset2 > blueStars.getHeight() )
    {
        scrollingOffset2 = 0;
    }

    //Render objects
    redStars.render( 0, scrollingOffset );
    redStars.render( 0, scrollingOffset - redStars.getHeight() );
    blueStars.render( 0, scrollingOffset2 );
    blueStars.render( 0, scrollingOffset2 - blueStars.getHeight() );

    //Update screen
    SDL_RenderPresent( gRenderer );
}

MenuState MenuState::sMenuState;

MenuState::MenuState()
{

}
