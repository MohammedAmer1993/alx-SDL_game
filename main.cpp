#include "inc/maze.h"


SDL_Surface* keyarr[total];

int main( int argc, char** argv )
{
	(void) argc;
	(void) argv;
	SDL_Window* main_window = NULL;
	SDL_Renderer* window_renderer = NULL;
	SDL_Texture* window_texture1 = NULL;
	SDL_Texture* window_texture2 = NULL;

    if (init(&main_window, &window_renderer) == false)
	{
		printf("failed to inialize the game");
		return (1);
	}
	else
	{
		if(load(&window_texture1, &window_texture2, window_renderer))
		{
			printf("program failed\n");
			close(main_window, window_renderer, window_texture1, window_texture2);
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
						SDL_SetRenderDrawColor(window_renderer,0xff, 0xff, 0xff, 0xff);
						SDL_RenderClear(window_renderer);
						SDL_RenderCopy(window_renderer, window_texture1, NULL, NULL);
						SDL_RenderCopy(window_renderer, window_texture2, NULL, NULL);
						SDL_RenderPresent(window_renderer);
					}
				}
			}
			close(main_window, window_renderer, window_texture1, window_texture2);
			return (0);
		}
	}
}
