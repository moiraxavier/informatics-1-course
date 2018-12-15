/*
 * Из входной строки сформировать список слов,
 * после каждого слова, заканчивающегося на гласную, добавить
 * новый элемент списка, содержащий три восклицательных знака
 * 
 */

#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

typedef struct List {
  char *word; 
  List *next; // next list element
  List *prev; // previous
} List;

bool isVowel(char c);
List * append(List *, char *); // add element to the list
void print_list(List * head); // print list
List * delete_list(List * head); // delete all list
List * add_exclamation_mark(List * head);

int main(int argc, char *argv[])
{
    List * head = NULL;
    char str[80];
    
    printf("Input string with words devided by ' '\n");
    gets(str);
    
    char * ptr = strtok(str, " ");
    while (ptr != NULL){
        head = append(head, ptr);
        printf("%s", ptr);
        ptr = strtok(NULL, " ");
    }
    
    printf("Your input:\n");
    print_list(head);
    printf("List with added !!! after words end by vowel\n");
    head = add_exclamation_mark(head);
    print_list(head);
    
    head = delete_list(head);
    
    return 0;
}

bool isVowel(char c){
    switch(tolower(c)) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return true;
        default:
            return false;
        }
}


List * append(List * head, char * str){
    
    List * new_element = new List;
    strcpy(new_element->word, str);
    new_element->next = NULL;
   
    if (head == NULL)  {
       head = new_element;
       head->prev = NULL;
    }
    else{      
        List * current = head;

        while (current->next)
            current = current->next;
        
        new_element->prev = current;
        current->next = new_element;              
    }
    
    return head;
}

void print_list(List * head){
    
    if (head == NULL){
        printf("List is empty\n");    
    }
    else {
        List * current = head;
        while (current){
            printf(" %s", current->word);
            current = current->next;
        }
        printf("\n\n");
    }

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

List * add_exclamation_mark(List * head){
    List * curr = head;
    List * excl;
    
    while (curr){
        if (isVowel((curr->word)[strlen(curr->word)-1])){
            excl = new List;
            strcpy(excl->word, "!!!");
            
            if (curr->next)
                (curr->next)->prev = excl;
            excl->next = curr->next;
            excl->prev = curr;
            curr->next = excl;
        }
        curr = curr->next;
    }
    
    return head;
}

