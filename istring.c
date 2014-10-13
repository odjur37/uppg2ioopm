#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define START(x) ((int*)(((char*)x)-sizeof(int)))
#define STRING(x) ((char*)(((char*)x)+sizeof(int)))


char *istring_mk(const char* str){
  if (str == NULL){
    return NULL;
  }
  
  char* istring = malloc(sizeof(int) + strlen(str) + 1);
  if (istring == NULL){
    exit(1);
  }
  
  *((int*) istring) = strlen(str);
  strcpy(STRING(istring), str);
  return STRING(istring);
}


void istring_rm(char *str){
  free(str);
  str = NULL;
}


char *istring_to_string(const char *str){
  int length = *((START(str)));
  char *temp = malloc(length);
  strncpy(temp, str, length);
  int tempint;
  tempint = strlen(temp);
  temp[tempint+1] = '\0';
  return temp;
}

/*size_t istrfixlen(char *s){
  if (START(s) != strlen(s)){
    *(START(s)) = strlen(s);
    return strlen(s);
  }
*/


char *istrcpy(char *dst, const char *src){
  int i;
  int length = *(START(src));
  *((int*) dst) = length;
  for(i=0; i<=length; i++){
    dst[sizeof(int)+(i)] = src[i];
  }
  return STRING(dst);
}

char *istrncpy(char *dst, const char *src, size_t n){
  int length = *(START(src));
  *((int*) dst) = length;
  while(n>0){
    dst[sizeof(int)+(n)] = src[n];
    n--;
  }
  return STRING(dst);
}


int main(){
  /*char *my_istring = istring_mk("Hej!");
  printf("My first string: %s\n", my_istring);
  char *my_converted_istring = istring_to_string("Bakåtkonverterad sträng!");
  printf("Converted string: %s\n", my_converted_istring);*/
  char arr[40];
  char* temp = istring_mk("UNIX");
  printf("%d\n", *(START(temp)));
  char *my_copy_istring = istrcpy(arr, temp);
  printf("My copy: %s\n", my_copy_istring);
}


