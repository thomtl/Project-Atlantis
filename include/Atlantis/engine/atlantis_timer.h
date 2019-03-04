#ifndef ATLANTIS_TIMER
#define ATLANTIS_TIMER

#include <Atlantis/atlantis_common.h>

#include <SDL2/SDL.h>

Uint32 timer_callback(Uint32 interval, void* params);

typedef void (*atlantis_timer_callback)(uint64_t);

class atlantis_timer{
    public:
        atlantis_timer(uint32_t interval): ticks(0), callback(NULL), paused(false), started(true){
            timer = SDL_AddTimer(interval, timer_callback, this);
            if(timer == 0){
                std::cout << __FILE__ << ":" << __LINE__ << ": Failed to create timer sdl_error: " << SDL_GetError() << std::endl;
                return;
            }
        }
        ~atlantis_timer(){
            SDL_RemoveTimer(this->timer);
        }

        void start() {started = true; ticks = 0;}
        void stop() {started = false;}

        void pause() {paused = true;}
        void resume() {paused = false;}


        void set_callback(atlantis_timer_callback callback){
            this->callback = callback;
        }

        uint64_t ticks;
        atlantis_timer_callback callback;
        bool paused, started;
    private: 
        SDL_TimerID timer;
};


#endif