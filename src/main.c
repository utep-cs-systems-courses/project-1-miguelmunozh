#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"

int main(){


  printf("%d\n",space_char(' ')); //1

  printf("%d\n",space_char('t')); //0

  printf("%d\n",non_space_char('t')); //1

  printf("%d\n",non_space_char(' ')); //0

  printf("%d\n",count_words(" 1 2 3    4 "));

  /*printf("%c\n",word_start("         this   is    where the   word starts?")); //to return the first letter instead of the address*/

  printf("%p\n",word_terminator("         this   is    where the   word starts?"));

  printf("%p\n",word_start("         this   is    where the   word starts?"));



  return 0;
}
