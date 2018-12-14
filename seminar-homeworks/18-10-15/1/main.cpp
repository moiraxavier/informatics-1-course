/*
 *  Создать односвязный список из чисел.
 *  На основании его сформировать два списка с положительными и отрицательными элементами.
 *  Склеить два списка в один.
 *  Пример: 2 -1 3 -4
 *  -1 -4 | 2 3
 */

#include <stdio.h>
#include <string.h>
#include "list.h"

int str_to_int(char * str); // convert char * to int with sentsitivity to +/-


int main(int argc, char *argv[])
{
    List * head = NULL, * head_pos = NULL, * head_neg = NULL;
    
    char str[80];
    printf("Input positive and negative numbers to make a list\n");
    while (gets(str), strlen(str) != 0)
        head = append(head, str_to_int(str));
    printf("Your input:\n");
    print_list(head);
    
    // make list of postitive numbers and list of negative numbers from first list
    pos_neg_lists(head, &head_pos, &head_neg);
    printf("List of positive numbers:\n");
    print_list(head_pos);
    printf("List of negative numbers:\n");
    print_list(head_neg);
    
    // delete first list
    head = delete_list(head);
    // new list positive+negative list
    head = join_lists(head_pos, head_neg);
    printf("United list:\n");
    print_list(head);

    return 0;
}

int str_to_int(char * str){
    int num;
    if (str[0] == '-'){
        for (size_t i = 0; i < strlen(str); i++)
            str[i] = str[i+1];
        num = atoi(str) * (-1);
    }
    else
        num = atoi(str);
    
    return num;
}

