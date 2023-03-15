//
//  GameState.cpp
//  Galaga
//
//  Created by Jake Houts on 3/14/23.
//

#include "GameState.hpp"

GameState *nextState = NULL;
GameState *currentState = NULL;

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
