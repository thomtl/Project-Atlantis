#include <Atlantis/engine/atlantis_sdl.h>

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

TTF_Font* global_font = NULL;

void atlantis_sdl_initialize(size_t width, size_t height, std::string window_title){
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) != 0){
        std::cout << __FILE__ << ":" << __LINE__ << ": SDL Failed to initialize error: " << SDL_GetError() << std::endl;
        return;
    }

    if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")){
        std::cout << __FILE__ << ":" << __LINE__ << ": Warning: failed to set SDL_HINT_RENDER_SCALE_QUALITY : " << SDL_GetError() << std::endl;
    }
    
    window = SDL_CreateWindow(window_title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if(window == NULL){
        std::cout << __FILE__ << ":" << __LINE__ << ": SDL Failed to create window: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(renderer == NULL){
        std::cout << __FILE__ << ":" << __LINE__ << ": SDL Failed to create renderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return;
    }

    atlantis_sdl_set_draw_colour(atlantis_colour(1,1,1));
    int img_flags = IMG_INIT_PNG;
    if(!(IMG_Init(img_flags) & img_flags)){
        std::cout << __FILE__ << ":" << __LINE__ << ": SDL_image Failed to Initialize: " << IMG_GetError() << std::endl;
        return;
    }

    if(TTF_Init() == -1){
        std::cout << __FILE__ << ":" << __LINE__ << ": SDL_ttf Failed to Initialize: " << TTF_GetError() << std::endl;
        return;
    }

    global_font = TTF_OpenFont("resources/fonts/typed.ttf", 12);
    if(global_font == NULL){
        std::cout << __FILE__ << ":" << __LINE__ << ": SDL_ttf Failed to load font: " << TTF_GetError() << std::endl;
        return;
    }


}

void atlantis_sdl_set_draw_colour(atlantis_colour col){
    SDL_SetRenderDrawColor(renderer, (col.r * 255), (col.g * 255), (col.b * 255), (col.a * 255));
}

SDL_Renderer* atlantis_sdl_get_renderer(){
    return renderer;
}

TTF_Font* atlants_sdl_get_global_font(){
    return global_font;
}

void atlantis_sdl_deinitialize(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    TTF_CloseFont(global_font);

    TTF_Quit();
    IMG_Quit();    
    SDL_Quit();
}