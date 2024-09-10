#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 720

int main( int argc, char** argv )
{
	int state = 0;
	SDL_Window* window = NULL;
	SDL_Renderer* render = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("fialed to initialize.\nError %s\n", SDL_GetError());
		state = 1;
	}
	else
	{
		window = SDL_CreateWindow("rect", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (!(window))
		{
			printf("failed to create window.\nError %s\n", SDL_GetError());
			state = 1;
		}
		else
		{
			SDL_Rect rect = {(SCREEN_WIDTH / 2) - (SCREEN_WIDTH / 8), (SCREEN_HEIGHT / 2 - (SCREEN_HEIGHT / 8)), SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4};
			SDL_Rect rect2 = {(SCREEN_WIDTH / 2) - (SCREEN_WIDTH / 4), (SCREEN_HEIGHT / 2 - (SCREEN_HEIGHT / 4)), SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
			render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if (!render)
			{
				printf("failed to create rendere.\nError: %s\n", SDL_GetError());
				state = 1;
			}
			else
			{
				SDL_Event e;
				bool quit = false;
				while (!quit)
				{
					while(SDL_PollEvent(&e))
					{
						if(e.type == SDL_QUIT)
						{
							quit = true;
						}
					}
					SDL_SetRenderDrawColor( render, 0xFF, 0xFF, 0xFF, 0xFF );
					SDL_RenderClear( render );

					SDL_SetRenderDrawColor(render, 0xff, 0, 0, 0xff);
					SDL_RenderFillRect(render, &rect);
					SDL_SetRenderDrawColor(render, 0xff, 0xff, 0 , 0xff);
					SDL_RenderDrawRect(render, &rect2);
					SDL_SetRenderDrawColor(render, 0x96, 0xa2, 0xe1 , 0xff);
					SDL_RenderDrawLine(render, SCREEN_WIDTH/2, 0, SCREEN_WIDTH/2, SCREEN_HEIGHT);
					
					for(int i = 0; i < SCREEN_HEIGHT; i+=4)
					{
						SDL_SetRenderDrawColor(render, 0x64, 0x12, 0xf3, 0xff);
						SDL_RenderDrawPoint(render, SCREEN_WIDTH/3, i);
					}
					SDL_RenderPresent(render);
				}
			}
		}
	}
	return (state);
}
