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
char *word_start(char *str){
  int i = 0;
  while(1){
    //if the char at s[i] is not a space or tab, then it is the first char and we return it
    if(non_space_char(str[i])){
      return &str[i];
    }
    i++;
  }  
}
char *word_terminator(char *str){
  int i = 0;
  while(1){ // until the end of the string
    //if the char at position s[i] is a space and the char at position s[i-1] is a char, return it, i++ otherwise
    if((space_char(str[i])) && (non_space_char(str[i-1]))){
      return &str[i]; // the address of the last char in the first word, // s[0] actual char
    }
    i++;
  }
}

int count_words(char *str){
  char prevChar;
  int i = 0;
  int words = 0;
  while(1){
    //if current char is a space/tab and one char before that is a char, we have a word
    if(space_char(str[i]) && non_space_char(prevChar)){
	words++;
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

char *copy_str(char *inStr, short len){
  char *copy = (char*) malloc((len + 1)*sizeof(char*));   //len + 1 to store the zero terminator
  int i;
  for(i = 0; i < len; inStr++, i ++){
    copy[i] = *inStr;
  }
  copy[i] = '\0';
  return copy;
}
char** tokenize(char * str){
  int total = count_words(str);
  //allocating memory for the array of tokens
  char **token = (char**)malloc((total+1) * sizeof(char**));
  int i;
  for(i = 0; i < total; i++){
    //space for each word in the array
    token[i] = malloc((total+1) * sizeof(char*)); /*if I comment this it still work*/

    //start and end of each word
    char* start = word_start(str);
    char* end = word_terminator(start);
    //we copy the word in the array at position i, witht he length of the word
    token[i] = copy_str(start, (end - start));
    //then we update the string to find word start after the end fo the word that we just saved
    str = word_start(end);
  }
  return token;
  free_tokens(token);
}

//changed \0 to NULL because i was getting a warning
void print_tokens(char **tokens){
  int i = 0;
  while(tokens[i] != NULL){
    printf("[%s]\n",tokens[i]);
    i++;
  }
  printf("\n");
}

void free_tokens(char ** tokens){
  int i = 0;
  while(tokens[i] != NULL){
    free(tokens[i]);
    i++;
  }
  free(tokens);
}






































