#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Questions.h"



char *my_strcat(const char * const str1, const char * const str2){

	/* this is the pointer holding the string to return */
	char *z = NULL;
	

	/*write your implementation here*/

	int stringLength;
	int i, j;
	int k=0;

	stringLength = strlen(str1) + strlen(str2);
	z = calloc(stringLength, sizeof(char));

	for (i = 0; str1[i] != '\0'; i++){
		z[k] = str1[i];
		k++;
	}

	for (j = 0; str2[j] != '\0'; j++){
		z[k] = str2[j];
		k++;
	}

	/* finally, return the string*/
	return z;
	
}
