CXX = g++
CXXFLAGS = -std=c++98 -O0 -g -ggdb -Wall -Wextra -Wshadow -pedantic

all:  
	$(CXX) $(CXXFLAGS) -o main Konsola.cpp utility.cpp

clean: 
	@rm main

.PHONY: all
