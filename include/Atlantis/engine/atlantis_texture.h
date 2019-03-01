#ifndef ATLANTIS_TEXTURE
#define ATLANTIS_TEXTURE

#include <Atlantis/atlantis_common.h>
#include <SDL2/SDL.h>

#define FAILURE_TEXTURE_PATH "resources/textures/Failure-to-load-texture.bmp"

class texture {
    public:
        SDL_Texture* tex;

        texture(std::string string){
            tex = NULL;

            SDL_Surface* loaded_surface = SDL_LoadBMP(string.c_str());
            if(loaded_surface == NULL){
                std::cout << __FILE__ << ":" << __LINE__ <<  ": Failed to load BMP" << std::endl;

                loaded_surface = SDL_LoadBMP(FAILURE_TEXTURE_PATH);
                if(loaded_surface == NULL){
                    std::cout << __FILE__ << ":" << __LINE__ <<  ": Failed to failure texture" << std::endl;
                    return;
                }

            } 
            tex = SDL_CreateTextureFromSurface(atlantis_sdl_get_renderer(), loaded_surface);
            if(tex == NULL){
                std::cout << __FILE__ << ":" << __LINE__ <<  ": Failed to create Texture" << std::endl;
            }

            SDL_FreeSurface(loaded_surface);
        }

        ~texture(){
            SDL_DestroyTexture(tex);
        }
};

#endif