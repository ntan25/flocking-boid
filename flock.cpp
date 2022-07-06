#include "flock.h"


void arrayAdd(std::array<double, 2>& a, std::array<double, 2>& b); 


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

boidVec Flock::getNeighbors(Boid& b){
    boidVec res; 
    double neighborDistance = 40.;
    for(auto& c : this->boids){
        if(abs(b.pos[0] - c->pos[0]) <= neighborDistance || abs(b.pos[1] - c->pos[1]) <= neighborDistance){
            if(!(abs(b.pos[0] - c->pos[0]) == 0)){ //make sure we are not including itslef in the neighborhood
                res.push_back(c);
            }
        }
    }
    return res; 
}

//Center of Mass Excluding the Boid passed as an argument
std::array<double, 2> Flock::centerofMass(Boid& b){
    std::array<double, 2> res; 
    
    double px = 0.;
    double py = 0.; 

    for(auto& c : this->boids){
        //Is this the boid passed in as an input, if so ignore
        if(c->pos[0] == b.pos[0] && c->pos[1] == b.pos[1] && c->vel[0] == b.vel[0] && c->vel[1] == b.vel[1]){
            continue; 
        }
        else{
            px += c->pos[0]; 
            py += c->pos[1]; 
        }
    }

    px /= (this->boids.size() - 1); 
    py /= (this->boids.size() - 1); 

    res[0] = px; 
    res[1] = py; 

    return res; 
}

//Center of Mass excluding boid and only neighbors
std::array<double, 2> Flock::neighborCenter(boidVec neighbors){
    std::array<double, 2> res; 

    double px = 0; 
    double py = 0; 

    for(auto& c: neighbors){
        px += c->pos[0]; 
        py += c->pos[1];    
    }

    px /= neighbors.size(); 
    py /= neighbors.size(); 

    res[0] = px; 
    res[1] = py; 

    return res; 
}

std::array<double, 2> Flock::neighborVelocity(boidVec neighbors){
    std::array<double, 2> res; 

    double vx = 0.; 
    double vy = 0.; 

    for(auto& c: neighbors){
        vx += c->vel[0]; 
        vy += c->vel[1]; 
    }

    vx /= neighbors.size();
    vy /= neighbors.size(); 

    res[0] = vx; 
    res[1] = vy; 

    return res; 
}

//Rules will only apply to the velocity position gets updated as a function of velocity

// Rule 1: Boids flock towards the center
std::array<double, 2> Flock::Cohesion(Boid& b, boidVec neighbors){

    std::array<double, 2> res{0., 0.}; 
    if(neighbors.size() == 0) return res; 

    res = neighborCenter(neighbors); 


    //moving one percent closer to center of mass 
    res[0] /= 100; 
    res[1] /= 100;

    return res; 
}

//Rule 2: Ensure no overlap between boids to amke sure they are not near each other
std::array<double, 2>  Flock::Separation(Boid& b, boidVec neighbors){

    double boid_padding = 8.; 
    std::array<double, 2> res{0., 0.};
    if(neighbors.size() == 0) return res;

    for(auto& c: neighbors){
        if(abs(b.pos[0] - c->pos[0]) <= boid_padding || abs(b.pos[1] - c->pos[1]) <= boid_padding){
            res[0] -= c->pos[0] - b.pos[0]; 
            res[1] -= c->pos[1] - b.pos[1]; 
        }
    }

    return res; 
}

//Rule 3: Align velocity vectors based on neighbors 
std::array<double, 2> Flock::Alignment(Boid& b, boidVec neighbors){
    std::array<double, 2> res{0., 0.};
    if(neighbors.size() == 0) return res; 

    res = neighborVelocity(neighbors); 

    res[0] -= b.vel[0]; 
    res[1] -= b.vel[1]; 

    res[0] /= 100; 
    res[1] /= 100; 

    return res; 
}


//This is going to look something like a += b
void arrayAdd(std::array<double, 2>& a, std::array<double, 2>& b){
    a[0] += b[0]; 
    a[1] += b[1]; 
}

//Updates positions of every boid
void Flock::update(){

    int time_days = 20; 
    int t_step = 30; 


    for(int i = 0; i < time_days * t_step; ++i){
        for(const auto& c: this->boids){
            boidVec n = getNeighbors(*c); 
            std::array<double, 2> v1{0., 0.};
            std::array<double, 2> v2{0., 0.};
            std::array<double, 2> v3{0., 0.};

            v1 = this->Cohesion(*c, n);
            v2 = this->Separation(*c, n); 
            v3 = this->Alignment(*c, n); 


            //Combine vectors for the three rules
            arrayAdd(c->vel, v1);
            arrayAdd(c->vel, v2);
            arrayAdd(c->vel, v3); 

            //Update position
            arrayAdd(c->pos, c->vel); 

        }
    }
    
}







