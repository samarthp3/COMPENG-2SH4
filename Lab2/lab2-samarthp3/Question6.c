#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"


void efficient(const int source[], int val[], int pos[], int size){

	int i;
	int j=0;

	for (i=0; i < size; i++){			//iterates through each element in source[]

		if (source[i] != 0){			//if the value at the ith index of source[] is a non-zero element
			val[j]=source[i];			//add the non-zero element to val[]
			pos[j]=i;					//add the index of the non-zero element to pos[]
			j++;
		}
	}
}

void reconstruct(int source[], int m, const int val[], const int pos[], int n){

    int i;
	int j=0;
    
    for(i = 0; i < m; i++){				//iterates until the size of source[] is reached

    	if (i == pos[j]){				//if the ith index is equal to the index of the non-zero elements in pos[]
    		source[i] = val[j];			//add that non-zero element to the ith index of source[]
    		j++;
    	}
    	else{
    		source[i]=0;				//the value at the ith index of source[] is just zero otherwise
    	}
    }
	

}
