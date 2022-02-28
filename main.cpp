#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include "SDL2/SDL_ttf.h"
#include <SDL2/SDL_mixer.h>
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include <string>
#include <sstream>
#include "item.h"
#include "man.h"
#include "monster.h"

using namespace std;

bool touch(man theman , SDL_Rect THING)
{
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = theman.getpos_x();
    rightA = theman.getpos_x() + 75;
    topA = theman.getpos_y();
    bottomA = theman.getpos_y() + 75;

    //Calculate the sides of rect B
    leftB = THING.x;
    rightB = THING.x + THING.w;
    topB = THING.y;
    bottomB = THING.y + THING.h;
    if( bottomA <= topB )
    {
        return false;
    }

    if( topA >= bottomB )
    {
        return false;
    }

    if( rightA <= leftB )
    {
        return false;
    }

    if( leftA >= rightB )
    {
        return false;
    }

    //If none of the sides from A are outside B
    return true;
}

int main(int argc, char* argv[]){
    TTF_Init();
    SDL_Window * window = NULL;
    SDL_Renderer * renderer = NULL;
    SDL_Renderer * renderer2 = NULL;
    SDL_Surface * surface = NULL;
    SDL_Texture * texture = NULL;
    SDL_Event event;

    int life = 3;
    int motion = 0;
    int jump = 0;
    int score = 0;
    window = SDL_CreateWindow("image_test", 600, 60, 600, 900, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    surface = IMG_Load("images/background.png");
    texture = SDL_CreateTextureFromSurface(renderer, surface);

    srand(time_t(NULL));

    Mix_OpenAudio(128000, MIX_DEFAULT_FORMAT, 2, 2048);

    Mix_Music *bgm = NULL;

    bgm = Mix_LoadMUS( "mp3/music.mp3" );

    Mix_PlayMusic( bgm, 0 );


    man tommy;
    int yy = 0;
    /////道具
    int appeartime = 0;
    int xxx = 0;
    int yyy = 0;
    int no = 0;
    /////道具
    SDL_Rect MONSTERA;
    MONSTERA.x = 50;
    MONSTERA.y = 50;
    MONSTERA.w = 75;
    MONSTERA.h = 75;

    SDL_Rect MONSTERB;
    MONSTERB.x = 150;
    MONSTERB.y = 150;
    MONSTERB.w = 75;
    MONSTERB.h = 75;

    SDL_Rect MONSTERC;
    MONSTERC.x = 250;
    MONSTERC.y = 250;
    MONSTERC.w = 75;
    MONSTERC.h = 75;
    int top = 0;

        while(top==0){
            yy+=1;
            if(yy > surface->h)
            {
                yy = 0;
            }
            SDL_Rect roll;
            roll.x = 0;
            roll.y = yy;
            roll.w = surface->w;
            roll.h = surface->h - yy;

            SDL_Rect sq;
            sq.x = 0;
            sq.y = 0;
            sq.w = surface->w;
            sq.h = surface->h - yy;

            SDL_Rect roll2;
            roll2.x = 0;
            roll2.y = 0;
            roll2.w = surface->w;
            roll2.h = yy;

            SDL_Rect sq2;
            sq2.x = 0;
            sq2.y = surface->h - yy;
            sq2.w = surface->w;
            sq2.h = yy;

            SDL_RenderSetViewport(renderer, &roll);
            SDL_RenderCopy(renderer, texture, &sq, NULL);
            SDL_RenderSetViewport(renderer, &roll2);
            SDL_RenderCopy(renderer, texture, &sq2, NULL);

    TTF_Font *welcome = NULL;
    welcome = TTF_OpenFont("fonts/GenJyuuGothic-Regular.ttf", 300);
    TTF_SetFontStyle(welcome, TTF_STYLE_BOLD|TTF_STYLE_ITALIC);
    SDL_Color color = {30, 144, 255};
    SDL_Surface * ganasur = NULL;
    SDL_Texture * ganatex = NULL;
    SDL_Rect game_word_area;
    game_word_area.x = 100;
    game_word_area.y = 300;
    game_word_area.w = 400;
    game_word_area.h = 200;
    stringstream game_name;
    game_name.str( "" );
    game_name << "THE GAME";
    ganasur = TTF_RenderText_Solid(welcome, game_name.str().c_str(), color);
    ganatex = SDL_CreateTextureFromSurface(renderer, ganasur);
    SDL_FreeSurface(ganasur);
    SDL_RenderSetViewport(renderer, &game_word_area);
    SDL_RenderCopy(renderer, ganatex, NULL, NULL);

        SDL_DestroyTexture(ganatex);
        welcome = NULL;
        SDL_RenderPresent(renderer);
        SDL_PollEvent(&event);

    if(event.type == SDL_KEYDOWN){
        top = 1;
        yy = 0;
        SDL_DestroyTexture(ganatex);
        TTF_CloseFont(welcome);
        welcome = NULL;
        break;
    }
}

    while(1){
        SDL_RenderClear(renderer);
        if(event.type == SDL_QUIT){
            break;
        }
        else{

             while(SDL_PollEvent(&event)!=0){
               tommy.handle_event(event);
               if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_SPACE && event.key.repeat==0){
                tommy.attack(renderer);
               }
            }
            tommy.move();
            SDL_PollEvent(&event);

            /////道具
            item theitem;
            appeartime++;
            /////道具
            yy+=6;
            if(yy > surface->h)
            {
                yy = 0;
            }
            SDL_Rect roll;
            roll.x = 0;
            roll.y = yy;
            roll.w = surface->w;
            roll.h = surface->h - yy;

            SDL_Rect sq;
            sq.x = 0;
            sq.y = 0;
            sq.w = surface->w;
            sq.h = surface->h - yy;

            SDL_Rect roll2;
            roll2.x = 0;
            roll2.y = 0;
            roll2.w = surface->w;
            roll2.h = yy;

            SDL_Rect sq2;
            sq2.x = 0;
            sq2.y = surface->h - yy;
            sq2.w = surface->w;
            sq2.h = yy;

             while(SDL_PollEvent(&event)!=0){
               tommy.handle_event(event);
               if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_SPACE && event.key.repeat==0){
                tommy.attack(renderer);
               }
            }
            tommy.move();
            SDL_PollEvent(&event);

            SDL_RenderSetViewport(renderer, &roll);
            SDL_RenderCopy(renderer, texture, &sq, NULL);
            SDL_RenderSetViewport(renderer, &roll2);
            SDL_RenderCopy(renderer, texture, &sq2, NULL);


               while(SDL_PollEvent(&event)!=0){
               tommy.handle_event(event);
               if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_SPACE && event.key.repeat==0){
                tommy.attack(renderer);
               }
            }
            tommy.move();
            SDL_PollEvent(&event);

            SDL_Texture * heart_tex = NULL;
            SDL_Surface * heart_sur = IMG_Load("images/heart.png");

            SDL_Texture * noheart_tex = NULL;
            SDL_Surface * noheart_sur = IMG_Load("images/no heart.png");

            heart_tex = SDL_CreateTextureFromSurface(renderer, heart_sur);
            SDL_FreeSurface(heart_sur);

            noheart_tex = SDL_CreateTextureFromSurface(renderer, noheart_sur);
            SDL_FreeSurface(noheart_sur);

             while(SDL_PollEvent(&event)!=0){
               tommy.handle_event(event);
               if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_SPACE && event.key.repeat==0){
                tommy.attack(renderer);
               }
            }
            tommy.move();
            SDL_PollEvent(&event);

            SDL_Rect heart1_zone;
            heart1_zone.x = 20;
            heart1_zone.y = 20;
            heart1_zone.w = 30;
            heart1_zone.h = 30;

            SDL_Rect heart2_zone;
            heart2_zone.x = 50;
            heart2_zone.y = 20;
            heart2_zone.w = 30;
            heart2_zone.h = 30;

            SDL_Rect heart3_zone;
            heart3_zone.x = 80;
            heart3_zone.y = 20;
            heart3_zone.w = 30;
            heart3_zone.h = 30;

             while(SDL_PollEvent(&event)!=0){
               tommy.handle_event(event);
               if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_SPACE && event.key.repeat==0){
                tommy.attack(renderer);
               }
            }
            tommy.move();
            SDL_PollEvent(&event);

            if(life<0){
                life = 0;
            }
            if(life==0){
                SDL_RenderSetViewport(renderer, &heart1_zone);
                SDL_RenderCopy(renderer, noheart_tex, NULL, NULL);
                SDL_RenderSetViewport(renderer, &heart2_zone);
                SDL_RenderCopy(renderer, noheart_tex, NULL, NULL);
                SDL_RenderSetViewport(renderer, &heart3_zone);
                SDL_RenderCopy(renderer, noheart_tex, NULL, NULL);
            }
            if(life==1){
                SDL_RenderSetViewport(renderer, &heart1_zone);
                SDL_RenderCopy(renderer, heart_tex, NULL, NULL);
                SDL_RenderSetViewport(renderer, &heart2_zone);
                SDL_RenderCopy(renderer, noheart_tex, NULL, NULL);
                SDL_RenderSetViewport(renderer, &heart3_zone);
                SDL_RenderCopy(renderer, noheart_tex, NULL, NULL);
            }

             while(SDL_PollEvent(&event)!=0){
               tommy.handle_event(event);
               if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_SPACE && event.key.repeat==0){
                tommy.attack(renderer);
               }
            }
            tommy.move();
            SDL_PollEvent(&event);

            if(life==2){
                SDL_RenderSetViewport(renderer, &heart1_zone);
                SDL_RenderCopy(renderer, heart_tex, NULL, NULL);
                SDL_RenderSetViewport(renderer, &heart2_zone);
                SDL_RenderCopy(renderer, heart_tex, NULL, NULL);
                SDL_RenderSetViewport(renderer, &heart3_zone);
                SDL_RenderCopy(renderer, noheart_tex, NULL, NULL);
            }
            if(life==3){
                SDL_RenderSetViewport(renderer, &heart1_zone);
                SDL_RenderCopy(renderer, heart_tex, NULL, NULL);
                SDL_RenderSetViewport(renderer, &heart2_zone);
                SDL_RenderCopy(renderer, heart_tex, NULL, NULL);
                SDL_RenderSetViewport(renderer, &heart3_zone);
                SDL_RenderCopy(renderer, heart_tex, NULL, NULL);
            }

             while(SDL_PollEvent(&event)!=0){
               tommy.handle_event(event);
               if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_SPACE && event.key.repeat==0){
                tommy.attack(renderer);
               }
            }
            tommy.move();
            SDL_PollEvent(&event);

            if(appeartime == 50){
                xxx = rand()%300 + 150;
                yyy = rand()%500 + 200;
                no = rand()%5;
            }
            if(appeartime > 50 && appeartime < 100)
            {
                theitem.choose(no, renderer, xxx, yyy);
            }

            if(appeartime == 100)
            {
                theitem.disappear();
                xxx = -1;
                yyy = -1;
                appeartime = 0;
            }


            while(SDL_PollEvent(&event)!=0){
                tommy.handle_event(event);
                if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_SPACE && event.key.repeat==0){
                tommy.attack(renderer);
               }
            }
            tommy.move();
            SDL_PollEvent(&event);

            SDL_Rect Item;
            Item.x = xxx;
            Item.y = yyy;
            Item.w = 40;
            Item.h = 40;

            if(touch(tommy, Item))
            {
                theitem.disappear();
                appeartime = 0;
                xxx = 0;
                yyy = 0;

                if(no == 0)
                {
                    score += 500;
                }
                if(no == 2)
                {
                    life = 3;
                    score += 100;
                }
                if(no == 4)
                {
                    life += 1;
                    score += 100;
                }
            }

             while(SDL_PollEvent(&event)!=0){
                tommy.handle_event(event);
                if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_SPACE && event.key.repeat==0){
                tommy.attack(renderer);
               }
             }
             tommy.move();
             SDL_PollEvent(&event);

             SDL_Texture* astrotex = NULL;
             SDL_Texture* yellowtex = NULL;
             SDL_Texture* redtex = NULL;
             SDL_Texture* bluetex = NULL;

             SDL_Surface* astrosur = IMG_Load("images/astro.png");
             SDL_Surface* yellowsur = IMG_Load("images/yellow.png");
             SDL_Surface* redsur = IMG_Load("images/red.png");
             SDL_Surface* bluesur = IMG_Load("images/blue.png");

             astrotex = SDL_CreateTextureFromSurface( renderer, astrosur );
             SDL_FreeSurface(astrosur);
             yellowtex = SDL_CreateTextureFromSurface( renderer, yellowsur );
             SDL_FreeSurface(yellowsur);
             redtex = SDL_CreateTextureFromSurface( renderer, redsur );
             SDL_FreeSurface(redsur);
             bluetex = SDL_CreateTextureFromSurface( renderer, bluesur );
             SDL_FreeSurface(bluesur);

              while(SDL_PollEvent(&event)!=0){
               tommy.handle_event(event);
               if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_SPACE && event.key.repeat==0){
                tommy.attack(renderer);
               }
            }
            tommy.move();
            SDL_PollEvent(&event);

            tommy.render(*astrotex, *renderer);


            monster monster1;
            monster monster2;
            monster monster3;
             if(motion==0)
             {
                monster1.mode_a(renderer, MONSTERA.x, MONSTERA.y, MONSTERA);
                monster2.mode_a(renderer, MONSTERB.x, MONSTERB.y, MONSTERB);
                monster3.mode_a(renderer, MONSTERC.x, MONSTERC.y, MONSTERC);

                if(MONSTERA.y>900 && MONSTERB.y>900 && MONSTERC.y>900){
                    MONSTERA.x = 50;
                    MONSTERB.x = 150;
                    MONSTERC.x = 250;
                    MONSTERA.y = 0;
                    MONSTERB.y = 0;
                    MONSTERC.y = 0;
                    motion = rand()%3;
                }
             }

             else if(motion==1)
             {
                monster1.mode_b(renderer, MONSTERA.x, MONSTERA.y, MONSTERA);
                monster2.mode_b(renderer, MONSTERB.x, MONSTERB.y, MONSTERB);
                monster3.mode_b(renderer, MONSTERC.x, MONSTERC.y, MONSTERC);

                if(MONSTERA.x>600 && MONSTERB.x>600 && MONSTERC.x>600){
                    MONSTERA.x = 50;
                    MONSTERB.x = 150;
                    MONSTERC.x = 200;
                    MONSTERA.y = 0;
                    MONSTERB.y = 0;
                    MONSTERC.y = 0;
                    motion = rand()%3;
                }
             }

             else if(motion==2)
             {
                monster1.mode_c(renderer, MONSTERA.x, MONSTERA.y, MONSTERA, jump);
                monster2.mode_c(renderer, MONSTERB.x, MONSTERB.y, MONSTERB, jump);
                monster3.mode_c(renderer, MONSTERC.x, MONSTERC.y, MONSTERC, jump);
                if(MONSTERA.y>900 && MONSTERB.y >900 && MONSTERC.y >900){
                    MONSTERA.x = 50;
                    MONSTERB.x = 150;
                    MONSTERC.x = 250;
                    MONSTERA.y = 0;
                    MONSTERB.y = 0;
                    MONSTERC.y = 0;
                    motion = rand()%3;
                    jump = 0;
                }
             }

             SDL_RenderSetViewport(renderer, &MONSTERA);
             SDL_RenderCopy(renderer, yellowtex, NULL, NULL);
             SDL_RenderSetViewport(renderer, &MONSTERB);
             SDL_RenderCopy(renderer, redtex, NULL, NULL);
             SDL_RenderSetViewport(renderer, &MONSTERC);
             SDL_RenderCopy(renderer, bluetex, NULL, NULL);
             ////////////////////////////////////////////////////////////////////////////

    TTF_Font *font = NULL;
    font = TTF_OpenFont("fonts/GenJyuuGothic-Regular.ttf", 100);
    TTF_SetFontStyle(font, TTF_STYLE_BOLD|TTF_STYLE_ITALIC);
    SDL_Color color = {30, 144, 255};
    SDL_Surface * wordsur = NULL;
    SDL_Texture * wordtex = NULL;
    SDL_Rect aaaaa;
    aaaaa.x = 400;
    aaaaa.y = 0;
    aaaaa.w = 100;
    aaaaa.h = 50;
    stringstream thescore;
    thescore.str( "" );
    thescore << "SCORE : " << score;
    wordsur = TTF_RenderText_Solid(font, thescore.str().c_str(), color);
    wordtex = SDL_CreateTextureFromSurface(renderer, wordsur);
    SDL_FreeSurface(wordsur);
    SDL_RenderSetViewport(renderer, &aaaaa);
    SDL_RenderCopy(renderer, wordtex, NULL, NULL);

            while(touch(tommy, MONSTERA) || touch(tommy, MONSTERB) || touch(tommy, MONSTERC)){
                life--;
                break;
            }


             TTF_CloseFont(font);
             font = NULL;
             SDL_DestroyTexture(wordtex);
             SDL_DestroyTexture(redtex);
             SDL_DestroyTexture(bluetex);
             SDL_DestroyTexture(yellowtex);

             SDL_DestroyTexture(astrotex);
             SDL_DestroyTexture(noheart_tex);
             SDL_DestroyTexture(heart_tex);

             SDL_RenderPresent(renderer);

        }
    }

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    TTF_Quit();
    IMG_Quit();
    SDL_Quit();

    return 0;
}
