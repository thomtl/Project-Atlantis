#ifndef ATLANTIS_FPS_TIMER
#define ATLANITS_FPS_TIMER

#include <Atlantis/atlantis_common.h>
#include <Atlantis/engine/atlantis_timer.h>
#include <SDL2/SDL.h>

class atlantis_fps_timer {
    public:
        atlantis_fps_timer(): fps(0), start_ms(SDL_GetTicks()), counted_frames(0) {}

        void start() {start_ms = SDL_GetTicks();}

        double handle_frame(){
            double avg_fps = counted_frames / ((SDL_GetTicks() - start_ms) / 1000.f);
            if(avg_fps > 2000000) avg_fps = 0;
            fps = avg_fps;

            counted_frames++;

            return fps;
        }

        double get_fps(){return fps;}

    private:
        double fps;
        int start_ms, counted_frames;     
};

#endif