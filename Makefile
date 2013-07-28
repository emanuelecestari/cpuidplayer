CXX := g++
CXX_FLAGS := -Wall -Werror -O3

SRC_FILE := src/main.cpp
EXE_NAME := cpuidplayer

all :
	$(CXX) $(CXX_FLAGS) $(SRC_FILE) -o $(EXE_NAME)
