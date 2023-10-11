#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Questions.h"

void letter_freq(const char word[], int freq[]){

	int i,j;
	int n = 65;											//ASCII equivalent of 'a'
	int m = 97;											//ASCII equivalent of 'A"
	int counter = 0;

	for (i = 0; i < 26; i++) {							//iterate from a (i = 0) to z (i = 25)

		for(j=0; word[j] != '\0'; j++){					//iterate from the first char in the string word[] to the last.

			if (n == word[j] || m == word[j]){			//if the j'th char of word[] is equal to n or m, then add it to its counter. If not, iterate through each character until the right letter is found.
				counter++;
			}
		}
		n++;											// add 1 to the ASCII number assigned to n to go to the next letter
		m++;
		freq[i] = counter;								// add the value of the counter to the list freq[]
		counter = 0;									// reset the counter
	}
}
