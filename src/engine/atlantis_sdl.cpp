#include <Atlantis/engine/atlantis_sdl.h>

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

void atlantis_sdl_initialize(size_t width, size_t height, std::string window_title){
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cout << __FILE__ << ":" << __LINE__ << ": SDL Failed to initialize error: " << SDL_GetError() << std::endl;
        return;
    } else {
        window = SDL_CreateWindow(window_title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
        if(window == NULL){
            std::cout << __FILE__ << ":" << __LINE__ << ": SDL Failed to create window: " << SDL_GetError() << std::endl;
            return;
        } else {
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if(renderer == NULL) {
                std::cout << __FILE__ << ":" << __LINE__ << ": SDL Failed to create renderer: " << SDL_GetError() << std::endl;
                return;
            } else {
                //SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
                atlantis_sdl_set_draw_colour(atlantis_colour(1,1,1));

                int img_flags = IMG_INIT_PNG;
                if(!(IMG_Init(img_flags) & img_flags)){
                    std::cout << __FILE__ << ":" << __LINE__ << ": SDL_image Failed to Initialize: " << IMG_GetError() << std::endl;
                    return;
                } else {

                }

            }
 
        }
    }

}

void atlantis_sdl_set_draw_colour(atlantis_colour col){
    SDL_SetRenderDrawColor(renderer, (col.r * 255), (col.g * 255), (col.b * 255), (col.a * 255));
}

SDL_Renderer* atlantis_sdl_get_renderer(){
    return renderer;
}

void atlantis_sdl_deinitialize(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();    
    SDL_Quit();
}