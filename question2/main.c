#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mystring.h"

/* Rawan Alsaadi 10081442 	*
 * Omar Toutounji 10169506	*
 * Beltan Michel 10169162	*/

int main(){
	
	char* a = "A first string, ";
	char* b = "followed by a second string";
	char* source = "A string with a lot of characters that are nice and charactery.";
	char target[strlen(source)];
	int from = 10;
	int n = 30;
	char* newString;
	substring(source, from, n, target);
	newString = safestrcat(a, b);
	printf("Result from substring: %s, result from safestrcat: %s \n", target, newString);
	free(newString);
	
}
