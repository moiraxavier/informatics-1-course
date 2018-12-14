#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

typedef struct List {
  int num; 
  List *next; // next list element
} List;

List * append(List *, int); // add element to the list
void print_list(List * head); // print list
List * delete_list(List * head); // delete all list
void pos_neg_lists(List * head, List **head_pos, List **head_neg);
List * join_lists(List * head1, List * head2);