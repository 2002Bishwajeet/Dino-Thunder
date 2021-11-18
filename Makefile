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
	
	g++ -Isrc/include -Iinclude  -Ilib -c main.cpp $(LIB)/*.cpp 
	

link:
	$(CXX) main.o game.o pause_game.o asset_manager.o main_menu.o  state_manager.o game_play.o game_over.o -I$(INCLUDE) -Isrc/include -o main -Lsrc/lib $(LIBRARIES)

clean:
	-rm $(BIN)/*
	

#  Make sure to comment this before pushing it to github
temp: 
	g++ -Isrc/include -c temp.cpp 

	$(CXX) temp.o  -I$(INCLUDE) -Isrc/include -o temp -Lsrc/lib $(LIBRARIES)