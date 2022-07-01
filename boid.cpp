#include "boid.h"

typedef std::vector<Boid*> boidVec; 


Boid::Boid(){

    double vx = rand() % MAX_SPEED;
    double vy = rand() % MAX_SPEED; 
    double x_pos = rand() % WIDTH; 
    double y_pos = rand() % HEIGHT;

    std::array<double, 2> posVec{x_pos, y_pos}; 
    std::array<double, 2> velocityVec{vx, vy}; 

    this->pos = posVec; 
    this->vel = velocityVec; 
    this->maxSpeed = MAX_SPEED;
}

Boid::Boid(std::array<double, 2>& position, std::array<double, 2>& velocity){
    
    if(pos[0] > WIDTH || pos[1] > HEIGHT){
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



