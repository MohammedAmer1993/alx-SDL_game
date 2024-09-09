#include "def.h"

SDL_Window* main_window = NULL;
SDL_Surface* main_surface = NULL;
SDL_Surface* img_surface = NULL;
SDL_Renderer* window_renderer = NULL;
SDL_Texture* window_texture = NULL;

SDL_Surface* keyarr[total];

int main( int argc, char** argv )
{
	(void) argc;
	(void) argv;

    if (init() == false)
	{
		printf("failed to inialize the game");
		return (1);
	}
	else
	{
		window_texture = loadTexture("./imgpng/keydefault.png");
		if (window_texture == NULL)
		{
			printf("failed to load texture\n");
			closeForTexture();
			return (1);
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
					else
					{
						SDL_RenderClear(window_renderer);
						SDL_RenderCopy(window_renderer, window_texture, NULL, NULL);
						SDL_RenderPresent(window_renderer);
					}
				}
			}
			closeForTexture();
		}
	}
}
