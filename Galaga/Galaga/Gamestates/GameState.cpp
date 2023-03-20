//
//  GameState.cpp
//  Galaga
//
//  Created by Jake Houts on 3/14/23.
//

#include "GameState.hpp"

GameState *nextState = NULL;
GameState *currentState = NULL;

Player GameState::player = Player();

void setNextState( GameState* newState )
{
    //If the user doesn't want to exit
    if( nextState != ExitState::get() )
    {
        //Set the next state
        nextState = newState;
    }
}

void changeState()
{
    //If the state needs to be changed
    if( nextState != NULL )
    {
        currentState->exit();
        nextState->enter();

        //Change the current state ID
        currentState = nextState;
        nextState = NULL;
    }
}

bool globalCheckCollision(SDL_Rect A, SDL_Rect B)
{
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = A.x;
    rightA = A.x + A.w;
    topA = A.y;
    bottomA = A.y + A.h;

    //Calculate the sides of rect B
    leftB = B.x;
    rightB = B.x + B.w;
    topB = B.y;
    bottomB = B.y + B.h;

    //If any of the sides from A are outside of B
    if( bottomA <= topB )
    {
        return false;
    }

    if( topA >= bottomB )
    {
        return false;
    }

    if( rightA <= leftB )
    {
        return false;
    }

    if( leftA >= rightB )
    {
        return false;
    }

    //If none of the sides from A are outside B
    return true;
}
