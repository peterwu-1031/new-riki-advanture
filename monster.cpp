#include "monster.h"

monster_yellow::monster_yellow()
{
    monster_w=0;
    monster_h=0;

}

monster_yellow::~monster_yellow()
{
    monster_w=0;
    monster_h=0;
}

void monster_yellow::mode_a(SDL_Renderer* renderer, int &mx, int &my, SDL_Rect monpos)
{
    my += 50;
    SDL_RenderSetViewport(renderer, &monpos);
}

void monster_yellow::mode_b(SDL_Renderer* renderer, int &mx, int &my, SDL_Rect monpos)
{
    mx += 11;
    my += 18;
    SDL_RenderSetViewport(renderer, &monpos);
}

void monster_yellow::mode_c(SDL_Renderer* renderer, int &mx, int &my, SDL_Rect monpos, int& jump)
{
    my += 50;
    if(jump%2==0){
        mx += 20;
        SDL_RenderSetViewport(renderer, &monpos);
        jump++;
    }
    else if(jump%2!=0){
        mx -= 20;
        SDL_RenderSetViewport(renderer, &monpos);
        jump++;
    }
}
void monster_yellow::choose_mode(int &mx, SDL_Renderer* renderer, int &my,SDL_Rect monpos, int &jump)
{
    srand(time(NULL));
    int t=rand()%6;
        // SDL_Rect MONSTERA;
       // MONSTERA.x = 50;
       // MONSTERA.y = 50;
       // MONSTERA.w = 75;
       // MONSTERA.h = 75;

    switch(t){
        case 0:
            if(my<900){
                mode_a( renderer, mx, my, monpos);
            }
            else{
                mx=50;
                my=0;
            }
            break;
        case 1:
            if(mx<600){
                mode_b( renderer, mx, my, monpos);
            }
            else{
                mx=50;
                my=0;
            }
            break;
        case 2:
            if(my<900){
                mode_c( renderer, mx, my, monpos,jump);
            }
            else{
                mx=50;
                my=0;
                jump=0;
            }
            break;
        case 3:
            if(my<900){
                mode_c( renderer, mx, my, monpos,jump);
            }
            else{
                mx=50;
                my=0;
                jump=0;
            }
            break;
        case 4:
            if(mx<600){
                mode_b( renderer, mx, my, monpos);
            }
            else{
                mx=50;
                my=0;
            }
            break;
        case 5:
            if(my<900){
                mode_a( renderer, mx, my, monpos);
            }
            else{
                mx=50;
                my=0;
            }
            break;
    }

}

void monster_yellow::monster_die()
{
    if(monster_texture != NULL)
    {
        SDL_DestroyTexture(monster_texture);
        monster_texture = NULL;
        monster_w = 0;
        monster_h = 0;
    }
}

void monster_yellow::destroy_all()
{

}
monster_blue::monster_blue()
{
    monster_h=0;
    monster_w=0;
}
monster_blue::~monster_blue()
{
    monster_h=0;
    monster_w=0;
}
void monster_blue::choose_mode_blue(int &mx, SDL_Renderer* renderer, int &my, SDL_Rect monpos ,int &jump)
{
    srand(time(NULL));
    int t=rand()%3;

   // SDL_Rect MONSTERB;
   // MONSTERB.x = 150;
   // MONSTERB.y = 150;
   // MONSTERB.w = 75;
   // MONSTERB.h = 75;

    switch(t){
        case 0:
            if(my<900){
                mode_a( renderer, mx, my, monpos);
            }
            else{
                mx=150;
                my=0;
            }
            break;
        case 1:
            if(mx<600){
                mode_b( renderer, mx, my, monpos);
            }
            else{
                mx=150;
                my=0;
            }
            break;
        case 2:
            if(my<900){
                mode_c( renderer, mx, my, monpos,jump);
            }
            else{
                mx=150;
                my =0;
                jump=0;
            }
            break;
    }


}
monster_red::monster_red(){
    monster_w=0;
    monster_h=0;
}
monster_red::~monster_red(){
    monster_w=0;
    monster_h=0;
}
void monster_red::choose_mode_red(int &mx, SDL_Renderer* renderer, int &my, SDL_Rect monpos,int &jump)
{
    srand(time(NULL));
    int t=rand()%3;

   // SDL_Rect MONSTERC;
   // MONSTERC.x = 250;
   // MONSTERC.y = 250;
   // MONSTERC.w = 75;
   // MONSTERC.h = 75;

    switch(t){
        case 0:
            if(my<900){
                mode_a( renderer, mx, my, monpos);
            }
            else{
                mx=250;
                my=0;
            }
            break;
        case 1:
            if(mx<600){
                mode_b( renderer, mx, my, monpos);
            }
            else{
                mx=250;
                my=0;
            }
            break;
        case 2:
            if(my<900){
                mode_c( renderer, mx, my, monpos,jump);
            }
            else{
                mx=250;
                my=0;
                jump=0;
            }
            break;
    }




}
