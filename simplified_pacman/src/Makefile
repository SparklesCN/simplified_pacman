# reference from http://lazyfoo.net/tutorials/SDL/01_hello_SDL/linux/cli/index.php

#OBJS specifies which files to compile as part of the project
OBJS = *.cpp

#CC specifies which compiler we're using
CC = g++ -std=c++14

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = pacman

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)


game:
	g++ -std=c++14 main.cpp labyrinth.cpp constants.cpp rail.cpp loadTexture.cpp pacman.cpp gameTimer.cpp ghost.cpp pill.cpp powerPill.cpp -o pacman.exe -F/Library/Frameworks -framework SDL2 -framework SDL2_image -framework SDL2_ttf -framework SDL2_mixer


# clean:
# 	rm *.o *.exe


clean:
	rm *.o *.exe
