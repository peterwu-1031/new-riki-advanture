#include "man.h"

man::man(){
    manpos_x = 250;
    manpos_y = 600;
    manv_x = 0;
    manv_y = 0;
}

void man::handle_event(SDL_Event &e){

    if(e.type == SDL_KEYDOWN){

        if(e.key.keysym.sym==SDLK_w){
            manv_y=-1;
        }
        if(e.key.keysym.sym==SDLK_s){
            manv_y=1;
        }
        if(e.key.keysym.sym==SDLK_a){
            manv_x=-1;
        }
        if(e.key.keysym.sym==SDLK_d){
            manv_x=1;
        }
    }

    else if(e.type == SDL_KEYUP){

        if(e.key.keysym.sym==SDLK_w){
            if(manv_y==-1) manv_y=0;
        }
        if(e.key.keysym.sym==SDLK_s){
            if(manv_y==1) manv_y=0;
        }
        if(e.key.keysym.sym==SDLK_a){
            if(manv_x==-1) manv_x=0;
        }
        if(e.key.keysym.sym==SDLK_d){
            if(manv_x==1) manv_x=0;
        }
    }

}

void man::move()
{
    manpos_x += manv_x;

    //If the dot went too far to the left or right
    if( ( manpos_x < 0 ) || ( manpos_x + 75 > 600 ) )
    {
        //Move back
        manpos_x -= manv_x;
    }
     //Move the dot up or down
    manpos_y += manv_y;

    //If the dot went too far up or down
    if( ( manpos_y < 0 ) || ( manpos_y + 75 > 900 ) )
    {
        //Move back
        manpos_y -= manv_y;
    }
}


void man::render(SDL_Texture &tex, SDL_Renderer &ren){
    SDL_Rect Quad;
    Quad.x = manpos_x;
    Quad.y = manpos_y;
    Quad.w = 75;
    Quad.h = 75;
    SDL_RenderSetViewport(&ren, &Quad);
    SDL_RenderCopy(&ren, &tex, NULL, NULL);
}

int man::getpos_x()
{
    return manpos_x;
}
int man::getpos_y()
{
    return manpos_y;
}

void man::attack(SDL_Renderer* att_ren)
{
    SDL_Rect att_rect;
    att_rect.x = manpos_x + 25;
    att_rect.y = manpos_y - 30;
    att_rect.w = 30;
    att_rect.h = 30;

    SDL_Surface* attsur = IMG_Load("images/attack.png");
    att_texture = SDL_CreateTextureFromSurface(att_ren, attsur);
    SDL_FreeSurface(attsur);
    SDL_RenderSetViewport(att_ren, &att_rect);
    SDL_RenderCopy(att_ren, att_texture, NULL, NULL);
}
