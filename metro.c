#include <stdio.h>
#include <stdbool.h>
#include "lists.h"
#include <malloc.h>

/**Line Declarations**/
Station* orangeLine;
Station* silverLine;
Station* blueLine;
Station* redLine;
Station* greenLine;
Station* yellowLine;
Station* yellowLine2;
/**End Line Declarations**/

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
	char* e = malloc(sizeof(char*) * 100);
	Station* currentLine = orangeLine;
	while(fscanf(map, "%s", e) != EOF) {
		if(e[0] == '%')
			switch(e[1]) {
				case 'O': currentLine = orangeLine; break;
				case 'S': currentLine = silverLine; break;
				case 'B': currentLine = blueLine; break;
				case 'R': currentLine = redLine; break;
				case 'G': currentLine = greenLine; break;
				case 'Y': currentLine = yellowLine; break;
				case 'Z': currentLine = yellowLine2; break;
			}
	}
}