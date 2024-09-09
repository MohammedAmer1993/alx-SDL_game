#ifndef	DEF_H_ 
#define DEF_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768



enum key {
	keydefault, keyup, keydown, keyright, keyleft, total
};

extern SDL_Window * main_window;
extern SDL_Surface * main_surface;
extern SDL_Surface * img_surface;
extern SDL_Surface * keyarr[total];

int init();
SDL_Surface * loadOneSurface(std::string path);
int load();
void close();

#endif //DEF_H_ GUARD
