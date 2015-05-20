#include <stdio.h>
#include <stdbool.h>
#include "lists.h"
#include <malloc.h>
#include <string.h>

Station stations[91];
int NUMBER_OF_STATIONS;
int main(char* argv[]) {
	int k;
	parseMap();
	parseDistances();
	for(k = 0; k < 5; k++) {
		printf("%s\n", stations[k].name);
	}
}

//Reads the metro map file.
void parseMap() {
	FILE* map = fopen("metromap.data", "r");
	char* e = malloc(sizeof(char) * 50);
	char* f = malloc(sizeof(char) * 50);
	int* g = malloc(sizeof(int));
	int* h = malloc(sizeof(int));
	fscanf(map, "%d", g);
	int k = 0;
	while(fscanf(map, "%s %s %d %d", e, f, g, h) != EOF) {
		strcpy(stations[k].name, e);
		stations[k].line = f;
		stations[k].ID = *h;
		stations[k].transfer = false;
		if(*g==1) stations[k].transfer = true;
		printf("%s %s %d\n", stations[k].name, stations[k].line, stations[k].transfer);
		k++;
	}
	NUMBER_OF_STATIONS = *g;
}

void parseDistances() {
	FILE* dist = fopen("metrodist.data", "r");
	char* e = malloc(sizeof(char) * 100);
	char* f = malloc(sizeof(char) * 100);
	int* g = malloc(sizeof(int));
	Station E; Station F;
	while(fscanf(dist, "%s %s %d", e, f, g) != EOF) {
		E = stations[*e]; F = stations[*f];
		E.neighbors[E.neighborCount++] = *f;
		F.neighbors[F.neighborCount++] = *e;
	}
}