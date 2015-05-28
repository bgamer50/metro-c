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
	for(k = 0; k < 91; k++) {
		printf("%s %d %d\n", stations[k].name, stations[k].neighbors[0], 0);
	}
	printf("\nhello\n");
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
		stations[k].neighborCount = 0;
		stations[k].transfer = false;
		if(*g==1) stations[k].transfer = true;
		//printf("%s %s %d\n", stations[k].name, stations[k].line, stations[k].transfer);
		k++;
	}
	NUMBER_OF_STATIONS = *g;
}

Station* int2Station(int k) {
	return &stations[k - 1];
}

void parseDistances() {
	FILE* dist = fopen("metrodist.data", "r");
	int* e = malloc(sizeof(int));
	int* f = malloc(sizeof(int));
	int* g = malloc(sizeof(int));
	Station E; Station F;
	while(fscanf(dist, "%d %d %d", e, f, g) != EOF) {
		stations[*e - 1].neighbors[stations[*e - 1].neighborCount++] = *f;
		stations[*f - 1].neighbors[stations[*f - 1].neighborCount++] = *e;
		//printf("%d %d\n", *f, *e);
	}
}