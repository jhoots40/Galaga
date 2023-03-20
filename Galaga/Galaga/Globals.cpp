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

//helps calculate delta time
Uint32 pastCount = 0;

//load font as well
TTF_Font* gFont = NULL;

//load all textures at the star of the program
LTexture playerShip;
LTexture galagaLogo;
LTexture playerBullet;
LTexture wasp;

//intro music
Mix_Chunk *introMusic = NULL;
Mix_Chunk *fireSound = NULL;
