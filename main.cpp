#include "boid.cpp"


int main(int argc, char* argv[]){
    
    if(argc < 2){
      std::cout << "Please provide seed value" << std:: endl;   
      return 1; 
    }
    srand(argv[1]); 



    std::cout << "Hello World" << std::endl; 




    return 0; 
}