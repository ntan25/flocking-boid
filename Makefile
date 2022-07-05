CXX := g++
CXXFLAGS := -g -Wall -std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes


flock: main.cpp flock.cpp flock.h
	$(CXX) $(CXXFLAGS) main.cpp -o flocking-boid


#testing purposes only a seed value is needed
run: flock
	./flocking-boid 1

clean: 
	rm flocking-boid  

