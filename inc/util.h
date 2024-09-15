#ifndef UTIL_H_
#define UTIL_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string>
#include "def.h"

int loadImgArr(SDL_Surface* keyarr[]);
SDL_Surface* loadOneSurface(std::string path);
SDL_Surface* optimizeSurface(SDL_Surface* surface, SDL_PixelFormat* fmt);
void closeImgArr(SDL_Window* main_window, SDL_Surface* main_surface, SDL_Surface** keyarr);
SDL_Texture* createTexture(SDL_Renderer* window_renderer,SDL_Surface* loadedSurface);
void closeTexture (SDL_Texture* window_texture);
void closeWindow(SDL_Window* main_window);
void closeRenderer(SDL_Renderer* window_renderer);
int widPos(SDL_Rect clip);
int hiPos(SDL_Rect clip);
SDL_Surface* createSurfaceFromFont(std::string path, int size, std::string str, SDL_Color color, int* w, int* h);
#endif //UTIL_H_
