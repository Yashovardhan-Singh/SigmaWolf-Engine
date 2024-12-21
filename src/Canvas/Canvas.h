#ifndef CANVAS_H
#define CANVAS_H

#include "../RenderObject/RenderObject.h"

typedef struct Canvas {
    SDL_Window *window;     // Window Handle
    SDL_Surface *surface;   // Surface buffer to draw to
} Canvas;

void initCanvas(Canvas *canvas, const char *title, int width, int height);
void destroyCanvas(Canvas *canvas);
void renderCanvas(Canvas *canvas, RenderObject *object);

#endif //CANVAS_H
