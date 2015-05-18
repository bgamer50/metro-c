#include "station.h"
typedef struct node {
	struct node* next;
	Station* content;
} Node;

typedef struct ll {
	Node head;
} LinkedList;

bool equals(char* a, char* b) {
	int k;
	if(strlen(a) != strlen(b))
		return false;
	for(k = 0; k < strlen(a); k++)
		if(a[k] != b[k])
			return false;
	return true;
}