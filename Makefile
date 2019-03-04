CC = g++

CFLAGS = -Wall -Wextra -Werror -pedantic -Iinclude/ -std=c++17
LINKFLAGS =  -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

CPP_SOURCES = $(wildcard src/*.cpp src/engine/*.cpp)
CPP_HEADERS = ${wildcard include/Atlantis/*.h include/Atlantis/engine/*.h include/Atlantis/primitives/*.h include/Atlantis/math/*.h include/Atlantis/misc/*.h}
CPP_OBJECTS = $(CPP_SOURCES:.cpp=.o)

.PHONY: dependencies clean

atlantis: ${CPP_OBJECTS}
	${CC} ${LINKFLAGS} -o $@ $^

clean: 
	rm -f src/*.o src/engine/*.o
	rm -f atlantis

dependencies:
	sudo pacman -S sdl sdl2_image

%.o: %.cpp ${CPP_HEADERS}
	${CC} ${CFLAGS} -c $< -o $@
