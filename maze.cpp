#include <SDL2/SDL.h>
#include <stdio.h>

#define SCREEN_WIDTH 720
#define SCREEN_HEIGHT 1080

SDL_Window * main_window = NULL;
SDL_Surface * main_surface = NULL;
SDL_Surface * img_surface = NULL;

enum key {
	keydefault, keyup, keydown, keyright, keyleft, total
};

SDL_Surface * keyarr[total];


int init()
{
	bool status = true;
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("couldn't initialize video subsystem, error: %s", SDL_GetError());
		status = false;
	}
	else
	{
		main_window = SDL_CreateWindow("mymazz", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (main_window == NULL)
		{
			printf("couldn't create windw, error: %s", SDL_GetError());
			status = false;
		}
		else
		{
			main_surface = SDL_GetWindowSurface(main_window);
		}
	}
	return (status);
}

int load() 
{
	bool status = true;

	keyarr[keydefault] = SDL_LoadBMP("./img/keydefault.bmp");
	img_surface = keyarr[keydefault];
	if (keyarr[keydefault] == NULL)
	{
		printf("failed to load image, error: %s", SDL_GetError());
		status = false;
	}
	keyarr[keyup] = SDL_LoadBMP("./img/keyup.bmp");
	if (keyarr[keyup] == NULL)
	{
		printf("failed to load image, error: %s", SDL_GetError());
		status = false;
	}
	keyarr[keydown] = SDL_LoadBMP("./img/keydown.bmp");
	if (keyarr[keydown] == NULL)
	{
		printf("failed to load image, error: %s", SDL_GetError());
		status = false;
	}
	keyarr[keyright] = SDL_LoadBMP("./img/keyright.bmp");
	if (keyarr[keyright] == NULL)
	{
		printf("failed to load image, error: %s", SDL_GetError());
		status = false;
	}
	keyarr[keyleft] = SDL_LoadBMP("./img/keyleft.bmp");
	if (keyarr[keyleft] == NULL)
	{
		printf("failed to load image, error: %s", SDL_GetError());
		status = false;
	}
	return (status);
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
    if (init() == false)
	{
		printf("failed to inialize the game");
		return (1);
	}
	else
	{
		if (load() == false)
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
					else if( e.type == SDL_KEYDOWN )
					{
						switch (e.key.keysym.sym)
						{
						case SDLK_UP:
							img_surface = keyarr[keyup];
							break;
						case SDLK_DOWN:
							img_surface = keyarr[keydown];
							break;
						case SDLK_RIGHT:
							img_surface = keyarr[keyright];
							break;
						case SDLK_LEFT:
							img_surface = keyarr[keyleft];
							break;
						
						default:
							img_surface = keyarr[keydefault];
							break;
						}
					}
					SDL_BlitSurface(img_surface, NULL, main_surface, NULL);
					SDL_UpdateWindowSurface(main_window);
				}
			}
			close();
		}
	}
}
