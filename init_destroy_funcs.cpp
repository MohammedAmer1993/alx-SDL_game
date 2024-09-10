#include "def.h"


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
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		main_window = SDL_CreateWindow("mymazz", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (main_window == NULL)
		{
			printf("couldn't create windw, error: %s", SDL_GetError());
			status = false;
		}
		else
		{
			window_renderer = SDL_CreateRenderer(main_window, -1, SDL_RENDERER_ACCELERATED);
			if (window_renderer == NULL)
			{
				printf("couldn't create renderer %s", SDL_GetError());
				status = false;
			}
			else
			{
				SDL_SetRenderDrawColor(window_renderer, 0xff, 0xff, 0xff, 0xff);
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

int load() 
{
	bool status = true;

	keyarr[keydefault] = loadOneSurface("./img_png/keydefault.png");
	img_surface = keyarr[keydefault];
	if (keyarr[keydefault] == NULL)
	{
		printf("failed to load image, error: %s", SDL_GetError());
		status = false;
	}
	keyarr[keyup] = loadOneSurface("./img_png/keyup.png");
	if (keyarr[keyup] == NULL)
	{
		printf("failed to load image, error: %s", SDL_GetError());
		status = false;
	}
	keyarr[keydown] = loadOneSurface("./img_png/keydown.png");
	if (keyarr[keydown] == NULL)
	{
		printf("failed to load image, error: %s", SDL_GetError());
		status = false;
	}
	keyarr[keyright] = loadOneSurface("./img_png/keyright.png");
	if (keyarr[keyright] == NULL)
	{
		printf("failed to load image, error: %s", SDL_GetError());
		status = false;
	}
	keyarr[keyleft] = loadOneSurface("./img_png/keyleft.png");
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

void closeForSurface() 
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

void closeForTexture () {
	SDL_DestroyRenderer(window_renderer);
	window_renderer = NULL;
	SDL_DestroyTexture(window_texture);
	window_texture = NULL;
	SDL_DestroyWindow(main_window);
	main_window = NULL;
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* loadTexture(std::string path)
{
	SDL_Surface* loadedSurface = NULL;
	SDL_Texture* texture = NULL;
	loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("failed to load img, Error %s\n",IMG_GetError());
		return NULL;
	}
	else
	{
		texture = SDL_CreateTextureFromSurface(window_renderer, loadedSurface);
		if (texture == NULL)
		{
			printf("couldn't load textur from surface, Error: %s\n", SDL_GetError());
			SDL_FreeSurface(loadedSurface);
			return (NULL);
		}
		else
		{
			SDL_FreeSurface(loadedSurface);
			return(texture);
		}
	}
}
