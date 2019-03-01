#include <Atlantis/engine/atlantis_sdl.h>

int main(){
    atlantis_sdl_initialize(800, 600, "Atlantis");

    SDL_Delay(2000);

    atlantis_sdl_deinitialize();
}