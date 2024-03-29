#ifndef ATLANTIS_JOYSTICK
#define ATLANTIS_JOYSTICK

#include <Atlantis/atlantis_common.h>
#include <Atlantis/math/vec.h>
#include <SDL2/SDL.h>

#define JOYSTICK_DEAD_ZONE 0

class atlantis_joystick {
    public:
        atlantis_joystick(int joystick_index): sdl_joystick_index(joystick_index){
            if(SDL_NumJoysticks() < joystick_index){
                std::cout << __FILE__ << ":" << __LINE__ << ": Error: Joystick index doesn't exist SDL_error: " << SDL_GetError() << std::endl;
                return;
            }

            joystick = SDL_JoystickOpen(joystick_index);
            if(joystick == NULL){
                std::cout << __FILE__ << ":" << __LINE__ << ": Error: Failed to open joystick SDL_error: " << SDL_GetError() << std::endl;
                return;
            }

            joystick_haptic = SDL_HapticOpenFromJoystick(joystick);
            if(joystick_haptic == NULL){
                std::cout << __FILE__ << ":" << __LINE__ << ": Warning failed to open joystick haptics SDL_error: " << SDL_GetError() << std::endl;
                return;
            }

            if(SDL_HapticRumbleInit(joystick_haptic) < 0){
                std::cout << __FILE__ << ":" << __LINE__ << ": Warning failed to init joystick haptics SDL_error: " << SDL_GetError() << std::endl;
                return;
            }
        }

        ~atlantis_joystick(){
            if(joystick != NULL) SDL_JoystickClose(this->joystick);
            if(joystick_haptic != NULL) SDL_HapticClose(joystick_haptic);
        }

        void handle_event(SDL_Event* e){
            int xDir, yDir;
            /*if(e->type == SDL_JOYAXISMOTION){
                if(e->jaxis.which == sdl_joystick_index){
                    if(e->jaxis.axis == 0){
                        if(e->jaxis.value < -JOYSTICK_DEAD_ZONE) xDir = -1;
                        else if(e->jaxis.value > JOYSTICK_DEAD_ZONE) xDir = 1;
                        else xDir = 0;
                    } 
                    if(e->jaxis.axis == 1){
                        if(e->jaxis.value < -JOYSTICK_DEAD_ZONE) yDir = -1;
                        else if(e->jaxis.value > JOYSTICK_DEAD_ZONE) yDir = 1;
                        else yDir = 0;
                    }
                }
            }*/

            xDir = SDL_JoystickGetAxis(this->joystick, 0);
            yDir = SDL_JoystickGetAxis(this->joystick, 1);
            direction = math::vec2i(xDir, yDir);

            (void)(e);
        }

        void play_rumble(double strenght_factor, int length){
            if(joystick_haptic != NULL) SDL_HapticRumblePlay(joystick_haptic, strenght_factor, length);
        }

        math::vec2i get_direction() {return this->direction;}

    private:
        math::vec2i direction;
        int sdl_joystick_index;
        SDL_Joystick* joystick;
        SDL_Haptic* joystick_haptic;
};

#endif