#include "flock.cpp"


int main(int argc, char* argv[]){
    
    if(argc < 2){
      std::cout << "Please provide seed value" << std:: endl;   
      return 1; 
    }

    Flock env(atoi(argv[1])); 

    for(auto &b : env.boids){
      std::cout << b << std::endl; 
    }


    



    std::cout << "Hello World" << std::endl; 




    return 0; 
}