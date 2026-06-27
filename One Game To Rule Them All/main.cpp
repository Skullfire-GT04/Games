#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "headers/utils.h"
#include "headers/widgets.h"
#include "headers/game.h"

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 800
#define FPS 60


static int curr_game = NULL;
static std::vector<Game> games;


void temp(int id){
    curr_game = id;
}


class Window{

    public:

    int window_width, window_height;
    SDL_Event event;
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool running;
    std::vector<Button> game_btns;


    Window(int w, int h, const char* title){

        TTF_Init();
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
        SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

        game_btns.push_back(Button("Tetris", 10, 10, 200, 50, 0, temp));

    }

    
    void run(){
        while(this->running){
            while(SDL_PollEvent(&event)){
                if((event.type == SDL_QUIT || event.type == SDL_KEYDOWN && event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)){
                    this->running = false;
                }
                if(event.type == SDL_KEYDOWN && event.key.keysym.scancode == SDL_SCANCODE_K){
                    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Hello there!", "This is my personal game-boy it will have many games in the future, pls come back again!", this->window);
                }
            }

            Uint64 start_time = SDL_GetTicks64();

            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);            
            
            // updating the button state of the game-boy and
            // drawing the game-boy buttons which will help the user
            // to choose a game
            for(auto btn : game_btns){
                btn.update();
                btn.draw(this->renderer);
            }

            if(curr_game){
                games[curr_game].update();
                games[curr_game].draw(renderer);
            }

            SDL_RenderPresent(renderer);

            Uint64 end_time = SDL_GetTicks64();

            if((1000 / FPS) > (end_time - start_time)){
                SDL_Delay((1000 / FPS) - (end_time - start_time));
            }
        }
    }

};


int main(){

    std::cout << "Hello from Game Boy v.1.1" << std::endl;
    Window a(WINDOW_WIDTH, WINDOW_HEIGHT, "One game to rule them all");
    a.run();

    return 0;
}