#include <iostream>
#include <stdbool.h>
#include <SDL2/SDL.h>

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 800


class Game{

    public:

    int window_width, window_height;
    SDL_Event event;
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool running;

    Game(int w, int h, const char* title){

        if(SDL_Init(SDL_INIT_VIDEO) < 0){
            std::cerr << "Failed to initialize sdl" << std::endl;
            return;
        }

        this->window_width = w;
        this->window_height = h;
        this->running = true;
        this->window = SDL_CreateWindow(title, 0, 0, w, h, SDL_WINDOW_SHOWN);
        
        if(!window){
            std::clog << "Failed to create window!" << std::endl;
            this->running = false;
            return;
        }

        this->renderer = SDL_CreateRenderer(this->window, -1, 0);

        if(!this->renderer){
            std::clog << "Failed to create renderer!" << std::endl;
            this->running = false;
            return;
        }
        
    }

    void run(){
        while(this->running){
            while(SDL_PollEvent(&event)){
                if(event.type == SDL_KEYDOWN && event.key.keysym.scancode == SDL_SCANCODE_ESCAPE){
                    this->running = false;
                }
            }
        }
    }

};


int main(){

    std::cout << "Hello from Game Boy v.1.1" << std::endl;
    Game a = Game(WINDOW_WIDTH, WINDOW_HEIGHT, "One Game To Rule Them All");
    a.run();

    return 0;
}