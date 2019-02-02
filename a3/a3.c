#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "a3.h"
#include <string.h>
#include <ctype.h>
char* sanitize(char*, int);

void insertion_sort(Name *names[], int num_of_nams);
// YOUR CODE GOES HERE
/*
int main(void) {
	Name name1;
	Name name2;
	Name name3;
	name1.first = "ben";
	name1.middle = "Ivan";
	name1.last = "bitdiddle";
	name2.first = "cin";
	name2.middle = NULL;
	name2.last = "green";
	name3.first = "Dinel";
	name3.middle = "Ellen";
	name3.last = "White";
 	listByName(&name1, &name2, &name3, 'B');
	char* str1 = "this is it";
	char* str2 = "that is it";
	char* str3 = "it is it";
	char* res1 = sanitize(str1, strlen(str1));
	char* res2 = sanitize(str2, strlen(str2));
	char* res3 = sanitize(str3, strlen(str3));
	printf("The string is: %s\n", res1);
	printf("The string is: %s\n", res2);
	printf("The string is: %s\n", res3);


	char dest[100] = {0};
	char dest2[100] = {0};
	fillName(&name1, 'M', dest);
	printf("the dest is %s\n", dest);
	fillName(&name2, 'M', dest2);
	printf("the dest1 is %s\n", dest2);

	big(&name1);
	big(&name2);

	name1.age = 9;
	name2.age = 3;
	name3.age = 6;
	Name* names[3];
	names[0] = &name1;
	names[1] = &name2;
	names[2] = &name3;
	listByAge(names, 3, 'B');
}
*/

char* sanitize(char* str, int len) {
	if (str == NULL || len <= 0) return NULL;
	char* result = (char*) malloc(sizeof(char) * strlen(str));
	char* res = result;
	result[0] = toupper(str[0]);
	int i;
	for (i = 1; i < len; i++) {
		res[i] = tolower(str[i]);
	}
	result[len] = '\0';
	return res;	
}

/*
char* sanitize(char* str, int len) {
//	printf("-------------- Enter Sanitize() ----------\n\n");

	if (str == NULL) return NULL;
//	printf("The string input is %s\n", str);
	char result[len + 1];
	char* res = &result[0];
	result[0] = toupper(str[0]);
	int i;
	for (i = 1; i < len; i++) {
		result[i] = tolower(str[i]);
	}
	result[len] = '\0';
//	printf("The string output is %s\n", res);
	
//	printf("------------- Exit Sanitize()-------------\n\n");
	return res;	
}
*/

void sanitize_name(Name* name) {
	if (name == NULL) return;
	if (name->first != NULL) 
		name->first = sanitize(name->first, strlen(name->first));
	if (name->middle != NULL) 
		name->middle = sanitize(name->middle, strlen(name->middle)); 
	if (name->last != NULL)	
		name->last = sanitize(name->last, strlen(name->last));
}

void big(Name *name) {
	if (name == NULL) return;
	sanitize_name(name);
	char* first = name->first;
	char* middle = name->middle;
       	char* last = name->last;
	if (name->first != NULL) {
		printf("%s ", first);
	}
	if (name->middle != NULL) {
		printf("%s ", middle);
	}
	if (name->last != NULL) {
		printf("%s\n", last);
	}
}


void last(Name *name) {
	if (name == NULL) return;
	sanitize_name(name);
	char* last = name->last;
	char* first = name->first;	
	if (name->last != NULL) {
		printf("%s ", last);
	}

	if (name->first != NULL) {
		printf("%s\n", first);
	}
}

void reg(Name *name) {
	if (name == NULL) return;
	sanitize_name(name);
	char* first = name->first;
	char* last = name->last;
	if (name->first != NULL) {
		printf("%s ", first);
	}
	if (name->last != NULL) {
		printf("%s\n", last);
	}
}

