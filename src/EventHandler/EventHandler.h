#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <SDL2/SDL.h>

typedef struct EventHandler {
    SDL_Event event;
    int running;
} EventHandler;

void manageEvents(EventHandler *event_handler);

#endif //EVENTHANDLER_H
