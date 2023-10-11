#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"

void diag_scan(int mat [][N3], int arr []){
	
	int i = 1;
	int line = (2*N3)-1;
	int diag;
	int j=0;

	for (diag=1; diag <= line; diag++){ 					//iterates through diagonals
		int k=1;
		for (i=diag;i>0;i--){								//iterates through rows
			if (i+k == (diag+1) && (i<=N3) && (k<=N3)){		//ensures i and k aren't greater than N3
				arr[j] = mat[i-1][k-1];						//adds the elements of the matrix in order of diagonals
				k++;
				j++;
			}
			else {
				k++;
			}
		}
	}
}
