#include "list.h"

List * append(List * head, int number){
    
    List * new_element = new List;
    new_element->num = number;
    new_element->next = NULL;
   
    if (head == NULL)  
       head = new_element;
    else{      
        List * current = head;

        while (current->next)
            current = current->next;
        
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
            printf("%5d", current->num);
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

void pos_neg_lists(List * head, List ** head_pos, List ** head_neg){
    if (head == NULL){
        printf("List is empty\n");
    }
    else {
        List * curr = head;
        while (curr != NULL){
            if (curr->num >= 0)
                *head_pos = append(*head_pos, curr->num);
            else
                *head_neg = append(*head_neg, curr->num);
            curr = curr->next;
        }
    }
}

List * join_lists(List * head1, List * head2){   
    List * head = NULL;
    List * curr = head1;
    
    while (curr != NULL){
        head = append(head, curr->num);
        curr = curr->next;
    }
    
    curr = head2;
    while (curr != NULL){
        head = append(head, curr->num);
        curr = curr->next;
    }
   
    
    return head;  
}


