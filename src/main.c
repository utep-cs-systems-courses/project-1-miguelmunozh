#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

int main(){
  
  char *str = "\ta 1\tooo\t ppp \t";
  print_tokens(tokenize(str));
  print_tokens(tokenize("   b 2    "));
  print_tokens(tokenize("a b v c miguelmunozh"));
  print_tokens(tokenize("v vvvvv cc c    c\t"));
  print_tokens(tokenize("v v b"));
  print_tokens(tokenize(" v v b "));

  print_tokens(tokenize("\tv v o\t"));


 List *list = init_history();
  add_history(list,str);
  add_history(list,"miguel munoz h");
  add_history(list,"testing the history part ");
  print_history(list);
  // get_history(list,1);    
  print_tokens(tokenize(get_history(list,3)));

  //free history when we exit the program
  free_history(list);



  
  /* 
  char in[100];
  List *list = init_history();

  int a;
  int m;
  while(a != -1){
    printf("enter 1 to tokenize a string\n      2 to print history\n     -1 to quit\n");
    scanf("%d",&a);
    char tmp;
    scanf("%c",&tmp);
    
    if(a == 1){
      printf("Enter string to tokenize:\n > ");

 
      fgets(in,100,stdin);
      add_history(list,in);
    
      char **tokens = tokenize(in);
      print_tokens(tokens);
  
    }
    if(a == 2){
      printf("\nHistory of strings:\n");
      print_history(list);
      
      printf("\nSelect a string number to print or -1 to quit\n");
      scanf("%d",&m);
      char tmp;
      scanf("%c",&tmp);
      
      print_tokens(tokenize(get_history(list,m)));
    }
    
  }
  printf("\nBYE!\n");
  free_history(list);
*/
  

  
return 0;
}
