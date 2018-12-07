#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
// дана матрица
// сортировка по убыванию произведений строк

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
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - 1; j++){
            float S1 = 0, S2 = 0;
            for (int k = 0; k < m; k++){
                if (matrix[j+1][k] < 0 && (abs(matrix[j+1][k]) % 2 == 0))
                    S2 = S2 + matrix[j+1][k];
                if (matrix[j][k] < 0 && (abs(matrix[j][k]) % 2 == 0))
                    S1 = S1 + matrix[j][k];
            }

            if (S2 > S1){
                for (int l = 0; l < m; l++){
                    matrix[j][l] = matrix[j][l] + matrix[j+1][l];
                    matrix[j+1][l] = matrix[j][l] - matrix[j+1][l];
                    matrix[j][l] = matrix[j][l] - matrix[j+1][l];
                }
            }
        }            
    
    for (int i = 0; i < n; i++){
        float S = 0;
        for (int j = 0; j < m; j++){
            printf("%3d", matrix[i][j]);
            if (matrix[i][j] < 0 && (abs(matrix[i][j]) % 2 == 0))
                S = S + matrix[i][j];
        }
        printf("%20f\n", S);
    }
    
    
    printf("\n");      
    
    return 0;
}

