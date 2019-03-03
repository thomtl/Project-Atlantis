#ifndef ATLANTIS_TEXTURE
#define ATLANTIS_TEXTURE

#include <Atlantis/atlantis_common.h>
#include <Atlantis/math/vec.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define FAILURE_TEXTURE_PATH "resources/textures/Failure-to-load-texture.bmp"

class atlantis_texture {
    public:
        bool initialized;

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

            width = loaded_surface->w;
            height = loaded_surface->h;

            SDL_FreeSurface(loaded_surface);

            initialized = true;

            this->modulate_colours(atlantis_colour(1,1,1));
            this->set_blend_mode(SDL_BLENDMODE_BLEND);
            this->set_alpha(255);
        }

        atlantis_texture(): initialized(false){}

        ~atlantis_texture(){
            if(initialized){
                SDL_DestroyTexture(tex);
                tex = NULL;
                width = 0;
                height = 0;
                initialized = false;
            }
            
        }

        void modulate_colours(atlantis_colour colour_modulation){
            SDL_SetTextureColorMod(this->tex, (colour_modulation.r * 255), (colour_modulation.g * 255), (colour_modulation.b * 255));
        }

        void set_blend_mode(SDL_BlendMode blending){
            SDL_SetTextureBlendMode(this->tex, blending);
        }

        void set_alpha(uint8_t alpha){
            SDL_SetTextureAlphaMod(this->tex, alpha);
        }

        SDL_Texture* get_sdl_texture() {return tex;}

        int get_width() {return this->width;}
        int get_height() {return this->height;}
        math::vec2i get_dimensions() {return math::vec2i(width, height);}

        void set_width(int _width) {this->width = _width;}
        void set_height(int _height) {this->height = _height;}

        void set_sdl_texture(SDL_Texture* texture) {
            if(initialized) this->~atlantis_texture();
            this->tex = texture;
            SDL_QueryTexture(this->tex, NULL, NULL, &this->width, &this->height);
            initialized = true;
        }

        SDL_Texture* tex;
        int width, height;

};

#endif