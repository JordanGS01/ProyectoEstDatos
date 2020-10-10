#include <SDL.h>
#include <SDL_image.h>

int main(int argc, char** argv)
{
    bool quit = false;
    SDL_Event event;

    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);

    SDL_Window* window = SDL_CreateWindow("SDL2 Sprite Sheets",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800,
        640, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Surface* image = IMG_Load("EspadasoDer.png");
    //SDL_Surface* fondo = IMG_Load("");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer,
        image);  
    SDL_SetRenderDrawColor(renderer, 168, 230, 255, 255);
    SDL_RenderClear(renderer);
    int x = 200;
    int y = 200;
    while (!quit)
    {
        Uint32 ticks = SDL_GetTicks();
        Uint32 sprite = (ticks / 100) % 2;
        SDL_Rect srcrect = { (sprite * 32)+0, 0, 32, 32};
        SDL_Rect dstrect = { x, y, 32, 32 };

        SDL_PollEvent(&event);

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
                    x += 4;
                    SDL_Delay(30);
                    break;
                }
                break;

            case SDLK_LEFT:
                if (x > 0) {
                    x = x - 4;
                    SDL_Delay(30);
                    break;
                }
                break;

            case SDLK_UP:
                if (y>0)
                {
                    y = y - 4;
                    SDL_Delay(30);
                    break;
                }
                break;
            case SDLK_DOWN:
                if (y<600-32) {
                    y += 4;
                    SDL_Delay(30);
                    break;
                }
                break;
            case SDLK_1:

                break;
            }
        }
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, &srcrect, &dstrect);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(image);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    return 0;
}
