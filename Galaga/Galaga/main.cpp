#include "Util.h"
#include "Globals.h"
#include "GameState.hpp"

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
             //Event handler
             SDL_Event e;

             //Set the current game state object
             currentState = MenuState::get();
             currentState->enter();

             //While the user hasn't quit
             while( currentState != ExitState::get() )
             {
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
                 currentState->update();

                 //Change state if needed
                 changeState();

                 //Clear screen
                 SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                 SDL_RenderClear( gRenderer );

                 //Do state rendering
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
 
