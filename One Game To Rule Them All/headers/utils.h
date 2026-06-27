#include <SDL2/SDL.h>
#include <vector>

#ifndef UTILS_H
#define UTILS_H

// draws a diamond on the screen of the given color
void draw_diamond(SDL_Renderer* renderer, int cx, int cy, int radius, int r, int g, int b);

// draws a rectangle on to the screen of given color
void draw_rect(SDL_Renderer* renderer, int x, int y, int width, int height, int r, int g, int b);

// draw a rectangle with given border size and color
void draw_border_rect(SDL_Renderer* renderer, int x, int y, int width, int height, int border_width, std::vector<int> color, std::vector<int> bd_color);


#endif