#include "item.h"

item::item()
{
    item_texture = NULL;
	item_w = 40;
	item_h = 40;
}
item::~item()
{
    disappear();
}
void item::get_diamond(SDL_Renderer* item_ren, int xxx, int yyy)
{
    SDL_Rect diamond_rect;
    diamond_rect.x = xxx;
    diamond_rect.y = yyy;
    diamond_rect.w = item_w;
    diamond_rect.h = item_h;
    SDL_Surface* diasur = NULL;
    diasur = IMG_Load("images/diamond.png");
    item_texture = SDL_CreateTextureFromSurface(item_ren, diasur);
    SDL_FreeSurface(diasur);
    SDL_RenderSetViewport(item_ren, &diamond_rect);
    SDL_RenderCopy(item_ren, item_texture, NULL, NULL);
}
void item::get_fireball(SDL_Renderer* item_ren, int xxx, int yyy)
{
    SDL_Rect fireball_rect;
    fireball_rect.x = xxx;
    fireball_rect.y = yyy;
    fireball_rect.w = item_w;
    fireball_rect.h = item_h;

    SDL_Surface* firsur = IMG_Load("images/fire ball.png");
    item_texture = SDL_CreateTextureFromSurface(item_ren, firsur);
    SDL_FreeSurface(firsur);
    SDL_RenderSetViewport(item_ren, &fireball_rect);
    SDL_RenderCopy(item_ren, item_texture, NULL, NULL);
}
void item::get_goldenheart(SDL_Renderer* item_ren, int xxx, int yyy)
{
    SDL_Rect goldenheart_rect;
    goldenheart_rect.x = xxx;
    goldenheart_rect.y = yyy;
    goldenheart_rect.w = item_w;
    goldenheart_rect.h = item_h;

    SDL_Surface* golsur = IMG_Load("images/golden heart.png");
    item_texture = SDL_CreateTextureFromSurface(item_ren, golsur);
    SDL_FreeSurface(golsur);
    SDL_RenderSetViewport(item_ren, &goldenheart_rect);
    SDL_RenderCopy(item_ren, item_texture, NULL, NULL);
}

void item::get_star(SDL_Renderer* item_ren, int xxx, int yyy)
{
    SDL_Rect star_rect;
    star_rect.x = xxx;
    star_rect.y = yyy;
    star_rect.w = item_w;
    star_rect.h = item_h;

    SDL_Surface* stasur = IMG_Load("images/star.png");
    item_texture = SDL_CreateTextureFromSurface(item_ren, stasur);
    SDL_FreeSurface(stasur);
    SDL_RenderSetViewport(item_ren, &star_rect);
    SDL_RenderCopy(item_ren, item_texture, NULL, NULL);
}

void item::get_heart(SDL_Renderer* item_ren, int xxx, int yyy)
{
    SDL_Rect heart_rect;
    heart_rect.x = xxx;
    heart_rect.y = yyy;
    heart_rect.w = item_w;
    heart_rect.h = item_h;

    SDL_Surface* heasur = IMG_Load("images/heart.png");
    item_texture = SDL_CreateTextureFromSurface(item_ren, heasur);
    SDL_FreeSurface(heasur);
    SDL_RenderSetViewport(item_ren, &heart_rect);
    SDL_RenderCopy(item_ren, item_texture, NULL, NULL);
}
//選擇
void item::choose(int index, SDL_Renderer* rr, int xxx, int yyy)
{
    switch(index)
    {
        case 0 : get_diamond(rr, xxx, yyy); break;
        case 1 : get_fireball(rr, xxx, yyy); break;
        case 2 : get_goldenheart(rr, xxx, yyy); break;
        case 3 : get_star(rr, xxx, yyy); break;
        case 4 : get_heart(rr, xxx, yyy); break;
    }
}
//道具消失
void item::disappear()
{
    if(item_texture != NULL)
	{
		SDL_DestroyTexture(item_texture);
		item_texture = NULL;
		item_w = 0;
		item_h = 0;
	}
}
