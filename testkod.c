#include <stdio.h>

int main(int argc, char *argv[]){
  char a[3] = {'1','2','3'};
  printf("%c is the third element", *(a+1));
  return 0;
}
