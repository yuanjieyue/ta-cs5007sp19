/**
 * Author: Yuanjie Yue
 * Date:   02/25/2019
 *
 * Helper Files: implementing all the helper functions, like read file function, print function.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "a5.h"

char** readFile(char* fileName){
	char** rows = (char**) malloc(sizeof(char*) * MAX_CHAR_IN_LINE);

	FILE *cfPtr;
	if ((cfPtr = fopen(fileName, "r")) == NULL) {
		printf("File could not be opened\n");
	} else {
		/*
		char c;
		while (!feof(cfPtr)) {
			c = fgetc(cfPtr);
			printf("%c\n", c);
		}
		*/

		char buffer[MAX_CHAR_IN_LINE];
		int i = 0;
		while (fgets(buffer, MAX_CHAR_IN_LINE, cfPtr) != NULL) {
			rows[i] = strdup(buffer);
			// printf("the %dth line is %s\n", i, rows[i]);
			/*
			// printf("-------------------The first line is-----------------\n %s\n", buffer);
			char* string, *found;
			string = strdup(buffer);
			// printf("-------------------The original string is------------\n %s\n", string);
			// int j = 0;
			while ((found = strsep(&string, ",")) != NULL) {
				printf("the %d element is %s\n", j, found);
				j++;
			}
			*/
			i++;
		}
	}
	fclose(cfPtr);
	return rows;
}

void printLines(char** rows) {
	for (int i = 0; i < MAX_CHAR_IN_LINE; i++) {
		if (rows[i] != NULL) {
			printf("%s\n", rows[i]);
		}
	}
}	
