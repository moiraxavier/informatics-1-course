#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <iomanip>

bool solveMazeUtil(char **maze, int n, int x, int y);
char **initialise_matrix_randomly(int n);
char **initialise_matrix_manually(int n);
void printMatrix(char **matrix, int n);

bool solveMaze(char **maze, int n);

#endif // MAZE_H