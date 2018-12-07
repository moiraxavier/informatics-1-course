#include <stdio.h>
#include <string.h>

// функция проверки на палиндром
bool isPalindrome(char *str){
    
    bool flag = true;
    // если i–й элемент отличен от (n-i-1)–го, где n-длина строки, то это не палиндром
    for(int i = 0; i < strlen(str)/2 && flag; i++)
        if (str[i] != str[strlen(str)-i-1])
            flag = false;
    
    return flag;
}


int main(int argc, char *argv[])
{
    char str[80];
    
    // ввод строки, пока строка не будет введена, те пока ее длина не станет отличной от 0
    while (!strlen(str)){
        printf("Input string\n");
        gets(str);
    }
    
    if (isPalindrome(str))
        printf("%s is palindrome\n", str);
    else
        printf("%s isn't palindrome\n", str);
    
    return 0;
}
