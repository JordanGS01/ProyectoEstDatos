#include <time.h>
#include <stdio.h>     
#include <stdlib.h> 
#include <SDL_audio.h>
#include "Header.h"


int main(int argc, char** argv)
{

    bool quit = false;
    SDL_Event event;
    srand(time(NULL));
    int random;
    int matriz[20][25] = { { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
                          { 1,0,1,0,0,0,0,0,0,1,0,1,1,0,1,0,1,0,1,0,0,0,1,0,1 },
                          { 1,0,0,0,1,1,1,1,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1 },
                          { 1,1,0,0,0,0,0,0,0,3,0,0,1,0,1,1,1,0,1,0,0,0,1,0,1 },
                          { 1,0,0,0,1,1,1,1,1,0,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1 },
                          { 1,0,1,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1 },
                          { 1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,3,1,0,1,0,1 },
                          { 1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,1,1,0,1,0,1,0,1,0,1 },
                          { 1,0,1,0,0,0,1,1,1,0,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1 },
                          { 1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,1,0,0,0,1,1,1,0,1 },
                          { 1,0,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1,1,1,0,1,0,0,0,1 },
                          { 1,0,1,0,1,1,1,0,0,3,0,0,1,0,0,0,1,0,1,0,1,0,1,0,1 },
                          { 1,0,1,0,0,0,1,1,1,0,1,0,1,0,1,1,1,0,1,0,1,0,1,0,1 },
                          { 1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,1 },
                          { 1,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1 },
                          { 1,0,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,1 },
                          { 1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,0,1 },
                          { 1,1,0,1,0,1,1,1,1,1,1,0,1,0,1,1,1,0,1,0,0,0,1,0,1 },
                          { 1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,1,0,1,0,1,0,1 },
                          { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
    };


    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    IMG_Init(IMG_INIT_PNG);
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) < 0) {
        std::cout << "Error" << Mix_GetError();
    }
    Mix_Music* bgm = Mix_LoadMUS("Lich yard.mp3");
    Mix_Chunk* sound = Mix_LoadWAV("Explosion.wav");
    Mix_Chunk* sound_Recompensa = Mix_LoadWAV("recompensa.wav");
    int coordenadas_recompensa[3][2];
    int vidas = 3;
    SDL_Window* window = SDL_CreateWindow("Juego 2D",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800,
        640, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Surface* pers2 = IMG_Load("pers2.png");
    SDL_Surface* image = IMG_Load("asda(1).png");
    SDL_Surface* vent = SDL_GetWindowSurface(window);
    SDL_Surface* fondo = IMG_Load("new-wall.png");
    SDL_Surface* recompensa = IMG_Load("oro(1).png");
    SDL_Surface* minotauro = IMG_Load("minotauro(1).png");
    SDL_Surface* explosion = IMG_Load("explosion.png");
    SDL_Texture* textura_Enemigo = SDL_CreateTextureFromSurface(renderer, minotauro);
    SDL_Texture* textura2 = SDL_CreateTextureFromSurface(renderer, fondo);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_Texture* textura_recompensa = SDL_CreateTextureFromSurface(renderer, recompensa);
    SDL_Texture* textura_pj2 = SDL_CreateTextureFromSurface(renderer, pers2);
    SDL_Texture* texturaExplosion = SDL_CreateTextureFromSurface(renderer, explosion);
    int rec = 0;
    while (rec < 3) {
        for (int row = 0; row < 20; row++) {
            for (int column = 0; column < 25; column++) {
                random = rand() % 100;
                if (random < 3 && matriz[row][column] == 0) {
                    matriz[row][column] = 2;
                    coordenadas_recompensa[rec][0] = column * 32;
                    coordenadas_recompensa[rec][1] = row * 32;
                    rec++;
                }
                if (rec >= 3) {
                    break;
                }
            }
        }
    }
    int x = 32;
    int y = 32;
    int pj2_x = 32;
    int pj2_y = 64;
    int tipo_movimiento = 0;
    int tipo_movimiento2 = 64;
    int tick = 1;
    int tick2 = 1;
    Mix_PlayMusic(bgm, -1);

    while (vidas != 0)
    {

        int pintar_x = 0;
        int pintar_y = 0;
        bool muerte = false;
        bool muerte2 = false;
        Uint32 ticks = SDL_GetTicks();
        Uint32 sprite2 = (ticks / 100) % tick2;
        Uint32 sprite = (ticks / 100) % tick;
        Uint32 temp_explosion = (ticks / 100) % 4;
        SDL_Rect laberinto = { pintar_x,pintar_y,32,32 };
        SDL_Rect srcrect = { tipo_movimiento, (sprite * 32) + 0, 32, 32 };
        SDL_Rect dstrect = { x, y, 32, 32 };
        SDL_Rect dimensiones_pj2 = { (sprite2 * 32),tipo_movimiento2,32,32 };
        SDL_Rect dimensionesV_pj2 = { pj2_x,pj2_y,32,32 };
        SDL_Rect dimensiones_exp = { (temp_explosion * 32),0,32,32 };
        SDL_PollEvent(&event);
        for (int row = 0; row < 20; row++) {
            for (int column = 0; column < 25; column++) {
                switch (matriz[row][column])
                {
                case 1:
                    SDL_RenderCopy(renderer, textura2, NULL, &laberinto);
                    break;
                case 2:
                    SDL_RenderCopy(renderer, textura_recompensa, NULL, &laberinto);
                    break;
                case 3:
                    SDL_RenderCopy(renderer, textura_Enemigo, NULL, &laberinto);
                    break;
                }
                laberinto.x += 32;
            }
            laberinto.x = 0;
            laberinto.y += 32;
        }
        tick = 1;
        tick2 = 1;
        switch (event.type)
        {
        case SDL_QUIT:
            quit = true;
            break;

        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_RIGHT:
                if (x < 800 - 32) {
                    tipo_movimiento = 96;
                    tick = 4;
                    x += 4;
                    comprobarRecompensa(x, y, coordenadas_recompensa, matriz, sound_Recompensa);
                    SDL_Delay(30);
                    break;
                }
                break;

            case SDLK_LEFT:
                if (x > 0) {
                    tipo_movimiento = 32;
                    tick = 4;
                    x = x - 4;
                    comprobarRecompensa(x, y, coordenadas_recompensa, matriz, sound_Recompensa);
                    SDL_Delay(30);
                    break;
                }
                break;

            case SDLK_UP:
                if (y > 0)
                {
                    tick = 4;
                    tipo_movimiento = 64;
                    y = y - 4;
                    comprobarRecompensa(x, y, coordenadas_recompensa, matriz, sound_Recompensa);
                    SDL_Delay(30);
                    break;
                }
                break;
            case SDLK_DOWN:
                if (y < 600 - 32) {
                    tick = 4;
                    tipo_movimiento = 0;
                    y += 4;
                    comprobarRecompensa(x, y, coordenadas_recompensa, matriz, sound_Recompensa);
                    SDL_Delay(30);
                    break;
                }
                break;

            case SDLK_s:
                if (pj2_x < 800 - 32) {
                    tipo_movimiento2 = 64;
                    tick2 = 3;
                    pj2_y += 4;
                    comprobarRecompensa(pj2_x, pj2_y, coordenadas_recompensa, matriz, sound_Recompensa);
                    SDL_Delay(30);
                    break;
                }
                break;

            case SDLK_a:
                if (pj2_x > 0) {
                    tipo_movimiento2 = 96;
                    tick2 = 3;
                    pj2_x = pj2_x - 4;
                    comprobarRecompensa(pj2_x, pj2_y, coordenadas_recompensa, matriz, sound_Recompensa);
                    SDL_Delay(30);
                    break;
                }
                break;

            case SDLK_w:
                if (pj2_y > 0)
                {
                    tick2 = 3;
                    tipo_movimiento2 = 0;
                    pj2_y = pj2_y - 4;
                    comprobarRecompensa(pj2_x, pj2_y, coordenadas_recompensa, matriz, sound_Recompensa);
                    SDL_Delay(30);
                    break;
                }
                break;
            case SDLK_d:
                if (pj2_y < 600 - 32) {
                    tick2 = 3;
                    tipo_movimiento2 = 32;
                    pj2_x += 4;
                    comprobarRecompensa(pj2_x, pj2_y, coordenadas_recompensa, matriz, sound_Recompensa);
                    SDL_Delay(30);
                    break;
                }
                break;
            case SDLK_m:
                muerte = true;
                --vidas;
                break;
            case SDLK_k:
                muerte2 = true;
                --vidas;
                break;
            }
        }

        if (muerte == true) {
            SDL_RenderCopy(renderer, texturaExplosion, &dimensiones_exp, &dstrect);
            SDL_RenderPresent(renderer);
            Mix_PlayChannel(-1, sound, 0);
            SDL_Delay(1000);
            x = 32;
            y = 32;
        }
        else {
            SDL_RenderCopy(renderer, texture, &srcrect, &dstrect);
        }
        if (muerte2 == true) {
            SDL_RenderCopy(renderer, texturaExplosion, &dimensiones_exp, &dimensionesV_pj2);
            SDL_RenderPresent(renderer);
            Mix_PlayChannel(-1, sound, 0);
            SDL_Delay(1000);
            pj2_x = 32;
            pj2_y = 64;
        }
        else {
            SDL_RenderCopy(renderer, textura_pj2, &dimensiones_pj2, &dimensionesV_pj2);
        }
        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);
    }
    Mix_FreeMusic(bgm);
    Mix_FreeChunk(sound);
    Mix_FreeChunk(sound_Recompensa);
    bgm = nullptr;
    sound = nullptr;
    sound_Recompensa = nullptr;
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(image);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
    return 0;
}