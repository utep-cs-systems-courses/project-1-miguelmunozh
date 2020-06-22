#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c){
  if(c == ' ' || c == '\t' || c == '\0'){
    return 1;
  }else{
    return 0;
  }
}
int non_space_char(char c){
  if(!space_char(c)){ /*check  is not a space, (anything than a space or tab)*/
    return 1;
  }else{
    return 0;
  }
}
//this returns a pointer to a char, and accepts a pointer to a char
char *word_start(char *s){
  int i = 0;
  while(1){
    //if the char at s[i] is not a space or tab, then it is the first char and we return it
    if(non_space_char(s[i])){
      return &s[i];
    }
    i++;
  }  
}
char *word_terminator(char *s){
  int i = 0;
  while(1){ // until the end of the string
    //if the char at position s[i] is a space and the char at position s[i-1] is a char, return it, i++ otherwise
    if((space_char(s[i])) && (non_space_char(s[i-1]))){
      return &s[i]; // the address of the last char in the first word, // s[0] actual char
    }
    i++;
  }
}

int count_words(char *str){
  char prevChar;
  int i = 0;
  int words = 0;
  while(1){
    //if current char is a space/tab
    if(space_char(str[i])){
      //if the char before the space is a char then we have a word
      if(non_space_char(prevChar)){
	words++;
      }
    }
    prevChar = str[i];
    if(str[i] == '\0'){
      break;
    }else{
      i++;
    }
  }
  return words;
}










