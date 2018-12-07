#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
// дана матрица
// удалить строки между максимальным и минимальным элементами k-го столбца

int main(int argc, char *argv[])
{
    const int nmax = 50;
    int n = 0, m = 0, matrix[nmax][nmax], min = -10, max = 10;

    
    srand(time(NULL));
    
    printf("Input amount of lines for matrix\n");
    while (n > 50 || n <= 0){
        printf("Input n (0; 50]\n");
        scanf("%d", &n);
    }
    
    printf("Input amount of lines for matrix\n");
    while (m > 50 || m <= 0){
        printf("Input m (0; 50]\n");
        scanf("%d", &m);
    }
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            matrix[i][j] = min + rand() % (max - min);
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            printf("%3d", matrix[i][j]);
        printf("\n");
    }
    printf("\n");
    
    int del = -1;
    printf("\nWhat column?\n");
    while (del <= -1 || del > m){
        printf("Input input k [0;%d]\n", m);
        scanf("%d", &del);
    }
    
    for (int i = 0; i < n; i++){
        
    }
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            printf("%3d", matrix[i][j]);
        printf("\n");
    }
        
    
    printf("\n");      
    
    return 0;
}

