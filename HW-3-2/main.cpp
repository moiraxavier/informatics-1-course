/*Часть 2. Строки и динамические структуры.
С клавиатуры вводятся строки, содержащие целые числа,
записанные через пробел. Организовать из вводимых чисел однонаправленный список,
упорядоченный по  абсолютной величине числа. 
В программе предусмотреть возможность добавления в список нового элемента и
удаления элемента, равного введенному с клавиатуры.
Вывести на печать список и
проверить функции добавления и удаления элементов списка.
*/

#include <stdio.h>
#include <string.h>

#include "list.h"

int str_to_int(char * str); // convert char * to int with sentsitivity to +/-


int main(int argc, char *argv[])
{
    List * head = NULL;
    char str[80];
    
    // list input
    printf("Input strings with numbers and spaces\n");
    gets(str);
    // tokenisation
    char * ptr = strtok(str, " ");
    while (ptr != NULL){
        head = append(head, str_to_int(ptr));
        ptr = strtok(NULL, " ");
    }
    // print inputed list   
    printf("\nList\n");
    print_list(head);

    while (printf("OPTIONS:\n1 :     ADD element to list\n2 :     DELETE element from list\nENTER : EXIT\n\n"), gets(str), strlen(str) != 0) {
        char * str_num;
        printf("Input element\n");
        gets(str_num);
        
        switch (str_to_int(str)) {
            case 1 :
                head = append(head, str_to_int(str_num));
                break;
            case 2 :
                head = delete_from_list(head, str_to_int(str_num));
                break;
            default : 
                printf("No such option\n");        
        }

        printf("\nList\n\n");
        print_list(head);
    }
    
    // free memory
    head = delete_list(head);
    
    return 0;
}
    
int str_to_int(char * str){
    int n;
    if (str[0] == '-'){
        for (size_t i = 0; i < strlen(str); i++)
            str[i] = str[i+1];
        n = atoi(str) * (-1);
    }
    else
        n = atoi(str);
    
    return n;
}

