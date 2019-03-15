# #OBJS specifies which files to compile as part of the project
# OBJS = main.cpp labyrinth.cpp constants.cpp rail.cpp loadTexture.cpp pacman.cpp gameTimer.cpp ghost.cpp pill.cpp powerPill.cpp

# #CC specifies which compiler we're using
# CC = g++ -std=c++14

# #COMPILER_FLAGS specifies the additional compilation options we're using
# # -w suppresses all warnings
# COMPILER_FLAGS = -w

# #LINKER_FLAGS specifies the libraries we're linking against
# LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

# #OBJ_NAME specifies the name of our exectuable
# OBJ_NAME = PacMan

# #This is the target that compiles our executable
# all : $(OBJS)
# 	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

pacman:
	g++ -std=c++14 -g -o pacman.exe main.cpp labyrinth.cpp constants.cpp rail.cpp loadTexture.cpp pacman.cpp gameTimer.cpp ghost.cpp pill.cpp powerPill.cpp -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer

game.exe:
    g++ -g -std=c++14 `sdl2-config --cflags` *.cpp -o game.exe `sdl2-config --static-libs` -lSDL2_image -lSDL2_ttf -lSDL2_mixer

clean:
	rm *.o *.exe