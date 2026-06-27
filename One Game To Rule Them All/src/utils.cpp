#include <SDL2/SDL.h>
#include <vector>
#include "../headers/utils.h"



void draw_diamond(SDL_Renderer* renderer, int cx, int cy, int radius, int r, int g, int b){
    if(radius < 1) return;
    int line_width = radius;
    int x = cx, y1 = cy, y2 = cy;
    int count = 0;
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    while(line_width > 0 && y1 > cy - radius){
        SDL_RenderDrawLine(renderer, x, y1, x + line_width, y1);
        SDL_RenderDrawLine(renderer, x - line_width, y1, x, y1);
        SDL_RenderDrawLine(renderer, x, y2, x + line_width, y2);
        SDL_RenderDrawLine(renderer, x - line_width, y2, x, y2);
        y1--;
        y2++;
        count++;
        line_width--;
    }
}


void draw_rect(SDL_Renderer* renderer, int x, int y, int width, int height, int radius, int r, int g, int b){
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = width;
    rect.h = height;
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    SDL_RenderFillRect(renderer, &rect);
}


void draw_border_rect(SDL_Renderer* renderer, int x, int y, int width, int height, int border_width, std::vector<int> color, std::vector<int> bd_color){
    if(color.size() < 3 || bd_color.size() < 3) return;

    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = width;
    rect.h = height;
    SDL_SetRenderDrawColor(renderer, bd_color[0], bd_color[1], bd_color[2], 255);
    SDL_RenderFillRect(renderer, &rect);
    
    rect.x += border_width;
    rect.y += border_width;
    rect.w -= 2 * border_width;
    rect.h -= 2 * border_width;

    SDL_SetRenderDrawColor(renderer, color[0], color[1], color[2], 255);
    SDL_RenderFillRect(renderer, &rect);
}