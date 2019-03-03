#ifndef ATLANTIS_MOUSE
#define ATLANTIS_MOUSE

#include <Atlantis/atlantis_common.h>
#include <Atlantis/math/vec.h>

#include <Atlantis/engine/atlantis_sdl.h>
#include <Atlantis/engine/atlantis_texture.h>

#include <SDL2/SDL.h>

class atlantis_mouse {
    public:
        atlantis_mouse(): position(math::vec2i(0,0)){}

        void set_position(math::vec2i position) {this->position = position;}
        math::vec2i get_position() {return this->position;}

        void handle_event(SDL_Event* e){
            if(e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP){
                int x, y;
                SDL_GetMouseState(&x, &y);
                this->set_position(math::vec2i(x, y));


                /*bool inside = true;
                if(x < position.x) inside = false;
                else if(x > position.x + mouse_texture.get_width()) inside = false;
                else if(y < position.y) inside = false;
                else if(y > position.y + mouse_texture.get_height()) inside = false;

                if(!)*/
            }
        }

    private:
        math::vec2i position;
        
};


#endif