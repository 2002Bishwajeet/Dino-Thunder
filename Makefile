CXX		  := g++
CXX_FLAGS := -Wall -Wextra -Wno-unused-parameter -std=c++17 -ggdb

BIN := bin
EXECUTABLE	:= main
MKDIR_P = mkdir 

all: compile  link

LIB :=lib
INCLUDE :=include

LIBRARIES	:= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

directories: ${BIN}

${BIN}:
	${MKDIR_P} ${BIN}

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

compile:

# TODO: Find a method to add all the objects in the bin folder
	
	$(CXX) $(CXX_FLAGS) -Isrc/include -I$(INCLUDE) -c main.cpp $(LIB)/*.cpp 
	

link:
	$(CXX) ${CXX_FLAGS} main.o game.o pause_game.o asset_manager.o main_menu.o  state_manager.o game_play.o game_over.o -I$(INCLUDE) -Isrc/include -o $(BIN)/$(EXECUTABLE -L$(LIB) $(LIBRARIES)

clean:
	-rm $(BIN)/*
	

#  Make sure to comment this before pushing it to github
# temp: 
# 	g++ -Isrc/include -c temp.cpp 

# 	$(CXX) temp.o  -Isrc/include -o temp -Lsrc/lib $(LIBRARIES)