#include <stdbool.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main(void) {

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *win = SDL_CreateWindow("Hi",100, 100, 1920, 1080, SDL_WINDOW_SHOWN);

    if (!win) printf("Failed to create window\n");

    SDL_Surface *screen = SDL_GetWindowSurface(win);
    SDL_Surface *picture = IMG_Load("../picture.png");

    SDL_Rect dest;
    dest.x = 0;
    dest.y = 0;
    dest.w = 1920;
    dest.h = 1080;

    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    src.w = 32;
    src.h = 32;

    SDL_Event e;
    int running = 1;

    while (running) {
        while (SDL_PollEvent(&e) != 0) {
            switch (e.type) {
                case SDL_QUIT:
                    running = 0;
                    break;
                default:
                    break;
            }
        }

        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
        SDL_BlitScaled(picture, NULL, screen, &dest);
        SDL_UpdateWindowSurface(win);
    }

    SDL_DestroyWindow(win);
    win = NULL;
    screen = NULL;

    SDL_Quit();

    return 0;
}