#ifndef ATLANTIS_TEXT
#define ATLANTIS_TEXT

#include <Atlantis/atlantis_common.h>
#include <Atlantis/engine/atlantis_colour.h>
#include <Atlantis/engine/atlantis_sdl.h>
#include <Atlantis/engine/atlantis_texture.h>
#include <Atlantis/math/vec.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class atlantis_text {
    public:
        std::string text;
        atlantis_colour text_colour;
        math::vec2i center;

        atlantis_text(std::string text, atlantis_colour text_colour, math::vec2i center): text(text), text_colour(text_colour), center(center), texture(NULL){
            SDL_Surface* text_surface = TTF_RenderText_Solid(atlants_sdl_get_global_font(), text.c_str(), text_colour.to_sdl_color());
            if(text_surface == NULL){
                std::cout << "Failed to render text surface SDL_tff error: " << TTF_GetError() << std::endl;
                return;
            }

            //SDL_SetColorKey(text_surface, SDL_TRUE, SDL_MapRGB(text_surface->format, 255, 255, 255));
            this->width = text_surface->w;
            this->height = text_surface->h;
            this->texture = SDL_CreateTextureFromSurface(atlantis_sdl_get_renderer(), text_surface);
            if(texture == NULL){
                std::cout << "Failed to create texture from surface SDL error: " << SDL_GetError() << std::endl;
                SDL_FreeSurface(text_surface);
                return;
            }

            SDL_FreeSurface(text_surface);
        }

        ~atlantis_text(){
            SDL_DestroyTexture(this->texture);
        }

        void draw(int x, int y){
            SDL_Rect renderquad;
            renderquad.x = x;
            renderquad.y = y;
            renderquad.w = this->width;
            renderquad.h = this->height;

            SDL_RenderCopy(atlantis_sdl_get_renderer(), this->texture, NULL, &renderquad);
        }

        SDL_Texture* get_raw_sdl_texture(){
            return this->texture;
        }

        int get_width() {return width;}
        int get_height() {return height;}
    private:
        SDL_Texture* texture;
        int width, height;
};

#endif