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
#include <iostream>

using namespace std;

typedef struct List {
  int num; 
  List *next; // next list element
} List;


List * append(List *, int); // add element to the list
void print_list(List * head); // print list
List * delete_from_list(List *, int); // delete element from list
List * delete_list(List * head); // delete all list


int main(int argc, char *argv[])
{
    List * head = NULL;
    char str[80];
    
    printf("Input strings with numbers and spaces\n");
    gets(str);
    
    char * ptr = strtok(str, " ");
    while (ptr != NULL){
        head = append(head, stoi(ptr));
        ptr = strtok(NULL, " ");
    }
        
    printf("\nList\n");
    print_list(head);
    
    int x;
    printf("What numbers do you want to delete from list?\n");
    scanf("%d", &x);
    head = delete_from_list(head, x);
    printf("\nList\n");
    print_list(head);
    head = delete_list(head);
    
    return 0;
}

List * append(List * head, int number){
    
    List * new_element = new List;
    List * temp;
    new_element->num = number;
   
    if (head == NULL){     
       head = new_element;
       head->next = NULL;
    }
    else{      
        List * current = head;
        
        if (number < head->num){      
            temp = head;
            head = new_element;
            new_element->next = temp;    
        }
        else {
        
            while (current && abs(current->num) <= number){
                temp = current;
                current = current->next;
            }
            
            new_element->next = temp->next;
            temp->next = new_element;
        }
                  
    }
    
    return head;
}

void print_list(List * head){
    
    if (head == NULL){
        printf("List does not exist\n");    
    }
    else {
        List * current = head;
        while (current){
            printf("%5d", current->num);
            current = current->next;
        }
        printf("\n");
    }

}

List * delete_from_list(List * head, int number){
    List * prev = head, * current = head;
    bool flag = true;
    
    while (current){
        if (current->num == number){
            if (current == head){
                current = current->next;
                delete head;
                head = current;
                prev = head;
                flag = false;
            }
            else {
                prev->next = current->next;
                delete current;
                current = prev->next;
                flag = false;
            }
        }
        else {
            prev = current;
            current = current->next;
        }
    }
    
    if (flag) 
        printf("There is no %d in list\n", number);
    
    return head;
}

List * delete_list(List * head){
    List * current = head;
    
    while (head){
        head = head->next;
        delete current;
        current = head;
    }
    
    return head;
}

