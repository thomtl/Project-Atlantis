#ifndef ATLANTIS_TEXTURE
#define ATLANTIS_TEXTURE

#include <Atlantis/atlantis_common.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define FAILURE_TEXTURE_PATH "resources/textures/Failure-to-load-texture.bmp"

class atlantis_texture {
    public:
        SDL_Texture* tex;

        atlantis_texture(std::string path){
            tex = NULL;

            SDL_Surface* loaded_surface = IMG_Load(path.c_str());
            if(loaded_surface == NULL){
                std::cout << __FILE__ << ":" << __LINE__ <<  ": Failed to load texture at path: " << path << std::endl;

                loaded_surface = SDL_LoadBMP(FAILURE_TEXTURE_PATH);
                if(loaded_surface == NULL){
                    std::cout << __FILE__ << ":" << __LINE__ <<  ": Failed to load failure texture" << std::endl;
                    return;
                }

            } 
            tex = SDL_CreateTextureFromSurface(atlantis_sdl_get_renderer(), loaded_surface);
            if(tex == NULL){
                std::cout << __FILE__ << ":" << __LINE__ <<  ": Failed to create Texture from loaded_surface" << std::endl;
            }

            SDL_FreeSurface(loaded_surface);
        }

        ~atlantis_texture(){
            SDL_DestroyTexture(tex);
        }
};

#endif