#ifndef ATLANTIS_SDL
#define ATLANTIS_SDL

#include <Atlantis/atlantis_common.h>
#include <Atlantis/engine/atlantis_colour.h>

#include <SDL2/SDL.h>


void atlantis_sdl_initialize(size_t width, size_t height, std::string window_title);
void atlantis_sdl_deinitialize();
void atlantis_sdl_write_pixel(size_t x, size_t y, colour colour);
uint32_t atlantis_create_sdl_colour(colour colour);

#endif