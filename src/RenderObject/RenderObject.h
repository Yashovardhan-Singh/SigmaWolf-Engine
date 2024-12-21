#ifndef RENDERING_H
#define RENDERING_H

#include <SDL2/SDL.h>

typedef struct RenderObject{
    SDL_Rect src;
    SDL_Rect dest;
    SDL_Surface *texture;
} RenderObject;

void loadRenderObject(RenderObject *object, const char *texture_file_path);

#endif //RENDERING_H
