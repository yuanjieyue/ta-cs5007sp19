#ifndef A3_H
#define A3_H


/* 
 * Ask on Piazza with any other questions! 
 */

// A Name consists of first, last, and
// and an OPTIONAL middle name.
struct Name {
  char *first;
  char *middle;
  char *last;
};

typedef struct Name Name;


// Print the string <first> <middle> <last>
//  e.g. if first = "Ben", middle = "Ivan", 
//  and last = "Bitdiddle, then print: 
//  "Ben Ivan Bitdiddle".
// 
//  If the middle name is NULL, then print: 
//  "Ben Bitdiddle"
//
//  name: a pointer to a Name
void big(Name *name);

// Print the string <last>, <first>
//  e.g. if first = "Ben", middle = "Ivan", 
//  and last = "Bitdiddle, then print: 
//  "Bitdiddle, Ben".
//
// name: a pointer to a Name
void last(Name *name);


// Print the string <first> <last>
//  e.g. if first = "Ben", middle = "Ivan", 
//  and last = "Bitdiddle, then print: 
//  "Ben Bitdiddle".
//
// name: a pointer to a Name
void reg(Name *name);


// Print the string <first> <middle-initial>. <last>
//  e.g. if first = "Ben", middle = "Ivan", 
//  and last = "Bitdiddle, then print: 
//  "Ben I. Bitdiddle".
//
// If middle name is NULL, print: 
// "Ben Bitdiddle"
// 
// name: a pointer to a Name
void mid(Name *name);

// Print the first name only. 
//  e.g. if first = "Ben", middle = "Ivan", 
//  and last = "Bitdiddle, then print: 
//  "Ben".
//
// name: a pointer to a Name
void small(Name *name);


 // Given a format char, print the given
 // name in the format specified by char.
 // The mapping is shown below:
 // B -> 'big' format
 // L -> 'last' format
 // R -> 'reg' format
 // M -> 'mid' format
 // S -> 'small' format
 // 
 // name: a pointer to a Name
 // format: a char indicating the format to use (case doesn't matter)
void formatName(Name *name, char format);


// Given a name, a format and a destination array, 
// put the properly formatted name in the destination 
// array, not printing anything on the screen. 
// 
 // The mapping is shown below:
 // B -> 'big' format
 // L -> 'last' format
 // R -> 'reg' format
 // M -> 'mid' format
 // S -> 'small' format
// 
// name: a pointer to a Name
// format: a char indicating the format to use (case doesn't matter)
// dest: a pointer to an array that is guaranteed to be big enough to hold the formatted name
void fillName(Name *name, char format, char *dest); 

// Given 3 names, print them in alphabetical 
// order. 
// e.g. "Alyssa Antle", "Charlie Chucker" and "Ben Bitdiddle"
// (and a format of 'r')
// will get printed: 
//
// Alyssa Antle
// Ben Bitdiddle
// Charlie Chucker 
void listByName(Name *n1, Name *n2, Name *n3, char format); 

// Given an array of names, print them in decreasing order 
// of age, in the provided format. 
// e.g. "Alyssa Antle", "Charlie Chucker" and "Ben Bitdiddle"
// (and a format of 'r') the following 
// will get printed: 
//
// Alyssa Antle: 	15
// Ben Bitdiddle: 	14
// Charlie Chucker: 6
void listByAge(Name* names[], char format); 



#endif

