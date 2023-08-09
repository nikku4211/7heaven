#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int main()
{
	FILE *csvStream = fopen("../level/str3ttestmap_tile.csv", "r");
	//char tileStream[2048];
	char *tileIndex;
	char cArrayString[2048];
	int lineNum = 18;
	
	//If we don't get a stream, assume there is no file
	if(csvStream == NULL) {
		perror("Error opening file");
		return(-1);
	}
	
	do {
		*tileIndex = fgetc(csvStream);
		strcat(cArrayString, tileIndex);
	} while (!feof(csvStream));
		
	printf("%s", cArrayString);
	fclose(csvStream);
	
	return 0;
}