void mid(Name *name) {
	if (name == NULL) return;
	sanitize_name(name);
	char* first = name->first;
	char* middle = name->middle;
       	char* last = name->last;
	if (name->first != NULL) {
		printf("%s ", first);
	}

	if (name->middle != NULL) {
		printf("%c. ", middle[0]);
	}
	if (name->last != NULL) {
		printf("%s\n", last);
	}
}

void small(Name *name) {
	if (name == NULL) return;
	sanitize_name(name);
	char* first = name->first;
	if (name->first != NULL) {
		printf("%s\n", first);
	}
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

void fillName(Name *name, char format, char *dest) {
	char buffer[100] = {0};
	char* first = sanitize(name->first, strlen(name->first));
	char* middle = name->middle == NULL ? NULL : sanitize(name->middle, strlen(name->middle));
	char* last = sanitize(name->last, strlen(name->last));
	char* space = " ";
	char temp[4] = {0};
	switch (format) {
		case 'B':
			strcat(buffer, first);
			strcat(buffer, space);
			if (middle != NULL) {
				strcat(buffer, middle);
				strcat(buffer, space);
			}
			strcat(buffer, last);
			break;
		case 'L':
			strcat(buffer, last);
			strcat(buffer, space);
			strcat(buffer, first);
			break;
		case 'R':
			strcat(buffer, first);
			strcat(buffer, space);
			strcat(buffer, last);
			break;
		case 'M':
			if (middle != NULL) {
				temp[0] = toupper(middle[0]);
				temp[1] = '.';
				temp[2] = '\0';
			} else {
				temp[0] = '\0';
			}
			strcat(buffer, first);
			strcat(buffer, space);
			strcat(buffer, temp);
			if (middle != NULL) {
				strcat(buffer, space);
			}
		       	strcat(buffer, last);	
			break;
		case 'S':
			strcat(buffer, first);
			break;
		default:
			break;
	}
	strcpy(dest, buffer);

}


void listByName(Name *n1, Name *n2, Name *n3, char format) {
	char buffer_n1[100] = {0};
	char buffer_n2[100] = {0};
	char buffer_n3[100] = {0};
	fillName(n1, format, buffer_n1);
	fillName(n2, format, buffer_n2);
	fillName(n3, format, buffer_n3);
	
	if (strcmp(buffer_n1, buffer_n2) <= 0) {
		if (strcmp(buffer_n1, buffer_n3) <= 0) {
			if (strcmp(buffer_n2, buffer_n3) <= 0) {
				printf("%s\n%s\n%s\n", buffer_n1, buffer_n2, buffer_n3);
			} else {
				printf("%s\n%s\n%s\n", buffer_n1, buffer_n3, buffer_n2);
			}
		} else {			
			printf("%s\n%s\n%s\n", buffer_n3, buffer_n1, buffer_n2);
		}
	} else {
		if (strcmp(buffer_n2, buffer_n3) <= 0) {
			if (strcmp(buffer_n1, buffer_n3) <= 0) {
				printf("%s\n%s\n%s\n", buffer_n2, buffer_n1, buffer_n3);
			} else {
				printf("%s\n%s\n%s\n", buffer_n2, buffer_n3, buffer_n1);
			}

		} else {	
			printf("%s\n%s\n%s\n", buffer_n3, buffer_n2, buffer_n1);
		}	
	
	}
} 

void insertion_sort(Name* names[], int num_of_names) {
	if (names == NULL) return;
	int i, j;
        Name* key;
	for (i = 1; i < num_of_names; i++) {
		key = names[i];
		j = i - 1;
		while (j >= 0 && names[j]->age >= key->age) {
			Name* temp = names[j];
			names[j] = names[j + 1];
			names[j + 1] = temp;
			j--;
		}
		names[j + 1] = key;
	}
}


void listByAge(Name *names[], int num_of_names, char format) { 
	if (names == NULL) return;
	insertion_sort(names, num_of_names);	
	int i;
	for (i = 0; i < num_of_names; i++) {
		formatName(names[i], format);
	}
}

