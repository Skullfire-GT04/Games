#include <SDL2/SDL.h>
#include "../headers/game.h"
#include "../headers/utils.h"


Game::Game(int x, int y, int width, int height){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

void Game::draw(SDL_Renderer* renderer){    
    draw_rect(renderer, this->x, this->y, this->width, this->height, this->game_bg[0], this->game_bg[1], this->game_bg[2]);
}

void Game::update(){

}