// Посчитать в введенной строке количество
// 1. маленьких букв
// 2. больших букв
// 3. цифр и их сумму
// 4. спец. сиволов

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
// проверка символов строки на то, являются ли они маленькими буквами, большими буквами
// цифрами (тогда находим их сумму) или спец символами
void count_chars(char *str){
    int sum = 0, small_let = 0, big_let = 0, num = 0, symb = 0;
    
    for(int i = 0; i < strlen(str); i++){
        // если это буква
        if (isalpha(str[i])){
            if (islower(str[i])) //проверим, маленькая ли она
                small_let++;
            else //если нет, значит, она большая
                big_let++;
        }
        else // если не буква
            if (isdigit(str[i])){ //проверим, является ли цифрой
                num++;
                sum = sum + (str[i]-'0'); // str[i]-'0' - "цифра" = номер в ASCII самой цифры - номер в ASCII нуля
            }
            else // если не буква и не цифра, значит, символ
                symb++;        
    }
    
    if (small_let)
        printf("%d small letters in string\n", small_let);
    else
        printf("No small letters in string\n");
    
    if (big_let)
        printf("%d big letters in string\n", big_let);
    else
        printf("No big letters in string\n");
    
    if (num)
        printf("%d numbers in string. Their sum is %d\n", num, sum);
    else
        printf("No numbers in string\n");
    
    if (symb)
        printf("%d symbols in string\n", symb);
    else
        printf("No symbols in string\n");
}

int main(int argc, char *argv[])
{
    char str[80];
    
    // ввод строки, пока строка не будет введена, те пока ее длина не станет отличной от 0
    while (!strlen(str)){
        printf("Input string\n");
        gets(str);
    }
    
    count_chars(str);
    
    return 0;
}
