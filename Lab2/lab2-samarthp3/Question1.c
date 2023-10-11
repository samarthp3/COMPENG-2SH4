#include <stdio.h>
#include <stdlib.h>

#include<math.h>
#include "Questions.h"



void add_vectors(double vector1[],double vector2[],double vector3[],int size)
{
    /*vector3 should store the sum of vector1 and vector2. 
	You may assume that all three arrays have the size equal to n
	*/
	//write your code below
	int i;
	for (i=0; i<size; i++)												//iterates through the vector1 and vector2 arrays starting at index 0. The ith index of each array are added to each other and stored in vector3's ith index.
	{
		vector3[i] = vector1[i] + vector2[i];
	}
}

double scalar_prod(double vector1[],double vector2[],int size)
{
	// this is the variable holding the scalar product of the two vectors
    double prod=0;

	//write your code below to calculate the prod value
	
    int i = 0;

    
    for (i=0; i<size; i++) {
    	prod += vector1[i] * vector2[i];						//stores the product of the ith index of both vector 1 and 2
    											//adds the ith term to the overall scalar product

    }
	// return the result
    return prod;
}

double norm2(double vector1[], int size)
{
	//this is the variable holding the L2 norm of the passed vector
    double L2;
	//write your code here
	// you should call function scalar_prod().

    L2 = sqrt(scalar_prod(vector1, vector1, size));			//the norm is the scalar product of the same vector square rooted. therefore vector1 is called twice through the scalar_prod function and then that value is square rooted to find the norm.
	
	//finally, return the L2 norm 
    return L2;
}
