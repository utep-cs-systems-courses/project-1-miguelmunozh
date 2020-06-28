#include <stdio.h>
#include <stdlib.h>
#include "history.h"

int i =1;

/*initialize the linked list to keep history*/

List* init_history(){
  //allocate space for the list, then for the root (first item in the list)
  List *head = NULL;
  head = (List*)malloc(sizeof(List));
  head->root = (Item*)malloc(sizeof(Item));// REMOVE? DOES THIS CREATE THE EXTRE ITEM?
  //head->root->next= (Item*)malloc(sizeof(Item));
  return head;
}

/*add an item to the end of the list*/
void add_history(List *list, char*str){
  Item *current = list->root;
  //check first if root is null, if so allocate the item there, if not go to the next,
  //we move to the last element in the list, to allocate the new item in the positioin which is
  //null
  while(current->next != NULL){
    current = current->next;
  }
  current->next = (Item*)malloc(sizeof(Item));
  current->next->str = str;
  current->next->id = i++;
  current->next->next = NULL;
}

/*retrieve the string storen in the node where item->id == id*/
char *get_history(List *list, int id){
  Item *current = list->root;
  while(current != NULL){
    if(current->id == id){
      return current->str;
    }
    current = current->next;
  }
}

void print_history(List *list){
  Item *current = list->root;
  while(current != NULL){
    /*while(current->str == NULL){
     current = current->next;
    }*/
    printf("%d.- %s \n", current->id, current->str);
    current = current->next;
  }
}

void free_history(List *list){
  Item *current = list->root;
  while(current != NULL){
    free(current);
    current = current->next;
  }
  free(list);
}








