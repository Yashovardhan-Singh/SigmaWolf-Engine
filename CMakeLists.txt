cmake_minimum_required(VERSION 3.30)
project(wolf C)

set(CMAKE_C_STANDARD 11)

add_executable(wolf main.c)
target_link_libraries(wolf SDL2 SDL2_image)