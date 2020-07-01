#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

/*returns one if the char is a space*/
int space_char(char c){
  if(c == ' ' || c == '\t' || c == '\0' || c == '\n'){
    return 1;
  }else{
    return 0;
  }
}
/*returns one is the char is not a space*/
int non_space_char(char c){
  if(!space_char(c)){ 
    return 1;
  }else{
    return 0;
  }
}

/*returns a pointer to the first char of a word*/
char *word_start(char *str){
  int i = 0;
  while(1){
    if(non_space_char(str[i])){
      return &str[i];
    }
    i++;
  }  
}
/*returns a pointer to the first space after a word*/
char *word_terminator(char *str){
  int i = 0;
  while(1){ 
    if((space_char(str[i])) && (non_space_char(str[i-1]))){
      return &str[i];
    }
    i++;
  }
}
/*returns the number of words in a string*/
int count_words(char *str){
  char prevChar;
  int i = 0;
  int words = 0;
  while(1){
    /*if current char is a space and the char before is a char, we have a word*/
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

/*returns a new allocated copy of a string*/
char *copy_str(char *inStr, short len){
  char *copy = (char*) malloc((len + 1)*sizeof(char*)); /*len + 1 to store the zero terminator*/
  int i;
  for(i = 0; i < len; inStr++, i ++){
    copy[i] = *inStr;
  }
  copy[i] = '\0'; /* zero terminator */
  return copy;
}

/*function to return tokenized string*/
char** tokenize(char * str){
  int total = count_words(str);
  char **token = (char**)malloc((total+1) * sizeof(char**)); /*allocating memory for char** */
  int i;
  for(i = 0; i < total; i++){
    token[i] = malloc((total+1) * sizeof(char*)); /*allocate space for evry word*/
    
    char* start = word_start(str);
    char* end = word_terminator(start);
    /*we copy the word in the 'array' at position i*/
    token[i] = copy_str(start, (end - start));
    /*call word start after the word that we just saved, so that it looks for the next word*/
    str = word_start(end);
  }
  return token;
  free_tokens(token); /*free the emmory used to allocate the tokens*/

}

/*changed \0 to NULL because i was getting a warning*/
void print_tokens(char **tokens){
  int i = 0;
  while(tokens[i] != NULL){
    printf("[%s]\n",tokens[i]);
    i++;
  }
  printf("\n");
}

/*free the space used to allocate the tokens*/
void free_tokens(char ** tokens){
  int i = 0;
  while(tokens[i] != NULL){
    free(tokens[i]);
    i++;
  }
  free(tokens);
}






































