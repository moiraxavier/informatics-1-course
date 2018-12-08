/*
 * Дана текстовая строка. Из нее сформировать односвязный список,
 * отсортированный при вводе по алфавиту и удалить все гласные.
 * 
 *  String is given. Make list sorted during input in the alphabet order,
 *  delete vowels from list.
 */



#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct List{
    char symb;
    List * next;
} List;

// add elements to the list
List * append(List * head, char c);
// print list
void print_list(List * head);
// delete vowels
List * delete_vowels(List * head);
// check is it vowel
bool isVowel(char c);



int main(int argc, char *argv[])
{
    char str[80];
    
    while (!strlen(str)){
        printf("Input string. All letters will be added to the list, other char-s will be ignored\n");
        gets(str);
    }
    
    List * head = NULL;
    // input string, make list
    int length = strlen(str);
    for (int i = 0; i < length; i++)
        if (isalpha(str[i]))
            head = append(head, str[i]);
    print_list(head);
    // delete vowels from list
    head = delete_vowels(head);
    print_list(head);
    


    return 0;
}

List * append(List * head, char c){
    List * new_el = new List;
    new_el->symb = c;
    
    if (head == NULL){
        head = new_el;
        head->next = NULL;
    }
    else{
        List * curr = head;
        if (c < head->symb){
            new_el->next = curr;
            head = new_el;
        }
        else {
            List * temp;
            while (curr && c >= curr->symb){
                temp = curr;
                curr = curr->next;
            }
            new_el->next = temp->next;
            temp->next = new_el;
        }
    }
    
    return head;
}

void print_list(List * head){
    if (head == NULL){
        printf("List is empty\n");
    }
    else{
        printf("List:\n");
        List * curr = head;
        while (curr){
            printf("%3c", curr->symb);
            curr = curr->next;
        }
    }
    printf("\n");
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

List * delete_vowels(List * head){
    List * curr = head, * prev = head;
    
    while (curr){
        if (isVowel(curr->symb)){
            if (curr == head){
                curr = curr->next;
                delete head;
                head = curr;
            }
            else {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
                
            }
        }
        else {
            prev = curr;
            curr = curr->next;
        }
    }
    
    return head;
}
