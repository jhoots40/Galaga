//
//  MenuState.cpp
//  Galaga
//
//  Created by Jake Houts on 3/14/23.
//

#include "../GameState.hpp"
#include "../../Globals.h"
#include "Constants.h"

MenuState* MenuState::get()
{
    return &sMenuState;
}

bool MenuState::enter()
{
    select = true;
    scrollingOffset = 600;
    SDL_Color white = {255, 255, 255};
    logo = &galagaLogo;
    player1 = new LTexture();
    player2 = new LTexture();
    marker = new LTexture();
    player1->loadFromRenderedText("1 Player", white);
    player2->loadFromRenderedText("2 Players", white);
    marker->loadFromRenderedText(">", white);
    
    return select;
}
    
bool MenuState::exit()
{
    logo = NULL;
    delete player1;
    player1 = NULL;
    delete player2;
    player2 = NULL;
    delete marker;
    marker = NULL;
    return true;
}

void MenuState::handleEvent( SDL_Event& e )
{
    if(e.type == SDL_KEYDOWN && e.key.repeat == 0) {
        if(e.key.keysym.sym == SDLK_DOWN && select == true) {
            select = false;
        }
        if(e.key.keysym.sym == SDLK_UP && select == false) {
            select = true;
        }
        if(e.key.keysym.sym == SDLK_SPACE && scrollingOffset == 0) {
            setNextState( PlayState::get() );
        }
    }
}

void MenuState::update()
{
    if(scrollingOffset > 0) {
        scrollingOffset -= 100 * dt;
    }
    else if (scrollingOffset < 0) {
        scrollingOffset = 0;
    }
}

void MenuState::render()
{
    //galagaLogo.render(0, 0);
    int markerPos = 0;
    if(select) markerPos = ((SCREEN_HEIGHT - player1->getHeight()) / 2) + 100;
    else markerPos = ((SCREEN_HEIGHT - player2->getHeight()) / 2) + 150;
    
    
    logo->render((SCREEN_WIDTH - logo->getWidth()) / 2, ( (SCREEN_HEIGHT - logo->getHeight()) / 2) - 100 + scrollingOffset);
    player1->render((SCREEN_WIDTH - player1->getWidth()) / 2, ((SCREEN_HEIGHT - player1->getHeight()) / 2) + 100 + scrollingOffset);
    player2->render((SCREEN_WIDTH - player1->getWidth()) / 2, ((SCREEN_HEIGHT - player2->getHeight()) / 2) + 150 + scrollingOffset);
    marker->render(((SCREEN_WIDTH - player1->getWidth()) / 2) - 50, markerPos + scrollingOffset);
    
}

MenuState MenuState::sMenuState;

MenuState::MenuState()
{
    
}
