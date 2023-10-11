#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"
#include "math.h"


int is_diag_dom(int mat[][N2]){

    //this is the flag that is returned to tell whether the mat is diagonally
	int isDiag=0;

	//write your code below
	//Return 1 if the matrix is diagonally dominant and 0 otherwise
	
	int i, j, diagonal;
	int n = 0;
	int nonDiagonal = 0;
	
	for(i = 0; i < N2; i++) {						// iterates through the columns of the matrix
		for (j = 0; j < N2; j++) {					// iterates through the rows of the matrix

			if (j == i){							// if the row equals to the column then find the absolute value of that entry and assign it to the variable "diagonal"
				diagonal = fabs(mat[i][j]);
			}
			else{
				nonDiagonal += fabs(mat[i][j]);		// if the row isn't equal to the column, it is a non-diagonal matrix element. Find its absolute value and then then, add these entries together.
			}

			if (diagonal > nonDiagonal) {			// if the abs. value of the diagonal entry is greater than the abs. value sum of the non diagonal entries then the row is diagonally dominant.
				n += 1;
			}
		}
	}
	if (n == N2){									// if each row is diagonally dominant, then the matrix is diagonally dominant. In that case, assign IsDiagonal the value of 1. Otherwise, zero.
		isDiag = 1;
	}

    return isDiag;
}
