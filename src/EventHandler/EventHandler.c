#include "EventHandler.h"

void manageEvents(EventHandler *event_handler) {
    while (SDL_PollEvent(&event_handler->event) != 0) {
        switch (event_handler->event.type) {
            case SDL_QUIT:
                event_handler->running = 0;
                break;
            default:
                break;
        }
    }
}