#ifndef ATLANTIS_SOUND
#define ATLANTIS_SOUND

#include <Atlantis/atlantis_common.h>

#include <Atlantis/misc/id_gen.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>


class sound_controller{
    public:
        std::string path;
        sound_controller(std::string path): path(path), music(NULL){
            music = Mix_LoadMUS(path.c_str());
            if(music == NULL){
                std::cout << __FILE__ << ":" << __LINE__ << ": SDL_mixer Failed to load music: " << Mix_GetError() << std::endl;
                return;
            }
        }

        sound_controller(): music(NULL){}

        ~sound_controller(){
            Mix_FreeMusic(music);
            music = NULL;
        }

        void play(){
            if(music != NULL) Mix_PlayMusic(music, 1);
        }

    private:
        Mix_Music* music;
};

class sound_manager {
    public:
        sound_manager(){
            this->set_volume(MIX_MAX_VOLUME);
        }
        ~sound_manager(){
            id_generator.reset_id_gen();
            for (auto& i : sounds) delete i.second;

            sounds.clear();
        }

        void play_all(){
            Mix_RewindMusic();
            for (auto& i : sounds) i.second->play(); 
        }

        void play(int id){
            Mix_RewindMusic();
            sounds[id]->play();
        }

        void stop(){
            Mix_HaltMusic();
        }

        void set_volume(int volume){
            Mix_VolumeMusic(volume);
        }

        int add_music(std::string path){
            int id = id_generator.gen_id();
            sounds[id] = new sound_controller(path);
            return id;
        } 

        void delete_sound(int id){
            delete sounds[id];
            sounds.erase(id);
        }
    private:
        id_gen<int> id_generator;
        std::unordered_map<int, sound_controller*> sounds;
};

#endif