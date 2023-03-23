/*This source code copyrighted by Lazy Foo' Productions (2004-2022)
and may not be redistributed without written permission.*/

#include "Util.h"
#include "Globals.h"
#include "Constants.h"

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "GALAGA", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
                
                //Initialize SDL_mixer
                if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
                {
                    printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
                    success = false;
                }
                
                //Initialize SDL_ttf
                if( TTF_Init() == -1 )
                {
                    printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
                    success = false;
                }
			}
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;
    
    if( !playerShip.loadFromFile("resources/player.png"))
    {
        fprintf(stderr, "Failed to load \"resources/player.png\"\n" );
        success = false;
    }
    
    if( !galagaLogo.loadFromFile("resources/Logo.png"))
    {
        fprintf(stderr, "Failed to load \"resources/Logo.png\"\n" );
        success = false;
    }
    if( !playerBullet.loadFromFile("resources/playerBullet.png"))
    {
        fprintf(stderr, "Failed to load \"resources/playerBullet.png\"\n" );
        success = false;
    }
    if( !gWaspSheet.loadFromFile("resources/wasp.png"))
    {
        fprintf(stderr, "Failed to load \"resources/wasp.png\"\n" );
        success = false;
    } else {
        for(int i = 0; i < 2; i++) {
            gWaspClips[i].x = i * 32;
            gWaspClips[i].y = 0;
            gWaspClips[i].w = 32;
            gWaspClips[i].h = 32;
        }
    }
    if( !gButterflySheet.loadFromFile("resources/butterfly.png"))
    {
        fprintf(stderr, "Failed to load \"resources/butterfly.png\"\n" );
        success = false;
    } else {
        for(int i = 0; i < 2; i++) {
            gButterflyClips[i].x = i * 32;
            gButterflyClips[i].y = 0;
            gButterflyClips[i].w = 32;
            gButterflyClips[i].h = 32;
        }
    }
    if( !enemyDeathSheet.loadFromFile("resources/enemyDeath.png"))
    {
        fprintf(stderr, "Failed to load \"resources/enemyDeath.png\"\n" );
        success = false;
    } else {
        for(int i = 0; i < 5; i++) {
            enemyDeathClips[i].x = i * 64;
            enemyDeathClips[i].y = 0;
            enemyDeathClips[i].w = 64;
            enemyDeathClips[i].h = 64;
        }
    }
    
    
    //Open the font
    gFont = TTF_OpenFont( "resources/font.ttf", 28 );
    if( gFont == NULL )
    {
        fprintf( stderr, "Failed to load galaga font! SDL_ttf Error: %s\n", TTF_GetError() );
        success = false;
    }
    
    //Load sound effects
    introMusic = Mix_LoadWAV( "resources/GalagaThemeSong.wav" );
    if( introMusic == NULL )
    {
        printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }
    
    fireSound = Mix_LoadWAV( "resources/fireSound.wav" );
    if( fireSound == NULL )
    {
        printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }

	return success;
}

void close()
{
    //free textures
    playerShip.free();
    galagaLogo.free();
    playerBullet.free();
    gWaspSheet.free();
    enemyDeathSheet.free();
    
    //free sound files
    Mix_FreeChunk(introMusic);
    Mix_FreeChunk(fireSound);
    introMusic = NULL;
    fireSound = NULL;

	//Destroy window	
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
    Mix_Quit();
    TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}
