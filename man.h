#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include "SDL2/SDL_ttf.h"
#include <SDL2/SDL_mixer.h>
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include <string>
#include <sstream>

class man{
public:
    static const int movement = 2;

    man();
    void handle_event(SDL_Event &e);
    void move();
    void render(SDL_Texture &tex, SDL_Renderer &ren);
    int getpos_x();
    int getpos_y();
    void attack(SDL_Renderer* att_ren);

private:
    int manpos_x,manpos_y;
    int manv_x,manv_y;
    SDL_Texture* att_texture = NULL;
};
