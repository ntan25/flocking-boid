CXX := g++
CXXFLAGS := -g -Wall -std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes


boid: main.cpp boid.cpp boid.h
	$(CXX) $(CXXFLAGS) main.cpp -o flocking-boid


run: boid
	./flocking-boid

clean: 
	rm flocking-boid
