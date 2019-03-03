#include <Atlantis/engine/atlantis_sdl.h>
#include <Atlantis/engine/atlantis_texture.h>
#include <Atlantis/primitives/line.h>
#include <Atlantis/engine/atlantis_joystick.h>


int main(){
    atlantis_sdl_initialize(800, 600, "Atlantis");

    
    bool quit = false;
    SDL_Event e;

    while(!quit){
        while(SDL_PollEvent(&e) != 0 ){
            if(e.type == SDL_QUIT) quit = true;
            else if(e.type == SDL_KEYDOWN){
                switch (e.key.keysym.sym)
                {
                    case SDLK_q:
                        quit = true;
                        break;
                    default:
                        break;
                }
            }

        }

        atlantis_sdl_set_draw_colour(atlantis_colour(1,1,0));

        SDL_RenderClear(atlantis_sdl_get_renderer());



        SDL_RenderPresent(atlantis_sdl_get_renderer());
    }
    atlantis_sdl_deinitialize();
}