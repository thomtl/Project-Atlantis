#include <Atlantis/engine/atlantis_sdl.h>
#include <Atlantis/engine/atlantis_texture.h>
#include <Atlantis/primitives/rect.h>
#include <Atlantis/primitives/text.h>


int main(){
    atlantis_sdl_initialize(800, 600, "Atlantis");

    //atlantis_texture tex = atlantis_texture("yet");


    //atlantis_rect rect = atlantis_rect(800 / 6, 600 / 6, 800 * 2 / 3, 600 * 2 / 3);
    //rect.texture = tex;//atlantis_colour(0.7,0,1);

    /*atlantis_rect recct = atlantis_rect(0,0,800, 600);
    recct.colour = atlantis_colour(1,1,0);*/

    
    

    atlantis_text text = atlantis_text("Hello World", atlantis_colour(0,0,0,1), math::vec2i(0,0));

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

        

        //rect.draw();
        int iW, iH;
        //SDL_QueryTexture(text.get_raw_sdl_texture(), NULL, NULL, &iW, &iH);
        iW = text.get_width();
        iH = text.get_height();
        int x = 800 / 2 - iW / 2;
        int y = 600 / 2 - iH / 2;
        text.draw(x, y);

        SDL_RenderPresent(atlantis_sdl_get_renderer());
    }

    atlantis_sdl_deinitialize();
}