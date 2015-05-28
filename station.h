typedef struct stn {
	int ID;
	char name[50];
	int neighbors[4];
	int neighborCount;
	char* line; //yellow rush is Z.
	bool transfer;
} Station;