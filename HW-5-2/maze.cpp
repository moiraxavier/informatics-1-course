#include "maze.h"

bool solveMazeUtil(char **maze, int n, int x, int y) 
{ 
    // (x,y) is outside maze
    if (x < 0 || x >= n || y < 0 || y >= n)
        return false;
    
	// (x,y) is the goal
	if (x == n - 1 && y == n - 1) { 
		*(*(maze + x) + y) = '+'; 
		return true; 
	} 
    
    // (x,y) is not open
    if (*(*(maze + x) + y) != '.') 
		return false; 

    // mark x, y as part of solution path 
    *(*(maze + x) + y) = '+';

    if (solveMazeUtil(maze, n, x - 1, y) == true) 
        return true; 
    
    if (solveMazeUtil(maze, n, x, y + 1) == true) 
        return true; 

    if (solveMazeUtil(maze, n, x+1, y) == true) 
        return true; 
    
    if (solveMazeUtil(maze, n, x, y-1) == true) 
        return true; 

    // If none of the above movements work then move back: 
    // unmark x, y as part of solution path 
    *(*(maze + x) + y) = '.';
    
    return false; 

} 

char **initialise_matrix_randomly(int n){
    char ** matrix;
    matrix = new char *[n];
    
    for (int i = 0; i < n; i++){
        *(matrix + i) = new char [n];
        for (int j = 0; j < n; j++){
            if (rand() % 2)
                *(*(matrix + i) + j) = '.';
            else {
                *(*(matrix + i) + j) = '#';
            }
        }
    }
    *(*(matrix + 0) + 0) = '.';
    *(*(matrix + n - 1) + n - 1) = '.';
    
    return matrix;
}

char **initialise_matrix_manually(int n){
    char ** matrix;
    matrix = new char *[n];
    char* buf = new char[n];
    
    for (int i = 0; i < n; i++){
        *(matrix + i) = new char [n];
        std::cin >> buf;
        for (int j = 0; j < n; j++){
            *(*(matrix + i) + j) = buf[j];
        }
    }
    *(*(matrix + 0) + 0) = '.';
    *(*(matrix + n - 1) + n - 1) = '.';
    
    return matrix;
}

void printMatrix(char **matrix, int n) { 
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            std::cout << std::setw(2) << *(*(matrix + i) + j);
        std::cout << std::endl;
    } 
} 

// A function calling solveMazeUtil(maze, n, 0, 0) (which begins recursion)
// Prints Maze and Path
bool solveMaze(char **maze, int n) {
    // matrix of maze
    std::cout << "----------Maze----------" << std::endl;
    printMatrix(maze, n); 
    
	if (solveMazeUtil(maze, n, 0, 0) == false) { 
		std::cout << "-----Solution doesn't exist-----" << std::endl; 
		return false; 
	} 
    std::cout << "----------Solution----------" << std::endl;
	printMatrix(maze, n); 
	return true; 
} 

