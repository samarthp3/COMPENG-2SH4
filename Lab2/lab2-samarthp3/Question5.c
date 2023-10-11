#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"

void string_copy(const char source[], char destination[], int n){

	int i;
	
	for (i = 0; source[i] != '\0'; i++){			// iterates through each char of the inputed string from source[]
		if (i < n-1){								// if the index of the string is less than (n-1), which is the index of each char in source[], then that char is appended to the string destination[]
			destination[i] = source[i];
		}
	}
	destination[n] = '\0';						//the final char of the destination[] string is the null character
}
