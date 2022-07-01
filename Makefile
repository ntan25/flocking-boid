CXX := g++
CXXFLAGS := -g -Wall -std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes


boid: main.cpp boid.cpp boid.h
	$(CXX) $(CXXFLAGS) main.cpp -o flocking-boid


#testing purposes only a seed value is needed
run: boid
	./flocking-boid 1

clean: 
	rm flocking-boid  

