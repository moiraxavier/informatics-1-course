#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// для каждой строки двумерного массива вычислить
// суммы модулей элементов, расположенных после первого нулевого элемента

int main(int argc, char *argv[])
{
    const int nmax = 50, mmax = 50;
    int n = 0, m = 0, matrix[nmax][mmax], min = -10, max = 10, sum;
    
    srand(time(NULL));
    
    printf("Input amount of lines for matrix\n");
    while (n > 50 || n <= 0){
        printf("Input n (0; 50]\n");
        scanf("%d", &n);
    }
    
    printf("Input size of lines for matrix\n");
    while (m > 50 || m <= 0){
        printf("Input m (0; 50]\n");
        scanf("%d", &m);
    }
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        matrix[i][j] = min + rand() % (max - min);
    
    printf("Massiv was entered randomly with numbers from %d to %d\n", min, max);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            printf("%3d",  matrix[i][j]);
        printf("\n");
    }
    printf("\n");
    
    for (int i = 0; i < n; i++){
        sum = 0;
        int j = 0;
        while (matrix[i][j] != 0 && j < n){
            j++;
        }
        
        if (j == n || j == n-1)
            printf("There is no 0 in %d line\n", i+1);
        else 
        {
            for (int k = j; k < m; k++)
                sum += abs(matrix[i][k]);
            
            printf("Sum in %d line = %d\n", i+1, sum);
        }
    }
        
    
    return 0;
}

