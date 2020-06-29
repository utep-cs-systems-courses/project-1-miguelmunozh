#include <stdio.h>
#include <stdlib.h>
#include "history.h"

int i =1;

/*initialize the linked list to keep history*/
List* init_history(){
  List *head = (List*)malloc(sizeof(List)); /*allocate space for the list*/
  head->root = NULL;
  return head;
}

/*add an item to the end of the list*/
void add_history(List *list, char*str){
  Item* current;
  current = list->root;
  if (list->root == NULL) {
    list->root = (Item*) malloc(sizeof(Item));
    list->root->id = i++;
    list->root->str = str;
    list->root->next = NULL;
  } else {
    while (current->next != NULL) {   /*loop to the last element*/
      current = current->next;
    }//get out of the loop when current->next is null
    current->next = (Item*) malloc(sizeof(Item));   /*allocate memory for each item added*/
    current->next->id = i++;
    current->next->str =str;
    current->next->next = NULL;
  }
}

/*return the string stored in the list where item->id == id*/
char *get_history(List *list, int id){
    Item* current = list->root;
    while (current != NULL) {
      if (current->id == id) {
	
	return current->str;
	}
      current = current->next;
    }
}

/*prints the items of the list*/
void print_history(List *list){
  Item *current = list->root;
  while(current != NULL){
    printf("%d.- %s \n", current->id, current->str);
    current = current->next;
  }
}

/*free the items of the list*/
void free_history(List *list){
  Item *current = list->root;
  while(current != NULL){
    free(current);
    current = current->next;
  }
  free(list);
}
