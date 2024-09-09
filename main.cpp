#include "def.h"

SDL_Window * main_window = NULL;
SDL_Surface * main_surface = NULL;
SDL_Surface * img_surface = NULL;
SDL_Surface * keyarr[total];

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
