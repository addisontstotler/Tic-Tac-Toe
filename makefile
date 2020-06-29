CFLAGS =  $(shell sdl2-config --cflags)  -O2 
LIBS = -lSDL2_image -lSDL_ttf $(shell sdl2-config --libs) -lm

main: SDLfunctions.h box.h box.cpp main.cpp
	g++ $(CFLAGS) box.cpp main.cpp -o tic-tac-toe $(LIBS)
