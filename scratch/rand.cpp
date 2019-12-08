#include<iostream>
#include<ctime>
#include<string> 
#include<cstdio> 


int main(int argc, char **argv){
    if (argc != 1){
        std::cout << "Help!\n " << argv[0] << " <seed>" << std::endl;
    }
    
    std::srand(std::time(0));
    int random_number = std::rand() % 10 - 6;
    if (random_number < 0) {
        random_number +=6;
    }

    std::cout << "random number is " << random_number << std::endl;
    return 0;
}