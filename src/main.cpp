#include <Atlantis/engine/atlantis_sdl.h>
#include <Atlantis/engine/atlantis_texture.h>
#include <Atlantis/primitives/rect.h>
#include <Atlantis/primitives/line.h>


int main(){
    atlantis_sdl_initialize(800, 600, "Atlantis");

    atlantis_texture tex = atlantis_texture("yet");

    atlantis_rect rect = atlantis_rect(800 / 6, 600 / 6, 800 * 2 / 3, 600 * 2 / 3);
    rect.colour = atlantis_colour(0.7,0,1);

    atlantis_line line = atlantis_line(math::vec2i(0, 600 / 2), math::vec2i(800, 600 / 2));
    line.colour = atlantis_colour(1,1,0);


    bool quit = false;
    SDL_Event e;

    while(!quit){
        while(SDL_PollEvent(&e) != 0 ){
            if(e.type == SDL_QUIT) quit = true;
        }

        SDL_RenderClear(atlantis_sdl_get_renderer());

        SDL_RenderCopy(atlantis_sdl_get_renderer(), tex.tex, NULL, NULL);

        rect.draw();
        line.draw();


        SDL_RenderPresent(atlantis_sdl_get_renderer());
    }

    atlantis_sdl_deinitialize();
}