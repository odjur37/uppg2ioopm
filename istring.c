#include <string.h>
#include <stdio.h>
#include <stdlib.h>
/*#define START 1
#define STRING 2
*/

char *istring_mk(const char* str){
  if (str == NULL){
    return NULL;
  }
  
  char* istring = malloc(sizeof(int) + strlen(str) + 1);
  if (istring == NULL){
    exit(1);
  }
  
  int length;
  length = strlen(str);
  char string_length[sizeof(int)+1] = {length,'\0'};
  strcpy(istring, string_length);
  printf("%c is the length of str\n",*istring);
  strcpy((istring+4), str);
  printf("%c is the complete istring\n",*istring);


  return istring;
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
  if(dst && src == NULL){
  }
  int i;
  int length = strlen(src) - 1;
  for(i=length; i>=0; i--){
    dst[i] = src[i];
 }
  return dst;
}

char *istrncpy(char *dst, const char *src, size_t n){
  if(dst && src == NULL){
  }
  
  while(n>=0){
    n--;
    dst[n] = src[n];
  }
  return dst;
}


int main(){
  char my_istring;
  my_istring = istring_mk("Hej!");
  char *arr[] = {};
  puts(istrcpy(arr, my_istring));  
}


