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

	Uint8 R = 255;
	Uint8 G = 255;
	Uint8 B = 255;


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
					else if (e.type == SDL_KEYDOWN)
					{
						switch (e.key.keysym.sym)
						{
						case SDLK_w:
							R += 70;
							break;
						case SDLK_s:
							R -= 70;
							break;
						case SDLK_d:
							G += 70;
							break;
						case SDLK_a:
							G -= 70;
							break;
						case SDLK_z:
							B += 70;
							break;
						case SDLK_r:
							B -= 70;
							break;
						default:
							break;
						}
					}
						SDL_SetRenderDrawColor(window_renderer,0xff, 0xff, 0xff, 0xff);
						SDL_RenderClear(window_renderer);
						SDL_SetTextureColorMod(window_texture1, R, G, B);
						SDL_RenderCopy(window_renderer, window_texture1, NULL, NULL);
						SDL_RenderPresent(window_renderer);
				}
			}
			close(main_window, window_renderer, window_texture1, window_texture2);
			return (0);
		}
	}
}
