#include <Atlantis/engine/atlantis_sdl.h>

#include <Atlantis/engine/atlantis_fps_timer.h>

#include <Atlantis/primitives/rect.h>

int main(){
    atlantis_sdl_initialize(800, 600, "Atlantis");

    atlantis_fps_timer t = atlantis_fps_timer();

    atlantis_rect r = atlantis_rect(400,300, 200, 200);
    r.colour = atlantis_colour(0.7,0,1);
    r.texture.initialized = false;

    bool quit = false;
    SDL_Event e;

    t.start();

    int x = 0, y = 0;

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

        std::cout << t.handle_frame() << std::endl;

        atlantis_sdl_set_draw_colour(atlantis_colour(1,1,0));

        SDL_RenderClear(atlantis_sdl_get_renderer());

        if(x >= 800) x = 0;
        if(y >= 600) y = 0;

        r.x = x;
        r.y = y;
        x++;
        y++;

        r.draw();
        

        SDL_RenderPresent(atlantis_sdl_get_renderer());
    }

    atlantis_sdl_deinitialize();
}