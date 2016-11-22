#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mystring.h"

char* safestrcat(char *a, char *b){
	
	/* These three statements will calculate the length of a, of b,	*
	 * and then create a new string of appropriate size.			*/
	int lenA = strlen(a);
	int lenB = strlen(b);
	char *newString = malloc(lenA+lenB);
	
	/*Adds the characters in a to the newString, from the start.	*/
	for (int i = 0; i<lenA; i++){
		newString[i] = a[i];
	}
	
	/* Adds the characters in b to the newString, starting from the	*
	 * end of a in newString										*/
	int newStrIndex;
	for (int n = 0; n<lenB; n++){
		newStrIndex = n + lenA;
		newString[newStrIndex] = b[n];
	}
	
	return newString;
	
}

int substring(char *source, int from, int n, char *target){
	
	/* Cases for failure:											*
	 * 		- sum of from and n bigger than source					*
	 * 		- from smaller than 0, n smaller than 1					*
	 *		- source is empty										*
	 * 		- It is assumed that target is >= to n					*/
	 
	if ((strlen(source) == 0) || (from < 0) || (n < 1) || ((from + n) > strlen(source))){ 
		return -1;
	}
	for (int i = 0; i<n; i++){
		target[i] = source[from+i];
	}
	return 0; 
	
}


