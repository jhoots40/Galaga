#include "Util.h"
#include "Globals.h"
#include "GameState.hpp"
#include "Background.hpp"
#include "Star.hpp"

int main( int argc, char* args[] )
{
    
    //Start up SDL and create window
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        //Load media
        if( !loadMedia() )
        {
            printf( "Failed to load media!\n" );
        }
        else
        {
            
            //helps calculate delta time
            Uint32 pastCount = 0;
            
            //background for the entire game
            Background b;
            
            //Event handler
            SDL_Event e;

            //Set the current game state object
            currentState = MenuState::get();
            currentState->enter();

            //While the user hasn't quit
            while( currentState != ExitState::get() )
            {
                //calculate delta time
                dt = (SDL_GetTicks() - pastCount) / 1000.0f;
                pastCount = SDL_GetTicks();
                
                //Do state event handling
                while( SDL_PollEvent( &e ) != 0 )
                {
                    //Handle state events
                    currentState->handleEvent( e );

                    //Exit on quit
                    if( e.type == SDL_QUIT )
                    {
                        setNextState( ExitState::get() );
                    }
                }

                //Do state logic
                b.update();
                currentState->update();

                //Change state if needed
                changeState();

                //Clear screen
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                SDL_RenderClear( gRenderer );

                //Do state rendering
                b.render();
                currentState->render();

                //Update screen
                SDL_RenderPresent( gRenderer );
            }
        }
    }

    //Free resources and close SDL
    close();

    return 0;
}
 
