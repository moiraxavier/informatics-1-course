#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// дан целочисленный массив <=50 эл-в
// рандомное заполнение
// поменять первую и вторучю часть

int main(int argc, char *argv[])
{
    const int nmax = 50;
    int n = 0, massiv[nmax], min = 0, max = 10;
    
    srand(time(NULL));
    
    printf("Input size of massiv\n");
    while (n > 50 || n <= 0){
        printf("Input n (0; 50]\n");
        scanf("%d", &n);
    }
    
    for (int i = 0; i < n; i++)
        massiv[i] = min + rand() % (max - min);
    
    printf("Massiv was entered randomly with numbers from %d to %d\n", min, max);
    for (int i = 0; i < n; i++)
        printf("%3d", massiv[i]);
    printf("\n");
    
    for (int i = 0; i < (n/2); i++){
        int t = n/2 + n%2 + i;
        massiv[i] = massiv[i] + massiv[t];
        massiv[t] = massiv[i] - massiv[t];
        massiv[i] = massiv[i] - massiv[t];
    }
    
    printf("Massiv was changed\n");
    for (int i = 0; i < n; i++)
        printf("%3d", massiv[i]);
    printf("\n");
        
    
    return 0;
}
