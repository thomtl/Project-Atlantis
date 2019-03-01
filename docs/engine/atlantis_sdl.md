atlantis_sdl.cpp is the interaction layer between Atlantis and SDL

Functions:
    void atlantis_sdl_initialize(size_t width, size_t height, std::string window_title)
        Initialize an SDL window

    void atlantis_sdl_deinitialize()
        Deinitialize the SDL context and free the resources

    void atlantis_sdl_write_pixel(size_t x, size_t y, colour colour)
        Write a raw pixel to the SDL context

    uint32_t atlantis_create_sdl_colour(colour colour)
        Convert a colour to a uint32_t usable by SDL as a colour