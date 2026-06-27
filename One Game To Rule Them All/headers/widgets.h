#include <SDL2/SDL.h>
#include <vector>


#ifndef WIDGETS_H
#define WIDGETS_H


class Button{
    private:
    std::vector<int> color = {110, 0, 110};
    std::vector<int> hover_color = {200, 0, 200};
    int curr_color = 0;

    public:
    int x, y, width, height, id;
    const char* text;
    void (*command)(int);
    Button(const char* text, int x, int y, int width, int height, int id, void (*command)(int));
    void draw(SDL_Renderer* renderer);
    void update();
};;


#endif