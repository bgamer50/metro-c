#include <stdio.h>
#include <stdbool.h>
#include "lists.h"
#include <malloc.h>
#include <string.h>

Station stations[91];
int NUMBER_OF_STATIONS;
int main(char* argv[]) {
	int k, i;
	parseMap();
	parseDistances();
	for(k = 1; k < 92; k++) {
		printf("\n%s | ", stations[k].name);
		for(i = 0; i < stations[k].neighborCount; i++) {
			printf("[%s, %d]; ", stations[stations[k].neighbors[i]].name, stations[k].neighborWeights[i]);
		}
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
	int k = 1;
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

void parseDistances() {
	FILE* dist = fopen("metrodist.data", "r");
	int* e = malloc(sizeof(int));
	int* f = malloc(sizeof(int));
	int* g = malloc(sizeof(int));
	Station E; Station F;
	while(fscanf(dist, "%d %d %d", e, f, g) != EOF) {
		stations[*e].neighbors[stations[*e].neighborCount++] = *f;
		stations[*f].neighbors[stations[*f].neighborCount++] = *e;
		//printf("%d %d\n", *f, *e);
		stations[*e].neighborWeights[stations[*e].neighborCount - 1] = *g;
		stations[*f].neighborWeights[stations[*f].neighborCount - 1] = *g;
	}
}