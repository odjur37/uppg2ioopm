#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define START(x) (x+sizeof(int))
#define STRING(x) (x-sizeof(int))


char *istring_mk(const char* str){
  if (str == NULL){
    return NULL;
  }
  
  char* istring = malloc(sizeof(int) + strlen(str) + 1);
  if (istring == NULL){
    exit(1);
  }
  
  *((int*) istring) = strlen(str);
  strcpy(START(istring), str);
  return START(istring);
}


void istring_rm(char *str){
  free(str);
  str = NULL;
}


char *istring_to_string(const char *str){
  int length = *(int *) (str - sizeof(int));
  char *temp = malloc(length);
  strncpy(temp, str, length);
  int tempint;
  tempint = strlen(temp);
  temp[tempint+1] = '\0';
  return temp;
}

char *istrcpy(char *dst, const char *src){
  int i;
  int length = *((int*)(STRING(src)));
  *((int*) dst) = length;
  for(i=0; i<=length; i++){
    dst[START(i)] = src[i];
  }
  return START(dst);
}

/*char *istrncpy(char *dst, const char *src, size_t n){
  if(dst && src == NULL){
  }
  
  while(n>=0){
    n--;
    dst[n] = src[n];
  }
  return dst;
  }*/


int main(){
  char *my_istring;
  my_istring = istring_mk("Hej!");
  printf("My string:%s\n", my_istring);
  char arr[45];
  printf("Here is the copied string:%s\n",istrcpy(arr, my_istring));  
}


