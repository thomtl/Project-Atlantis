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
                SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

            }
 
        }
    }

}

SDL_Renderer* atlantis_sdl_get_renderer(){
    return renderer;
}

void atlantis_sdl_deinitialize(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}