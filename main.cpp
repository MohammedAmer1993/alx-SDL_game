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
	SDL_Rect arr[4];
	SDL_Rect renderQuad;

	arr[0] = {15, 15, 104, 86};
	arr[1] = {126, 29, 69, 72};
	arr[2] = {13, 110, 153, 77};
	arr[3] = {207, 30, 99, 69};


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
						renderQuad.x = arr[0].x;
						renderQuad.y = arr[0].y;
						renderQuad.w = arr[0].w * 2;
						renderQuad.h = arr[0].h * 2;

						SDL_RenderCopy(window_renderer, window_texture1, &arr[0], &renderQuad);
						renderQuad.x = SCREEN_WIDTH - arr[1].w * 2;
						renderQuad.y = arr[1].y;
						renderQuad.w = arr[1].w * 2;
						renderQuad.h = arr[1].h * 2;

						SDL_RenderCopy(window_renderer, window_texture1, &arr[1], &renderQuad);

						renderQuad.x = arr[2].x;
						renderQuad.y = SCREEN_HEIGHT - arr[2].h * 2;
						renderQuad.w = arr[2].w * 2;
						renderQuad.h = arr[2].h * 2;

						SDL_RenderCopy(window_renderer, window_texture1, &arr[2], &renderQuad);

						renderQuad.x = SCREEN_WIDTH - arr[3].w * 2;
						renderQuad.y = SCREEN_HEIGHT - arr[3].h * 2;
						renderQuad.w = arr[3].w * 2;
						renderQuad.h = arr[3].h * 2;

						SDL_RenderCopy(window_renderer, window_texture1, &arr[3], &renderQuad);
						SDL_RenderPresent(window_renderer);
					}
				}
			}
			close(main_window, window_renderer, window_texture1, window_texture2);
			return (0);
		}
	}
}
