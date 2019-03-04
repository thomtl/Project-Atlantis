#ifndef ATLANTIS_SDL
#define ATLANTIS_SDL

#include <Atlantis/atlantis_common.h>
#include <Atlantis/engine/atlantis_colour.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>


void atlantis_sdl_initialize(size_t width, size_t height, std::string window_title);
void atlantis_sdl_deinitialize();

SDL_Renderer* atlantis_sdl_get_renderer();
TTF_Font* atlants_sdl_get_global_font();

void atlantis_sdl_set_draw_colour(atlantis_colour col);




#endif