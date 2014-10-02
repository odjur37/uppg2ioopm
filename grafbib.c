typedef struct node{
  int *busstop;
  int *time;
  struct node *next;
} *Node;

typedef struct arch{
  int *busnumber;
  int *traveltime;
} *Arch;
