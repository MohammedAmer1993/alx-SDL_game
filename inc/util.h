#ifndef UTIL_H_
#define UTIL_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include "def.h"

int loadImgArr(SDL_Surface* keyarr[], SDL_Surface* img_surface);
SDL_Surface* loadOneSurface(std::string path);
SDL_Surface* optimizeSurface(SDL_Surface* surface, SDL_PixelFormat* fmt);
void closeImgArr(SDL_Window* main_window, SDL_Surface* main_surface, SDL_Surface** keyarr);
SDL_Texture* createTexture(SDL_Renderer* window_renderer,SDL_Surface* loadedSurface);
void closeTexture (SDL_Texture* window_texture);
void closeWindow(SDL_Window* main_window);
void closeRenderer(SDL_Renderer* window_renderer);


#endif //UTIL_H_
