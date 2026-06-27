#include <SDL2/SDL.h>
#include <iostream>
#include "../headers/utils.h"
#include "../headers/widgets.h"


Button::Button(const char* text, int x, int y, int width, int height, int id, void (*command)(int)){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->command = command;
    this->text = text;
    this->id = id;
}

void Button::draw(SDL_Renderer* renderer){
    SDL_Rect rect;
    rect.x = this->x;
    rect.y = this->y;
    rect.w = this->width;
    rect.h = this->height;

    switch(this->curr_color){
        case 0: 
            SDL_SetRenderDrawColor(renderer, this->color[0], this->color[1], this->color[2], 255);
            break;
        case 1:
            SDL_SetRenderDrawColor(renderer, this->hover_color[0], this->hover_color[1], this->hover_color[2], 255);
            break;
    }
    SDL_RenderFillRect(renderer, &rect);
}

void Button::update(){
    int x, y;
    Uint32 buttons = SDL_GetMouseState(&x, &y);

    // adding a hovering utility to the button
    if(this->x <= x && this->x + this->width >= x){
        if(this->y <= y && this->y + this->height >= y){
            this->curr_color = 1;
        }else this->curr_color = 0;
    }else this->curr_color = 0;

    if(buttons & SDL_BUTTON(SDL_BUTTON_LEFT)){
        this->command(this->id);
    }
    
}