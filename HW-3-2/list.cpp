#include "list.h"

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
        
        if (abs(number) < abs(head->num)){      
            temp = head;
            head = new_element;
            new_element->next = temp;    
        }
        else {
        
            while (current && abs(current->num) <= abs(number)){
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
        printf("List is empty\n");    
    }
    else {
        List * current = head;
        while (current){
            printf("%5d", current->num);
            current = current->next;
        }
        printf("\n\n");
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
        puts("There is no such number in the list\n");
    
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


