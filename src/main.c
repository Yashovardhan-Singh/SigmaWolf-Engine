#include <stdio.h>
#include <SDL2/SDL.h>
#include "Canvas/Canvas.h"
#include "RenderObject/RenderObject.h"
#include "EventHandler/EventHandler.h"

int main(void) {

    SDL_Init(SDL_INIT_EVERYTHING);

    Canvas canvas;
    initCanvas(&canvas, "Hello", 1920, 1080);

    RenderObject object;
    loadRenderObject(&object, "../assets/raw/picture.png");

    EventHandler event_handler;
    event_handler.running = 1;

    while (event_handler.running) {
        manageEvents(&event_handler);
        renderCanvas(&canvas, &object);
    }

    destroyCanvas(&canvas);
    return 0;
}