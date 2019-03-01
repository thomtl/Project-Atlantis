#include <Atlantis/engine/atlantis_sdl.h>
#include <Atlantis/engine/atlantis_texture.h>

int main(){
    atlantis_sdl_initialize(800, 600, "Atlantis");

    texture tex = texture("yet");

    bool quit = false;
    SDL_Event e;

    while(!quit){
        while(SDL_PollEvent(&e) != 0 ){
            if(e.type == SDL_QUIT) quit = true;
        }

        SDL_RenderClear(atlantis_sdl_get_renderer());

        SDL_RenderCopy(atlantis_sdl_get_renderer(), tex.tex, NULL, NULL);

        SDL_RenderPresent(atlantis_sdl_get_renderer());
    }

    atlantis_sdl_deinitialize();
}