/*Часть 1. Создание модулей. Указатель на функцию. 
Разработать модуль, содержащий указанную процедуру. Написать тестирующую программу.
Составить подпрограмму-процедуру MASSHTAB отыскания масштаба
графического (выведенного в текстовом режиме) изображения функции f(x)
на экране размером B единиц растра по формуле M=B/max f(x),
где B – заданная величина, вводимая с клавиатуры.
В основной программе использовать процедуру для отыскания масштаба функций
x*sin(x) и tg(x), при –1 < x < 1.
*/

#include <stdio.h>
#include <math.h>
#include "masshtab.h"

// x*sin(x)
float x_sin(float x){
    return x * sin(x);
}

// tg(x)
float tg(float x){
    return tan(x);
}

int main(int argc, char *argv[])
{
    int B = 0;
    do {
        printf("Input B > 0 - size of the screen\n");
        scanf("%d", &B);
    } while (B <= 0);

    printf("M SIN(x) is %f\n", MASSHTAB(x_sin, B));
    printf("M TG(x) is %f\n", MASSHTAB(tg, B));
    
    return 0;
}
