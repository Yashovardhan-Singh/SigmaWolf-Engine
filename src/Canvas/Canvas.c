#include "Canvas.h"

void initCanvas(Canvas *canvas, const char *title, int width, int height) {
    canvas->window = SDL_CreateWindow(title,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        width, height,
        SDL_WINDOW_SHOWN);

    if (canvas->window == NULL) {
        perror("Failed to create window");
        exit(EXIT_FAILURE);
    }

    canvas->surface = SDL_GetWindowSurface(canvas->window);

    if (canvas->surface == NULL) {
        perror("Failed to get surface");
        exit(EXIT_FAILURE);
    }
}

void destroyCanvas(Canvas *canvas) {
    SDL_DestroyWindow(canvas->window);
    canvas->window = NULL;
    canvas->surface = NULL;

    SDL_Quit();
}

void renderCanvas(Canvas *canvas, RenderObject *object) {
    SDL_FillRect(canvas->surface, NULL, SDL_MapRGB(canvas->surface->format, 255, 255, 255));
    SDL_BlitScaled(object->texture, &object->src, canvas->surface, &object->dest);
    SDL_UpdateWindowSurface(canvas->window);
}