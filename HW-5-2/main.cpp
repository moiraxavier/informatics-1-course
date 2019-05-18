#include <stdio.h> 
#include <iostream>
#include <time.h> 

#include "maze.h"


int main() 
{ 
    // random
    int key, n = 0;
    const int nmax = 10;
    char keystr[10], nstr[10];
    
    char **maze = nullptr;
    
    srand(time(NULL));
    
    do {
        std::cout << "~~~~Menu~~~~" << std::endl;
        std::cout << "1 - Create maze manually" << std::endl;
        std::cout << "2 - Create maze randomly"<< std::endl;
        std::cout << "0 - Exit"<< std::endl;
        do {
            std::cout << "Your input [0/1/2]:" << std::endl;
            std::cin.getline(keystr,sizeof(keystr));
            key = atoi(keystr);
        } while ((strlen(keystr) == 0) || ((key != 0) && (key != 1) && (key != 2)));
        
        if (key != 0){
            do {
                std::cout << "Input size of maze (square matrix) < " << nmax << std::endl;
                std::cout << "Float numbers will be converted to their floor" << std::endl;
                std::cin.getline(nstr,sizeof(nstr));
                n = atoi(nstr);
            } while ((strlen(nstr) == 0) || (n != int(n)) || (n > nmax));

        }
        
        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch (key){
        case 0:{
            std::cout << "EXIT" << std::endl;
        }
            break;
        case 1:{
            maze = initialise_matrix_manually(n);
            solveMaze(maze, n);
        }
            break;
        case 2:{
            maze = initialise_matrix_randomly(n);
            solveMaze(maze, n);
        }
            break;
        default:
            std::cout << "Wrong command" << std::endl;
            break;
        }
        
    } while (key != 0);
	
	return 0; 
} 

