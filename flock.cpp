#include "flock.h"

Flock::Flock(size_t seed){
    srand(seed); 
    double px, py, vx, vy; 

    for(int i = 0; i < 20; ++i){
        px = rand() % WIDTH; 
        py = rand() % HEIGHT;
        vx = rand() % MAX_SPEED; 
        vy = rand() % MAX_SPEED;  

        std::array<double, 2> position{px, py}; 
        std::array<double, 2> velocity{vx, vy}; 
        
        Boid* to_add = new Boid;
        to_add->pos = position; 
        to_add->vel = velocity;
        to_add->maxSpeed = MAX_SPEED; 

        boids.push_back(to_add); 
    }
}

Flock::Flock(size_t seed, int numBoids){
    srand(seed); 
    double px, py, vx, vy; 

    for(int i = 0; i < numBoids; ++i){
        px = rand() % WIDTH; 
        py = rand() % HEIGHT;
        vx = rand() % MAX_SPEED; 
        vy = rand() % MAX_SPEED;  

        std::array<double, 2> position{px, py}; 
        std::array<double, 2> velocity{vx, vy}; 
        
        Boid* to_add = new Boid;
        to_add->pos = position; 
        to_add->vel = velocity;
        to_add->maxSpeed = MAX_SPEED; 

        boids.push_back(to_add); 
    }
}

Flock::~Flock(){
    for(int i = 0; i < boids.size(); ++i){
        delete boids[i]; 
    }
}








