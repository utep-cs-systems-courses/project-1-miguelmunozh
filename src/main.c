#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

int main(){
  
  char *str = "\t hello \tUTEP is ok\t  \t";
  print_tokens(tokenize(str));
  print_tokens(tokenize("   hello  world    "));
  print_tokens(tokenize("a b  c d\t e f g  h  k\t"));
 

 List *list = init_history();
  add_history(list,str);
  add_history(list,"miguel munoz h");
  add_history(list,"testing the history part ");

  printf("%s\n","Printing history of words:");
  
  print_history(list);
  // get_history(list,1);    
  print_tokens(tokenize(get_history(list,3)));

  /*free history when we exit the program*/
  free_history(list);
  
return 0;
}
