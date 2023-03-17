//
//  Globals.cpp
//  Galaga
//
//  Created by Jake Houts on 3/16/23.
//

#include "Globals.h"
#include "LTexture.hpp"
#include "sys/time.h"

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//delta time: the amount of time that has passed since the last frame in seconds
float dt = 0;
