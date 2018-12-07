#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
// дана матрица
// удалить все строки и столбцы, на пересечении которых стоят нулевые элементы
// результирующую матрицу отсортировать по k-му столбцу

// to do: move lines with zeros

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
    
    for (int i = 0; i < n; i++){
        int j = 0;
        while (matrix[i][j] != 0 && j < m)
            j++;
        if (j < m){
            for (int k = i+1; k < n; k++)
                for(int l = 0; l < m; l++)
                    matrix[k-1][l] = matrix[k][l];
            n--, i--;
            for (int k = j+1; k < m; k++)
                for(int l = 0; l < n; l++)
                    matrix[l][k-1] = matrix[l][k];
            m--, j--;
        }
    }
    
    if (!n && !m)
        printf("Matrix was deleted\n");
    else
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++)
                printf("%3d", matrix[i][j]);
            printf("\n");
        }
    
    int sort_col = -1;
    printf("\nBy which column do you want matrix to be sorted?\n");
    while (sort_col > 50 || sort_col <= -1){
        printf("Input input k [0;%d]\n", m);
        scanf("%d", &sort_col);
    }
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n-1; j++)
            if (matrix[j][sort_col] > matrix[j+1][sort_col]){
                for(int k = 0; k < m; k++){
                    matrix[j][k] = matrix[j][k] + matrix[j+1][k];
                    matrix[j+1][k] = matrix[j][k] - matrix[j+1][k];
                    matrix[j][k] = matrix[j][k] - matrix[j+1][k];
                }
                    
            }
    }
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            printf("%3d", matrix[i][j]);
        printf("\n");
    }
        
    
    printf("\n");      
    
    return 0;
}

