#ifndef ATLANTIS_RECT
#define ATLANTIS_RECT

#include <Atlantis/atlantis_common.h>

#include <Atlantis/engine/atlantis_colour.h>
#include <Atlantis/engine/atlantis_texture.h>

#include <Atlantis/engine/atlantis_sdl.h>

#include <SDL2/SDL.h>

class atlantis_rect {
    public:
        size_t x, y, w, h;

        atlantis_colour colour;
        atlantis_texture texture;

        atlantis_rect(size_t _x, size_t _y, size_t _w, size_t _h): x(_x), y(_y), w(_w), h(_h), colour(atlantis_colour(1,1,1)), texture(atlantis_texture()){;}
        atlantis_rect(size_t _w, size_t _h): x(0), y(0), w(_w), h(_h), colour(atlantis_colour(1,1,1)), texture(NULL){;}

        SDL_Rect to_sdl_rect(){SDL_Rect ret; ret.h = h; ret.w = w; ret.x = x; ret.y = y; return ret;}

        void draw(){
            if(!texture.initialized){
                
                atlantis_sdl_set_draw_colour(this->colour);
                SDL_Rect rect = this->to_sdl_rect();
                SDL_RenderFillRect(atlantis_sdl_get_renderer(), &rect);
            } else {
                SDL_Rect rect = this->to_sdl_rect();
                SDL_RenderCopy(atlantis_sdl_get_renderer(), texture.get_sdl_texture(), NULL, &rect);
            }
        }
};

#endif