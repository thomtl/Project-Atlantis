#ifndef ATLANTIS_LINE
#define ATLANTIS_LINE

#include <Atlantis/atlantis_common.h>
#include <Atlantis/engine/atlantis_colour.h>
#include <Atlantis/engine/atlantis_sdl.h>
#include <Atlantis/math/vec.h>

#include <SDL2/SDL.h>

class atlantis_line {
    public:
        math::vec2i a, b;

        atlantis_colour colour;
        //TODO: texture texture;

        atlantis_line(math::vec2i a, math::vec2i b): a(a), b(b), colour(atlantis_colour(1,1,1)){;}
        atlantis_line(): a(math::vec2i(0,0)), b(math::vec2i(0,0)), colour(atlantis_colour(1,1,1)){;}

        void draw(){
            atlantis_sdl_set_draw_colour(this->colour);
            SDL_RenderDrawLine(atlantis_sdl_get_renderer(), a.x, a.y, b.x, b.y);
        };
};



#endif