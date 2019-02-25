/**
 * Author: Yuanjie Yue
 * Date:   02/25/2019
 *
 * C File: implementing dijikstra algorithm on graph represented by adjacence matrix.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "a5.h"

int main(){
	char* milesGraphFile = "miles_graph.csv";
	char** rows = readFile(milesGraphFile);
	printLines(rows);
	char* string, *found;
	

	for (int i = 0; i < MAX_CHAR_IN_LINE; i++) {
		if (rows[i] == NULL) break;
		if (i == 1) {
			string = strdup(rows[i]);
			printf("-------------------The original string is------------\n %s\n", string);
			int j = 0;
			while ((found = strsep(&string, ",")) != NULL) {
				printf("the %d element is %s\n", j, found);
				j++;
			}
	
		}
	}
	return 0;
}

