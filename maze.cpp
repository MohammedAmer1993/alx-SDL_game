#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
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
SDL_Surface * loadOneSurface(std::string path);
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
			int flags = IMG_INIT_PNG;
			if (!(IMG_Init(flags) & flags)) // this is the cryptic way to make sure everything is fine and please don't send him SDL owner a massage saying this is a bug
			{
				printf("couldn't initialize the png subsystem, error %s", IMG_GetError());
				status = false;
			}
			else
			{
				main_surface = SDL_GetWindowSurface(main_window);
			}
		}
	}
	return (status);
}

int load() 
{
	bool status = true;

	keyarr[keydefault] = loadOneSurface("./imgpng/keydefault.png");
	img_surface = keyarr[keydefault];
	if (keyarr[keydefault] == NULL)
	{
		printf("failed to load image, error: %s", SDL_GetError());
		status = false;
	}
	keyarr[keyup] = loadOneSurface("./imgpng/keyup.png");
	if (keyarr[keyup] == NULL)
	{
		printf("failed to load image, error: %s", SDL_GetError());
		status = false;
	}
	keyarr[keydown] = loadOneSurface("./imgpng/keydown.png");
	if (keyarr[keydown] == NULL)
	{
		printf("failed to load image, error: %s", SDL_GetError());
		status = false;
	}
	keyarr[keyright] = loadOneSurface("./imgpng/keyright.png");
	if (keyarr[keyright] == NULL)
	{
		printf("failed to load image, error: %s", SDL_GetError());
		status = false;
	}
	keyarr[keyleft] = loadOneSurface("./imgpng/keyleft.png");
	if (keyarr[keyleft] == NULL)
	{
		printf("failed to load image, error: %s", SDL_GetError());
		status = false;
	}
	return (status);
}

SDL_Surface * loadOneSurface(std::string path)
{
	SDL_Surface* optimizedsurface = NULL;
	SDL_Surface* loadedsurface = NULL;

	loadedsurface = IMG_Load(path.c_str());
	if (loadedsurface == NULL)
	{
		printf("failed to load image %s, error: %s\n", path.c_str(), IMG_GetError());
		return (NULL);
	}
	else
	{
		optimizedsurface = SDL_ConvertSurface(loadedsurface, main_surface->format, 0);
		if (optimizedsurface == NULL)
		{
			printf("couldn't optimize surface");
			SDL_FreeSurface(loadedsurface);
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
int main( int argc, char** argv )
{
	(void) argc;
	(void) argv;
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
