#include "util.h"


int loadImgArr(SDL_Surface* keyarr[])
{
	bool status = true;

	keyarr[keydefault] = loadOneSurface("img_png/keydefault.png");
	if (keyarr[keydefault] == NULL)
	{
		printf("failed to load image, error: %s", SDL_GetError());
		status = false;
	}
	keyarr[keyup] = loadOneSurface("img_png/keyup.png");
	if (keyarr[keyup] == NULL)
	{
		printf("failed to load image, error: %s", SDL_GetError());
		status = false;
	}
	keyarr[keydown] = loadOneSurface("img_png/keydown.png");
	if (keyarr[keydown] == NULL)
	{
		printf("failed to load image, error: %s", SDL_GetError());
		status = false;
	}
	keyarr[keyright] = loadOneSurface("img_png/keyright.png");
	if (keyarr[keyright] == NULL)
	{
		printf("failed to load image, error: %s", SDL_GetError());
		status = false;
	}
	keyarr[keyleft] = loadOneSurface("img_png/keyleft.png");
	if (keyarr[keyleft] == NULL)
	{
		printf("failed to load image, error: %s", SDL_GetError());
		status = false;
	}
	return (status);
}


SDL_Surface* loadOneSurface(std::string path)
{
	SDL_Surface* loadedsurface = NULL;

	loadedsurface = IMG_Load(path.c_str());
	if (loadedsurface == NULL)
	{
		printf("failed to load image %s, error: %s\n", path.c_str(), IMG_GetError());
		return (NULL);
	}
	else
	{
		return (loadedsurface);
	}
}


SDL_Surface* optimizeSurface(SDL_Surface* surface, SDL_PixelFormat* fmt)
{
	SDL_Surface* tmp = NULL;
	tmp = SDL_ConvertSurface(surface, fmt, 0);
	if (tmp == NULL)
	{
		printf("couldn't convert the surface into required format.\nError: %s\n",SDL_GetError());
		return (NULL);
	}
	else
	{
		return (tmp);
	}
}

void closeImgArr(SDL_Window* main_window, SDL_Surface* main_surface, SDL_Surface** keyarr) 
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

void closeTexture (SDL_Texture* window_texture)
{
	
	SDL_DestroyTexture(window_texture);
	window_texture = NULL;
}

void closeWindow(SDL_Window* main_window)
{
	SDL_DestroyWindow(main_window);
	main_window = NULL;
}

void closeRenderer(SDL_Renderer* window_renderer)
{
	SDL_DestroyRenderer(window_renderer);
	window_renderer = NULL;
}

SDL_Texture* createTexture(SDL_Renderer* window_renderer,SDL_Surface* loadedSurface)
{
	SDL_Texture* texture = NULL;
	texture = SDL_CreateTextureFromSurface(window_renderer, loadedSurface);
	if (texture == NULL)
	{
		printf("couldn't load textur from surface, Error: %s\n", SDL_GetError());
		return (NULL);
	}
	else
	{
		return(texture);
	}
}
