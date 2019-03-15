# CXX = g++
# CXXFLAGS = -g -std=c++14 `sdl-config --cflags`

# %.o: %.cpp
# 	$(CXX) -c $(CXXFLAGS) $<

# pacman.exe: main.o labyrinth.o constants.o rail.o loadTexture.o pacman.o gameTimer.o ghost.o pill.o powerPill.o
# 	$(CXX) -o $@ $^



# ## Defie your own test* targets here and then add them to the all: target
# ## For example, if you implement a Caesar cipher, define a testCaesar.exe target
# ## and then add it to the dependencies of the all: target above. Do the 
# ## same for testDate.exe.

# clean: 
# 	$(RM) *.o *.exe

pacman:
	g++ -std=c++14 -g -o pacman.exe main.cpp labyrinth.cpp constants.cpp rail.cpp loadTexture.cpp pacman.cpp gameTimer.cpp ghost.cpp pill.cpp powerPill.cpp -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer

clean:
	rm *.o *.exe