atlantis_sdl.cpp is the interaction layer between Atlantis and SDL

Functions:
    void atlantis_sdl_initialize(size_t width, size_t height, std::string window_title)
        Initialize an SDL window

    void atlantis_sdl_deinitialize()
        Deinitialize the SDL context and free the resources

    SDL_Renderer* atlantis_sdl_get_renderer()
        Returns the SDL_Renderer object created by atlantis_sdl_initialize()