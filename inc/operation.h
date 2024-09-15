#ifndef OPER_H_
#define OPER_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include "def.h"
#include "util.h"

int init(SDL_Window** main_window, SDL_Renderer** window_renderer);
int load(SDL_Texture** texture1, SDL_Texture** texture2, SDL_Renderer* renderer, int* w, int* h);
void close(SDL_Window* main_window, SDL_Renderer* window_renderer, SDL_Texture* text1, SDL_Texture* text2);

#endif //OPER_H_
