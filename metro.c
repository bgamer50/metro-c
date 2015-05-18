#include <stdio.h>
#include <stdbool.h>
#include "lists.h"
#include <malloc.h>

int main(char* argv[]) {
	Station lfp;
	lfp.name = "L'Enfant Plaza";
	lfp.line = "BOSGYZ"; 
	printf("%s\n", lfp.line);
	parseMap();
}

//Reads the metro map file.
void parseMap() {
	FILE* map = fopen("metromap.data", "r");
	char* e = malloc(sizeof(char) * 100);
	char* f = malloc(sizeof(char) * 100);
	char* g = malloc(sizeof(char) * 100);
	Station stations[100];
	int k = 0;
	while(fscanf(map, "%s %s %d", e, f, g) != EOF) {
		stations[k].name = e;
		stations[k].line = f;
		stations[k].transfer = false;
		if(g[0]==1) stations[k].transfer = true;
		printf("%s %s %d\n", stations[k].name, stations[k].line, stations[k].transfer);
		k++;
	}
}