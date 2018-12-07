#include <stdio.h>
#include <string.h>

bool is_vowel(char c) {
    switch(c) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            return true;
        default:
            return false;
    }
}

// функция п
int from_vowel(char *str){
    int kol = 0;
    
    char *ptr = strtok(str, ",;._ ");
    while (ptr != NULL){
        if (is_vowel(ptr[0])){
            printf("%s\n", ptr);
            kol++;
        }
        
        ptr = strtok(NULL, ",;._ ");
    }
    
    return kol;
}


int main(int argc, char *argv[])
{
    char str[80];
    
    // ввод строки, пока строка не будет введена, те пока ее длина не станет отличной от 0
    while (!strlen(str)){
        printf("Input string\n");
        gets(str);
    }
    
    int k = from_vowel(str);
    if (k)
        printf("%d words beginning from vowel\n", k);
    else              
        printf("No words beginning from vowel\n");
    
    return 0;
}
