#include <Atlantis/engine/atlantis_sdl.h>

SDL_Window* window = NULL;
SDL_Surface* screen_surface = NULL;

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
            screen_surface = SDL_GetWindowSurface(window);

            SDL_FillRect(screen_surface, NULL, atlantis_create_sdl_colour(colour(1,1,1,1)));

            SDL_UpdateWindowSurface(window);
        }
    }

}

void atlantis_sdl_deinitialize(){
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void atlantis_sdl_write_pixel(size_t x, size_t y, colour colour);

uint32_t atlantis_create_sdl_colour(colour colour){
    return SDL_MapRGBA(screen_surface->format, colour.r * 255, colour.g * 255, colour.b * 255, colour.a * 255);
}