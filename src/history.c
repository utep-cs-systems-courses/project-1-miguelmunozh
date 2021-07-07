#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"


/*initialize the linked list to keep history*/
List* init_history(){
  List *head = (List*)malloc(sizeof(List)); /*allocate space for the list*/
  head->root = NULL;
  return head;
}

/*Helper method to copy a string and allocate memory for the string with copy_str*/
char *str_copy(char *str){
  char *end = str;
  while(*end != '\0'){
    end++;
  }
  int len = end-str-1; 
  return copy_str(str,len); /*return a copy of the whole string*/
}


/*add an item to the end of the list*/
void add_history(List *list, char*str){
char *copy = str_copy(str);
  
  if (list->root == NULL) {
    list->root = (Item*) malloc(sizeof(Item));
    list->root->id = 1;
    list->root->str = copy;
    list->root->next = NULL;
  } else {
      Item* current;
      current = list->root;
      while (current->next != NULL) {   /*loop to the last element*/
      current = current->next;
    }//get out of the loop when current->next is null
    current->next = (Item*) malloc(sizeof(Item));   /*allocate memory for each item added*/
    current->next->id = current->id +1;
    current->next->str = copy;
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
      if(current->next == NULL){
	return "indexOutOfBounds";
      }else{
      current = current->next;
      }}
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
    free(current->str);
    free(current);
    current = current->next;
  }
  free(list);
}
