/*This source code copyrighted by Lazy Foo' Productions (2004-2022)
and may not be redistributed without written permission.*/

#ifndef GLOBALS_H
#define GLOBALS_H

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

//The window we'll be rendering to
extern SDL_Window* gWindow;

//The window renderer
extern SDL_Renderer* gRenderer;

//delta time: the amount of time that has passed since the last frame in seconds
extern float dt;

#endif 

