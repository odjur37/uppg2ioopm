#include <string.h>
#include <stdio.h>
#include <stdlib.h>
/*#define START 1
#define STRING 2
*/

int main(){
  char *istring_mk(const char* str) {
    if (str == NULL){
      return NULL;
    }
    
    char* istring = malloc(sizeof(int) + strlen(str));
    if (istring == NULL){
      exit(1);
    }
    
    int length;
    length = strlen(str);

    char string_length[length];
    strcpy(string_length, (str + length));
    printf("%c",string_length[1]);

    return 0;
  }
  
  void istring_rm(char *str) {
    free(str);
    str = NULL;
  }
  istring_mk("Hej");
  return 0;

  
  char *istring_to_string(const char *str) {
    int length = *(int *) (str - sizeof(int));
    char *temp = malloc(length);
    strncpy(temp, str, length);
    int tempint;
    tempint = strlen(temp);
    temp[tempint+1] = '\0';
    return temp;
  }
}

