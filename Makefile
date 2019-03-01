CC = g++

CFLAGS = -Wall -Wextra -Werror -pedantic -Iinclude/

CPP_SOURCES = $(wildcard src/*.cpp src/engine/*.cpp)
CPP_OBJECTS = $(CPP_SOURCES:.cpp=.o)

.PHONY: dependencies clean

atlantis: ${CPP_OBJECTS}
	${CC} -o $@ $^ -lSDL2

%.o: %.cpp
	${CC} ${CFLAGS} -c $< -o $@

clean: 
	rm -rf src/engine/*.o
	rm atlantis

dependencies:
	sudo pacman -S sdl