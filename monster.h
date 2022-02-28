#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include "SDL2/SDL_ttf.h"
#include <SDL2/SDL_mixer.h>
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include <string>
#include <sstream>

class monster_yellow
{
public:
    monster_yellow();
    ~monster_yellow();

    void mode_a(SDL_Renderer*, int&, int&, SDL_Rect);
    void mode_b(SDL_Renderer*, int&, int&, SDL_Rect);
    void mode_c(SDL_Renderer*, int&, int&, SDL_Rect, int&);

    void choose_mode(int&, SDL_Renderer*,int&, SDL_Rect ,int&);

    void monster_die();

    void destroy_all();

private:
    SDL_Texture* monster_texture;
    int monster_w;
    int monster_h;
};

class monster_blue : public monster_yellow
{
    public:
        monster_blue();
        ~monster_blue();
        void choose_mode_blue(int&, SDL_Renderer*,int&,SDL_Rect, int&);
    private:
        SDL_Texture* monster_texture;
        int monster_w;
        int monster_h;

};

class monster_red : public monster_yellow
{
    public:
        monster_red();
        ~monster_red();
        void choose_mode_red(int&, SDL_Renderer*,int&,SDL_Rect ,int&);

    private:
        SDL_Texture* monster_texture;
        int monster_w;
        int monster_h;
};
