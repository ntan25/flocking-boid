#include <iostream> 
#include <vector> 
#include <string> 
#include <cmath>
#include <algorithm> 
#include <stdlib.h> 
#include <array> 
#include <sstream> 
#include <iomanip> 
#include <cstdlib> 

#define WIDTH 640 
#define HEIGHT 360 
#define MAX_SPEED 20

struct Boid{
    std::array<double, 2> pos; 
    std::array<double, 2> vel; 
    double maxSpeed = 100; 
}; 

typedef std::vector<Boid*> boidVec; 



class Flock
{

    public: 
        Flock(size_t seed); 
        Flock(size_t seed, int numBoids); 
        ~Flock(); 
        boidVec getNeighbors(Boid& b); 
        std::array<double, 2> Cohesion(Boid& b, boidVec neighbors); 
        std::array<double, 2>  Separation(Boid& b, boidVec neighobrs); 
        std::array<double, 2> Alignment(Boid& b, boidVec neighbors); 
        std::array<double, 2> centerofMass(Boid& b); 
        std::array<double, 2> neighborCenter(boidVec neighbors); 
        void update(); 
        boidVec boids; 

}; 
