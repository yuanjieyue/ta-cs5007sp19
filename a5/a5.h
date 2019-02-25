/**
 * Author: yuanjie yue
 * Date: 02/25/2019
 * Header File: a5.h
 */

#ifndef A5_H
#define A5_H

#define MAX_CHAR_IN_LINE 100000

/* ------------ helper functions ------------------  */

/**
 * Read the file with given name into a string array, each slot stores data in one line.
 * Given: the name of the file to read from.
 * Return: the pointer to an array of strings, in which each slot stores chars in one line.
 */ 
char** readFile(char*);

/**
 * Print the content in each slot of given char array.
 * Given: the pointer to an array of strings.
 * Return: print all strings out.
 */
void readLines(char**);

#endif
