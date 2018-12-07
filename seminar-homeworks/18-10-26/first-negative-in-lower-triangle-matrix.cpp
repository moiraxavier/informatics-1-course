#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
// дана квадратная матрица, в нижнем треугольнике поменять 
// первый отрицательный с наиболее близким по значению среднего арифметического этой матрицы

int main(int argc, char *argv[])
{
    const int nmax = 50;
    int n = 0,matrix[nmax][nmax], min = -10, max = 10;
    float SA=0;
    
    srand(time(NULL));
    
    printf("Input amount of lines for matrix\n");
    while (n > 50 || n <= 0){
        printf("Input n (0; 50]\n");
        scanf("%d", &n);
    }
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        matrix[i][j] = min + rand() % (max - min);
    
    printf("Massiv was entered randomly with numbers from %d to %d\n", min, max);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            printf("%3d",  matrix[i][j]);
        printf("\n");
    }
    printf("\n");
    
    // среднее арифметическое
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            SA += matrix[i][j];
    SA = SA / (n * n);
    printf("SA = %5.2f\n", SA);
    
    // поиск первого отрицательного в нижнем треугольнике (включ диагонали)
    int i_ = -1, j_ = -1;
    for (int i = n/2; i < n; i++)
        for (int j = n-1-i; j <= i && i_ == -1; j++)
            if (matrix[i][j] < 0)
                i_ = i, j_ = j;
    
    // наиболее близкое по значению
    int d = 100, i_d = -1, j_d = -1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (fabs(SA - matrix[i][j]) < d){
                d = fabs(SA - matrix[i][j]);
                i_d = i, j_d = j;
            }
    printf("%d ~~ SA\n\n", matrix[i_d][j_d]);
    
    matrix[i_][j_] += matrix[i_d][j_d];
    matrix[i_d][j_d] = matrix[i_][j_]  - matrix[i_d][j_d];
    matrix[i_][j_] = matrix[i_][j_] - matrix[i_d][j_d];
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            printf("%3d",  matrix[i][j]);
        printf("\n");
    }
    printf("\n");      
    
    return 0;
}

