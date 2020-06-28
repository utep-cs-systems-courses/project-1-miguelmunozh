#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

int main(){
  
  char in[100];
  /*bugs when reading input*/
  /*
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
   
      char **tokens = tokenize(in);
      add_history(list,in);
      print_tokens(tokens);
  

    }
    if(a == 2){
      printf("\nHistory of strings:\n");
      print_history(list);
      printf("\nSelect a string number to print or -1 to quit\n");
      scanf("%d",&m);
      
      print_tokens(tokenize(get_history(list,m)));
    }
    
  }
  printf("\nBYE!\n");

*/
  // SAME ERROR THANT WITH ABOVE UI

  //char *in;
  /*
    printf("%s", "> ");
    fgets(in, sizeof(in), stdin);
    //printf("%s", in);

    char **tokens = tokenize(in);
    print_tokens(tokens);
  */
  
  
  
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
  print_tokens(tokenize(get_history(list,2)));
     

  
return 0;
}
