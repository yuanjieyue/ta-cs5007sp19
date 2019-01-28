#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include "a3.h"
#include <string.h>


void str_print(char *str);
// YOUR CODE GOES HERE
/*
int main(void) {
	char *first = "Ben";
	char *middle = "Ivan";
	char *last = "Bitdiddle";
	char *null;
	if (null == NULL) {
		printf("first is NULL\n");
	} else {
		printf("first is not NULL\n");
	}
	
	int i;
	int len = strlen(first);
	printf("The length of the string is %d\n", len);
	for (i = 0; i < strlen(first); i++) {	
		printf("%c\n", *(first + i));
	}
}
*/


void str_print(char *str) {
	int i = 0;
	while (str[i] != '\0') {
		printf("%c", str[i]);
		i++;
	}
}

void big(Name *name) {
	char *first = name->first;
	char *middle = name->middle;
	char *last = name->last;
	str_print(first);
	printf(" ");
	if (middle != NULL) {
		str_print(middle);
		printf(" ");	
	}
	str_print(last);
	printf("\n");
}


void last(Name *name) {
	char *first = name->first;
	char *last = name->last;
	str_print(last);
	printf(" ");
	str_print(first);
	printf("\n");
}

void reg(Name *name) {
	char *first = name->first;
	char *last = name->last;
	str_print(first);
	printf(" ");
	str_print(last);
	printf("\n");

}

void mid(Name *name) {
	char *first = name->first;
	char *middle = name->middle;
	char *last = name->last;

	str_print(first);
	printf(" ");
	if (middle != NULL) {
		printf("%c. ", *middle);
	}
	str_print(last);
	printf("\n");

}

void small(Name *name) {
	char* first = name->first;
	str_print(first);
	printf("\n");
}

void formatName(Name *name, char format) {
	
	switch (format) {
		case 'B':
			big(name);
			break;
		case 'L':
			last(name);
			break;
		case 'R':
			reg(name);
			break;
		case 'M':
			mid(name);
			break;
		case 'S':
			small(name);
			break;
		default:
			break;
	}
}

void fill(char* src, char *dest) {
	int i = 0;

	while (src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	dest[i] = ' ';
}

void fillName(Name *name, char format, char *dest) {
	char *first = name->first;
	char *middle = name->middle;
	char *last = name->last;
	int first_len = strlen(first);
	int middle_len = strlen(middle);
	int last_len = strlen(last);
	switch (format) {
		case 'B':
			fill(first, dest);
			if (middle != NULL) {
				fill(middle, dest + first_len + 1);
				fill(last, dest + first_len + middle_len + 2);
			} else {
				fill(last, dest + first_len + 1);
			}
			break;
		case 'L':
			fill(last, dest);
			fill(first, dest + last_len + 1);
			break;
		case 'R':
			fill(first, dest);
			fill(last, dest + first_len + 1);
			break;
		case 'M': 
			fill(first, dest);
			if (middle != NULL) {
				dest[first_len + 1] = middle[0];
				dest[first_len + 2] = '.';
				fill(last, dest + first_len + 3);
			} else {
				fill(last, dest + first_len + 1);
			}
			break;
		case 'S':
			fill(first, dest);
			break;
		default:
			break;
	}	
}	

void listByName(Name *n1, Name *n2, Name *n3, char format) {
		
}

void listByAge(Name *names[], char format) {
	
}

