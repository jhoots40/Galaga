#ifndef GLOBALS_H
#define GLOBALS_H

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include "LTexture.hpp"

//The window we'll be rendering to
extern SDL_Window* gWindow;

//The window renderer
extern SDL_Renderer* gRenderer;

//delta time: the amount of time that has passed since the last frame in seconds
extern float dt;

//helps calculate delta time
extern Uint32 pastCount;

//font for galaga game
extern TTF_Font* gFont;


extern LTexture playerShip;
extern LTexture galagaLogo;
extern LTexture playerBullet;

extern LTexture gWaspSheet;
extern SDL_Rect gWaspClips[2];

extern LTexture gButterflySheet;
extern SDL_Rect gButterflyClips[2];

extern LTexture enemyDeathSheet;
extern SDL_Rect enemyDeathClips[5];

//intro music
extern Mix_Chunk *introMusic;
extern Mix_Chunk *fireSound;

#endif 

