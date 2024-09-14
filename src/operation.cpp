#include "operation.h"

int init(SDL_Window** main_window, SDL_Renderer** window_renderer)
{
	bool status = true;
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("couldn't initialize video subsystem, error: %s", SDL_GetError());
		status = false;
		
	}
	else
	{
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		*main_window = SDL_CreateWindow("mymazz", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (*main_window == NULL)
		{
			printf("couldn't create windw, error: %s", SDL_GetError());
			status = false;
		}
		else
		{
			*window_renderer = SDL_CreateRenderer(*main_window, -1, SDL_RENDERER_ACCELERATED);
			if (window_renderer == NULL)
			{
				printf("couldn't create renderer %s", SDL_GetError());
				status = false;
			}
			else
			{
				SDL_SetRenderDrawColor(*window_renderer, 0xff, 0xff, 0xff, 0xff);
				int flags = IMG_INIT_PNG;
				if (!(IMG_Init(flags) & flags)) // this is the cryptic way to make sure everything is fine and please don't send him SDL owner a massage saying this is a bug
				{
					printf("couldn't initialize the png subsystem, error %s", IMG_GetError());
					status = false;
				}
			}
		}
	}
	return (status);
}

int load(SDL_Texture** texture1, SDL_Texture** texture2, SDL_Renderer* renderer)
{
	int success = 0;
	SDL_Surface* main = NULL;
	SDL_Surface* sec = NULL;
	main = loadOneSurface("img_png/backmario.png");
	sec = loadOneSurface("img_png/fade.png");
	if (main == NULL or sec == NULL)
	{
		success = 1;
	}
	else
	{
		*texture1 = createTexture(renderer, main);
		if(SDL_SetColorKey(sec, SDL_TRUE ,SDL_MapRGB(sec->format, 0, 0xff, 0)) < 0)
		{
			printf("failed to colorkey.\nError: %s\n",SDL_GetError());
			success = 1;
		}
		*texture2 = createTexture(renderer, sec);
		if (*texture1 == NULL || *texture2 == NULL)
		{
			success = 1;
		}
	}
	free(main);
	free(sec);
	main = NULL;
	sec = NULL;
	return (success);
}

void close(SDL_Window* main_window, SDL_Renderer* window_renderer, SDL_Texture* text1, SDL_Texture* text2)
{
	closeTexture(text1);
	closeTexture(text2);
	closeRenderer(window_renderer);
	closeWindow(main_window);
	IMG_Quit();
	SDL_Quit();
}
