#include <iostream> 
#include <vector> 
#include <string> 
#include <cmath>
#include <algorithm> 
#include <stdlib.h> 
#include <array> 
#include <sstream> 
#include <iomanip> 

#define WIDTH 640 
#define HEIGHT 360 
#define MAX_SPEED 20

class Boid
{

    public: 
        Boid(); 
        Boid(std::array<double, 2>& position, std::array<double, 2>& velocity);  
    
    private: 
        std::array<double, 2> pos; 
        std::array<double, 2> vel; 
        double maxSpeed; 

}; 
