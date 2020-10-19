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
    int random;//Used to located the rewards randomly in the matrix
    //Matrix used to control the painting of the screen.
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

    //SDL Library Initialization
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);//Initialization of the components needed of SDL.
    IMG_Init(IMG_INIT_PNG);
    
    //Sound error control
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) < 0) {
        std::cout << "Error" << Mix_GetError();
    }
    //SOUND variables
    Mix_Music* bgm = Mix_LoadMUS("Lich yard.mp3");
    Mix_Chunk* sound = Mix_LoadWAV("Explosion.wav");
    Mix_Chunk* sound_Recompensa = Mix_LoadWAV("recompensa.wav");
    
    int coordenadas_recompensa[3][2];//Used to store the location of the rewards.
    
    int vidas = 3;//Players lifes control.
    //Window initialization
    SDL_Window* window = SDL_CreateWindow("Juego 2D",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800,
        640, 0);
    //Renderer initialization
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    //declaration of the game sprites to the  renderer.
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
    
    //Loop used to print randomly the rewards on the matrix used to paint the map.
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
    //Variables used for the initial location of the Players
    int x = 32;
    int y = 32;
    int pj2_x = 32;
    int pj2_y = 64;
    
    //Variables used to move across the sprite sheet and print the different sprites used to animate the players movement,it .
    int tipo_movimiento = 0;
    int tipo_movimiento2 = 64;
    int tick = 1;
    int tick2 = 1;
    
    Mix_PlayMusic(bgm, -1);//Back ground music.

    //Main loop. Stay running while the players still have lifes
    while (vidas != 0)
    {
        // variables using for the draw of the labyrinth    
        int pintar_x = 0;
        int pintar_y = 0;
        //variable that control if the characters lives or not
        bool muerte = false;
        bool muerte2 = false;
        // variables used for the management of animations, the variables have the duty of change the the order of draw in the sprite sheet 
        Uint32 ticks = SDL_GetTicks();
        Uint32 sprite2 = (ticks / 100) % tick2;
        Uint32 sprite = (ticks / 100) % tick;
        Uint32 temp_explosion = (ticks / 100) % 4;
        // variables in charge of the position of different sprites
        SDL_Rect laberinto = { pintar_x,pintar_y,32,32 };
        SDL_Rect srcrect = { tipo_movimiento, (sprite * 32) + 0, 32, 32 };
        SDL_Rect dstrect = { x, y, 32, 32 };
        SDL_Rect dimensiones_pj2 = { (sprite2 * 32),tipo_movimiento2,32,32 };
        SDL_Rect dimensionesV_pj2 = { pj2_x,pj2_y,32,32 };
        SDL_Rect dimensiones_exp = { (temp_explosion * 32),0,32,32 };
        // the funtion that waits for a keyboard event
        SDL_PollEvent(&event);
        //loop used for update the maze
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
        // the value of these 2 functions in 1 make the characters static when they are not moving 
        tick = 1;
        tick2 = 1;
        
        switch (event.type)//Used to control the game events.
        {
        case SDL_QUIT:
            quit = true;
            break;

        case SDL_KEYDOWN://In case any key is pressed
            switch (event.key.keysym.sym)
            {
            case SDLK_RIGHT://Move the first player to the right.
                if (x < 800 - 32) {
                    // this function are in charge of the character 1 movement and animation based on the position that the user wants to move.
                    tipo_movimiento = 96;
                    tick = 4;
                    x += 4;
                    comprobarRecompensa(x, y, coordenadas_recompensa, matriz, sound_Recompensa); // function for take the rewards
                    SDL_Delay(30);// delay used for a more fluid movement
                    break;
                }
                break;

            case SDLK_LEFT://Move the first player to the left.
                if (x > 0) {
                    // this function are in charge of the character 1 movement and animation based on the position that the user wants to move.
                    tipo_movimiento = 32;
                    tick = 4;
                    x = x - 4;
                    comprobarRecompensa(x, y, coordenadas_recompensa, matriz, sound_Recompensa); // function for take the rewards
                    SDL_Delay(30);// delay used for a more fluid movement
                    break;
                }
                break;

            case SDLK_UP://Move up the first player.
                if (y > 0)
                {
                    // this function are in charge of the character 1 movement and animation based on the position that the user wants to move.
                    tick = 4;
                    tipo_movimiento = 64;
                    y = y - 4;
                    comprobarRecompensa(x, y, coordenadas_recompensa, matriz, sound_Recompensa); // function for take the rewards
                    SDL_Delay(30);// delay used for a more fluid movement
                    break;
                }
                break;
            case SDLK_DOWN://Move down the first player.
                if (y < 600 - 32) {
                    // this function are in charge of the character 1 movement and animation based on the position that the user wants to move.
                    tick = 4;
                    tipo_movimiento = 0;
                    y += 4;
                    comprobarRecompensa(x, y, coordenadas_recompensa, matriz, sound_Recompensa); // function for take the rewards
                    SDL_Delay(30);// delay used for a more fluid movement
                    break;
                }
                break;

            case SDLK_s://Move down the second player.
                if (pj2_x < 800 - 32) {
                    // this function are in charge of the character 2 movement and animation based on the position that the user wants to move.
                    tipo_movimiento2 = 64;
                    tick2 = 3;
                    pj2_y += 4;
                    comprobarRecompensa(pj2_x, pj2_y, coordenadas_recompensa, matriz, sound_Recompensa); // function for take the rewards
                    SDL_Delay(30);// delay used for a more fluid movement
                    break;
                }
                break;

            case SDLK_a://Move the second player to the left.
                if (pj2_x > 0) {
                    // this function are in charge of the character 2 movement and animation based on the position that the user wants to move.
                    tipo_movimiento2 = 96;
                    tick2 = 3;
                    pj2_x = pj2_x - 4;
                    comprobarRecompensa(pj2_x, pj2_y, coordenadas_recompensa, matriz, sound_Recompensa); // function for take the rewards
                    SDL_Delay(30);// delay used for a more fluid movement
                    break;
                }
                break;

            case SDLK_w://Move up the second player.
                if (pj2_y > 0)
                {
                    // this function are in charge of the character 2 movement and animation based on the position that the user wants to move.
                    tick2 = 3;
                    tipo_movimiento2 = 0;
                    pj2_y = pj2_y - 4;
                    comprobarRecompensa(pj2_x, pj2_y, coordenadas_recompensa, matriz, sound_Recompensa); // function for take the rewards
                    SDL_Delay(30);// delay used for a more fluid movement
                    break;
                }
                break;
            case SDLK_d://Move the second player to the right.
                if (pj2_y < 600 - 32) {
                    // this function are in charge of the character 2 movement and animation based on the position that the user wants to move.
                    tick2 = 3;
                    tipo_movimiento2 = 32;
                    pj2_x += 4;
                    comprobarRecompensa(pj2_x, pj2_y, coordenadas_recompensa, matriz, sound_Recompensa); // function for take the rewards
                    SDL_Delay(30);// delay used for a more fluid movement
                    break;
                }
                break;
                    
             //This part is just used to proof the players lifes.
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

        //Functions to control the players lifes
        //In case the player1 dies. It reproduse the death audio adn shows the death sprite. Then the player is located at the beggining.
        if (muerte == true) {
            SDL_RenderCopy(renderer, texturaExplosion, &dimensiones_exp, &dstrect);
            SDL_RenderPresent(renderer);
            Mix_PlayChannel(-1, sound, 0);
            SDL_Delay(1000);
            x = 32;
            y = 32;
        }
        else {
            // add the texture of the player 1 to the renderer
            SDL_RenderCopy(renderer, texture, &srcrect, &dstrect);
        }
         //In case the player2 dies. It reproduse the death audio adn shows the death sprite. Then the player is located at the beggining.
        if (muerte2 == true) {
            SDL_RenderCopy(renderer, texturaExplosion, &dimensiones_exp, &dimensionesV_pj2);
            SDL_RenderPresent(renderer);
            Mix_PlayChannel(-1, sound, 0);
            SDL_Delay(1000);
            pj2_x = 32;
            pj2_y = 64;
        }
        else {
             // add the texture of the player 1 to the renderer
            SDL_RenderCopy(renderer, textura_pj2, &dimensiones_pj2, &dimensionesV_pj2);
        }
        SDL_RenderPresent(renderer); // show renderer information on the screen
        SDL_RenderClear(renderer); // clear the screen
    }
    // This section is in charge of clean memory, by the destruction of the variables used
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
