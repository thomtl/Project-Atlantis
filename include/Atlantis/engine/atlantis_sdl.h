#ifndef ATLANTIS_SDL
#define ATLANTIS_SDL

#include <Atlantis/atlantis_common.h>
#include <Atlantis/engine/atlantis_colour.h>

#include <SDL2/SDL.h>


void atlantis_sdl_initialize(size_t width, size_t height, std::string window_title);
void atlantis_sdl_deinitialize();
SDL_Renderer* atlantis_sdl_get_renderer();


#endif