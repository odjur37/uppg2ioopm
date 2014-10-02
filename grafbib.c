struct edgedata {
  unsigned short travel_time;
  unsigned short bus_line;
};

unsigned short getWeightFromEdgeData(void *d) {
  return ((struct edgedata*) d)->travel_time;

typedef struct node{
  char *busstop;
  struct node *connections;
  struct arch *directions;
} *Node;

void traveltime (Node *start, Node *destination){
  start->



};

