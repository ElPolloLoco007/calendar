CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb
LDFLAGS  := -lpqxx 
BIN		:= bin
SRC		:= src
INCLUDE	:= include
LIB		:= lib
EXTRA		:= extra


LIBRARIES	:=
EXECUTABLE	:= calendar


all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -I$(EXTRA) -L$(LIB) $^ $(LDFLAGS) -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*
