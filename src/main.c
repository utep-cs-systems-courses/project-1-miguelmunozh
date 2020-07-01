#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

int main (){

  char in[60];
  List *list = init_history();
  int selection;
  int innerSel;
  while(selection != -1){
    printf("enter 1 to tokenize a string\n      2 to print history\n     -1 to quit\n");

    scanf("%d",&selection);
    char tmp;
    scanf("%c",&tmp);
    
    if(selection == 1){
      printf("Enter string to tokenize:\n > ");
      fgets(in,100,stdin);
      add_history(list,in);
      char **tokens = tokenize(in);
      print_tokens(tokens);/*print tokens*/
      free_tokens(tokens); /*free the emmory used to allocate the tokens*/      
      
    }
    if(selection == 2){
      printf("\nHistory of strings:\n");
      print_history(list);
      printf("\nSelect a string number to print or -1 to go back\n");

      scanf("%d",&innerSel);
      char tmp;
      scanf("%c",&tmp);
      if(innerSel != -1){
      char ** token = tokenize(get_history(list,innerSel));
      print_tokens(token);
      free_tokens(token);	
      }
    }
  }
  printf("\nBYE!\n");
  free_history(list);
    
return 0;
}

