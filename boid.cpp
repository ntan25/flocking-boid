#include "boid.h"

typedef std::vector<Boid*> boidVec; 


Boid::Boid(){
    



}

Boid::Boid(std::array<double, 2>& position, std::array<double, 2>& velocity){
    
    if(num[0] > WIDTH || num[1] > HEIGHT){
        std::cout << "Invalid start position" << std::endl; 
        return; 
    }
    if(velocity[0] > MAX_SPEED || velocity[1] > MAX_SPEED){
        std::cout << "Invalid velocity value" << std::endl; 
    }

    this->pos = position;
    this->vel = velocity; 
    this->maxSpeed = MAX_SPEED; 
}



