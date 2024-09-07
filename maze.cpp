#include <SDL2/SDL.h>
#include <stdio.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

SDL_Window * main_window = NULL;
SDL_Surface * main_surface = NULL;
SDL_Surface * img_surface = NULL;



int init()
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("couldn't initialize video subsystem, error: %s", SDL_GetError());
		return false;
	}
	else
	{
		main_window = SDL_CreateWindow("mymazz", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (main_window == NULL)
		{
			printf("couldn't create windw, error: %s", SDL_GetError());
			return false;
		}
		else
		{
			main_surface = SDL_GetWindowSurface(main_window);
		}
	}
	return true;
}

int load() 
{
	img_surface = SDL_LoadBMP("./sam.bmp");
	if (img_surface == NULL)
	{
		printf("failed to load image, error: %s", SDL_GetError());
		return false;
	}
	return true;
}

void close() 
{
	SDL_FreeSurface(main_surface);
	main_surface = NULL;

	SDL_DestroyWindow(main_window);
	main_window = NULL;

	SDL_Quit();
}
int main( int argc, char* args[] )
{
    if (!init())
	{
		printf("failed to inialize the game");
		return (1);
	}
	else
	{
		if (!load())
		{
			printf("failed to load image");
			close();
		}
		else
		{	
			bool quite = false;
			SDL_Event e;

			while(!quite)
			{
				while (SDL_PollEvent(&e))
				{
					if (e.type == SDL_QUIT)
					{
						quite = true;
					}
				}
				SDL_BlitSurface(img_surface, NULL, main_surface, NULL);
				SDL_UpdateWindowSurface(main_window);
			}
			close();
		}
	}
}
