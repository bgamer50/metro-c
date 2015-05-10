#include "station.h"
typedef struct node {
	struct node* next;
	Station* content;
} Node;

typedef struct ll {
	Node head;
} LinkedList;