#include <SDL2/SDL.h>
#include <vector>

#ifndef GAME_H
#define GAME_H


// a generic template for games defined for this game-boy
class Game{

    private:
    std::vector<int> game_bg = {100, 100, 100};

    public:
    int x, y, width, height;

    Game(int x, int y, int width, int height);
    void draw(SDL_Renderer* renderer);
    void update();
};

#endif