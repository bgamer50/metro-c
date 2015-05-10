typedef struct stn {
	int ID;
	char* name;
	int* neighbors;
	char* line; //yellow rush is Z.
	bool transfer;
} Station;