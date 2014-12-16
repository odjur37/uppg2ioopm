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



size_t istrfixlen(char *s){
  char *tmp = malloc(strlen(s)+1);
  strcpy(tmp, s);
  if (tmp[strlen(s)+1] != '\0'){
    tmp[strlen(s)+1] = '\0';	
  }
  if (*(START(tmp)) != strlen(tmp)){
    *(START(tmp)) = strlen(tmp);
  }
  return *(START(tmp));
}

char* istrslen(char *s, size_t length){
  s[*(START(s))] = (int)length;
  while (length != strlen(s)) {
    malloc(strlen(s)+1);
    s[strlen(s)+1] = s[strlen(s)];
  }
  malloc(strlen(s)+1);
  s[length+1] = '\0';
  return s;
}

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
  for(int i = 0; i < n; i++){
    dst[sizeof(int)+(i)] = src[i];
  }
  dst[sizeof(int)+(n)] = '\0';
  return STRING(dst);
}

char *istrchr(const char *s, int c){
  return strchr(s, c);
}

char *istrrchr(const char *s, int c){
  return strrchr(s, c);
}

int istrcmp(const char *s1, const char *s2){
  return strcmp(s1,s2);
}

int istrncmp(const char *s1, const char *s2, size_t n){
  return strncmp(s1, s2, n);
}

size_t istrlen(const char *s){
  return strlen(s);
}

char *istrcat(char *dst, const char *src){
  return  strcat(dst,src);
}

char *istrncat(char *dst, const char *src, size_t n){
  return strncat(dst, src, n);
}


/* int main(){ */
/*   char *my_istr = istring_mk("Hej "); */
/*   char *my_istr_cat = istring_mk("på dig"); */
/*   char *cat_istr = istrcat(my_istr, my_istr_cat); */
/*   printf("%s\n",cat_istr); */
/* } */
