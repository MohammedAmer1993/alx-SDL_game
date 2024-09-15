#include "inc/maze.h"


int main( int argc, char** argv )
{
	(void) argc;
	(void) argv;
	SDL_Window* main_window = NULL;
	SDL_Renderer* window_renderer = NULL;
	SDL_Texture* window_texture1 = NULL;
	SDL_Texture* window_texture2 = NULL;
	int w = 0;
	int h = 0;

	// SDL_RendererFlip flip = SDL_FLIP_HORIZONTAL;
	// double angle = 0;
	// SDL_Point point = {0, 0};

    if (init(&main_window, &window_renderer) == false)
	{
		printf("failed to inialize the game");
		return (1);
	}
	else
	{
		if(load(&window_texture1, &window_texture2, window_renderer, &w, &h))
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
				SDL_Rect view = {0, 0, w, h};
				SDL_Rect clip = {0, 0, w, h};
				SDL_SetRenderDrawColor(window_renderer,0xff, 0xff, 0xff, 0xff);
				SDL_RenderClear(window_renderer);
				SDL_RenderCopy(window_renderer, window_texture1, &clip, &view);
				SDL_RenderPresent(window_renderer);
				}
			}
		}
	}
	close(main_window, window_renderer, window_texture1, window_texture2);
	return (0);
}







/*
	THIS WAS FOR ANIMATING SPRITES I WILL COME BACK LATER TO MAKE IT FUNCTION AND MAKE IT MODULAR
#define WALKING_FRAME 5
	SDL_Rect clip;make
	SDL_Rect arr[WALKING_FRAME];
	int frame = 0;
	arr[0]= {0, 0, 172, 183};
	arr[1]= {172, 0, 172, 183};
	arr[2]= {344, 0, 172, 183};
	arr[3]= {516, 0, 172, 183};
	arr[4]= {688, 0, 172, 183};

	clip = {widPos(arr[0]), hiPos(arr[0]), 172, 183};

				frame++;
				if (frame / 5 >= WALKING_FRAME)
				{
					frame = 0;
				}
				SDL_RenderCopy(window_renderer, window_texture1, &(arr[frame / 5]), &clip);
*/
