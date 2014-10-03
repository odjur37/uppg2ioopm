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
   return NULL;
 }
 int length;
 length = strlen(str);
 return istring;
}
 
 void istring_rm(char *str) {
   free(str);
   str = NULL;
 }
  }
