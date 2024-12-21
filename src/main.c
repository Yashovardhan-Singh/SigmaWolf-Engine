#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

typedef struct RenderObject{
    SDL_Rect src;
    SDL_Rect dest;
    SDL_Surface *texture;
} RenderObject;

void loadRenderObject(RenderObject* object, char *texture_file_path) {
    object->texture = IMG_Load(texture_file_path);
    if (object->texture == NULL) {
        perror("Failed to load texture");
        exit(EXIT_FAILURE);
    }

    object->src.x = 0;
    object->src.y = 0;
    object->src.w = object->texture->w;
    object->src.h = object->texture->h;

    object->dest.x = 0;
    object->dest.y = 0;
    object->dest.w = 1920;
    object->dest.h = 1080;
}

typedef struct EventHandler {
    SDL_Event event;
    int running;
} EventHandler;

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

typedef struct Canvas {
    SDL_Window *window;     // Window Handle
    SDL_Surface *surface;   // Surface buffer to draw to
} Canvas;

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

void destoryCanvas(Canvas *canvas) {
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

    destoryCanvas(&canvas);
    return 0;
}