#include <Atlantis/engine/atlantis_timer.h>

Uint32 timer_callback(Uint32 interval, void* params){

    atlantis_timer* param = (atlantis_timer*)params;

    if(!(param->paused) && param->started){
        param->ticks++;
        if(param->callback != NULL) param->callback(param->ticks);
    }

    return interval;
}