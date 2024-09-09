#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768

SDL_Window * main_window = NULL;
SDL_Surface * main_surface = NULL;
SDL_Surface * img_surface = NULL;

enum key {
	keydefault, keyup, keydown, keyright, keyleft, total
};

SDL_Surface * keyarr[total];

int init();
SDL_Surface * loadsurface(std::string path);
int load();
void close();

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

	keyarr[keydefault] = loadsurface("./img/keydefault.bmp");
	img_surface = keyarr[keydefault];
	if (keyarr[keydefault] == NULL)
	{
		printf("failed to load image, error: %s", SDL_GetError());
		status = false;
	}
	keyarr[keyup] = loadsurface("./img/keyup.bmp");
	if (keyarr[keyup] == NULL)
	{
		printf("failed to load image, error: %s", SDL_GetError());
		status = false;
	}
	keyarr[keydown] = loadsurface("./img/keydown.bmp");
	if (keyarr[keydown] == NULL)
	{
		printf("failed to load image, error: %s", SDL_GetError());
		status = false;
	}
	keyarr[keyright] = loadsurface("./img/keyright.bmp");
	if (keyarr[keyright] == NULL)
	{
		printf("failed to load image, error: %s", SDL_GetError());
		status = false;
	}
	keyarr[keyleft] = loadsurface("./img/keyleft.bmp");
	if (keyarr[keyleft] == NULL)
	{
		printf("failed to load image, error: %s", SDL_GetError());
		status = false;
	}
	return (status);
}

SDL_Surface * loadsurface(std::string path)
{
	SDL_Surface* optimizedsurface = NULL;
	SDL_Surface* loadedsurface = NULL;

	loadedsurface = SDL_LoadBMP(path.c_str());
	if (loadedsurface == NULL)
	{
		printf("failed to load image %s, error: %s\n", path.c_str(), SDL_GetError());
		return (NULL);
	}
	else
	{
		optimizedsurface = SDL_ConvertSurface(loadedsurface, main_surface->format, 0);
		if (optimizedsurface == NULL)
		{
			printf("couldn't optimize surface");
			return (NULL);
		}
		else
		{
			SDL_FreeSurface(loadedsurface);
			return (optimizedsurface);
		}
	}
}

void close() 
{
	for (int i = 0; i < total; ++i)
	{
		SDL_FreeSurface(keyarr[i]);
		keyarr[i] = NULL;
	}
	SDL_FreeSurface(main_surface);
	main_surface = NULL;

	SDL_DestroyWindow(main_window);
	main_window = NULL;

	SDL_Quit();
}
int main( int argc, char* args[] )
{
	SDL_Rect imgStretchedRect;
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
					imgStretchedRect.x = 0;
					imgStretchedRect.y = 0;
					imgStretchedRect.h = SCREEN_HEIGHT;
					imgStretchedRect.w = SCREEN_WIDTH;
					SDL_BlitScaled(img_surface, NULL, main_surface, &imgStretchedRect);
					SDL_UpdateWindowSurface(main_window);
				}
			}
			close();
		}
	}
}
