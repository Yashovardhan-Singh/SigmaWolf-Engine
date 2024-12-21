cmake_minimum_required(VERSION 3.30)
project(wolf C)

set(CMAKE_C_STANDARD 11)

add_executable(wolf src/main.c
        src/RenderObject/RenderObject.h
        src/RenderObject/RenderObject.c
        src/EventHandler/EventHandler.c
        src/EventHandler/EventHandler.h
        src/Canvas/Canvas.c
        src/Canvas/Canvas.h)
target_link_libraries(wolf SDL2 SDL2_image)