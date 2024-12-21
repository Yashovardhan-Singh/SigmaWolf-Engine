# Features:

* Software rendering (easier to setup,  
OG engine also used it)
* Texture mapped environments (No floor or ceiling)
* Billboard Sprites
* Asset loading custom assets
* Mod support
* Embedded lua for game

# Tools Needed:

* Map builder
* asset packer

# Explanation:

The engine will be divided into 3 parts:
1) Rendering (C, SDL2)
2) Game Logic (Lua)
3) Resource Management (C, Custom)

The rendering will be handled in C, and will  
expose an API to lua for logic integration.

All of the resource Management will be written  
from scratch