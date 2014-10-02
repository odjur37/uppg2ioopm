#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int *busstop;
  int *time;
  struct node *next;
} *Node;

typedef struct arch{
  int *busnumber;
  int *traveltime;
} *Arch;


/* ett till argument? eftersom node tar strukten består av två*/
Node nyNod (char *busstop) { 
     Node newNode = malloc(sizeof(struct node));
     newNode->busstop = malloc(strlen(busstop) + 1);
     strcpy(newNode->busstop, busstop);
     return newNode;
}

Arch nyArch() {
}

Node query() {
}

void destroyNode() {
}

void destroyArch() {
}

void insert () {
}

