#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"


void addEff(int val1[], int val2[], int val3[], int pos1[], int pos2[], int pos3[], int k1, int k2){
	
	int x = 0;
	int y = 0;
    int i = 0;
    int moreThan = 0;
	int z = 0;

	if(pos1[k1-1]>= pos2[k2-1])  							// assigns the greatest value of pos1 and pos2 to moreThan
	{
		moreThan = pos1[k1-1];
	}
	else
	{
		moreThan = pos2[k2-1];
	}

	for(i=0; i<=(k1+k2); i++)								 // iterates through the total indexes of val3
		{
		if((pos1[x] == pos2[y]) && (pos1[x] == (i+1)) ){ 	// if pos has the same value as val1 and val2, then the value of val1 and val2 are added together
			val3[z] = (val1[x] + val2[y]);
			pos3[z] = pos1[x];
			x++;											//increment by 1 for every loop
			y++;
			z++;
		}

		else{
			if(pos1[x]> pos2[y] && pos2[y] == (i+1)) 		//if the value isn't found in the first array, then the values of the second array are added to pos3/val3
				{
				val3[z] = val2[y];
				pos3[z] = pos2[y];
				y++;
				z++;
				}

			else
			{
				if(pos1[x]< pos2[y] && pos1[x] == (i+1))	//if the value isn't found in the second array, then the values of the first array are added to pos3/val3
					{
					val3[z] = val1[x];
					pos3[z] = pos1[x];
					x++;
					z++;
					}


				else  										//adds 0 to end of the array
				{
					if (i>moreThan)
					{
						val3[i] = 0;
					}
				}
			}
		}
	}
}
