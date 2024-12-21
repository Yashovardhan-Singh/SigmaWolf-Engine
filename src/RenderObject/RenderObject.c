#include "RenderObject.h"
#include <SDL2/SDL_image.h>

void loadRenderObject(RenderObject *object, const char *texture_file_path) {
    object->texture = IMG_Load(texture_file_path);
    if (object->texture == NULL) {
        perror("Failed to load texture");
        exit(EXIT_FAILURE);
    }

    object->src = (SDL_Rect) {0, 0, object->texture->w, object->texture->h};
    object->dest = (SDL_Rect) {0, 0, 1920, 1080};
}