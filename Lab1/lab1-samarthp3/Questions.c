
#include "Questions.h"



int Q1_for(){
	int sum = 0, i;							// initialize variable "sum" which will get incremented by 1 each time a multiple of 4 between 3 and 1000 is found
	
	// calculate your sum below..this has to use for loop
	
	for (i = 30; i <= 1000; i++)			// for works only for integers between 30 and 1000
	{
		if (i % 4 == 0)						// if remainder for i / 4 is zero then the if statement executes and adds 1 to the total sum
		{
			sum += i;
		}
	}
	
	// here, we return the calcualted sum:
	return sum;
}
int Q1_while(){
	int sum = 0, i = 30;					//initialize i to 30 so the counter for the loop begins at 30



	// calculate your sum below..this has to use while loop
	
	
	while (i <= 1000) {
		i++;
		if (i % 4 == 0){
			sum += i;
		}
	}

	// here, we return the calcualted sum:
	return sum;
}
int Q1_do(){
	int sum = 0, i = 30;
	
	// calculate your sum below..this has to use do-while loop
	
	do {								//increment i by 1 for each iteration of the loop
	i++;
		if (i % 4 == 0){
		sum += i;
		}
	} while (i <= 1000);

	
	// here, we return the calcualted sum:
	return sum;
}
//===============================================================================================
int Q2(int Q2_input){
	
	// this is the flag that is holding whether the input number is 5-digit or not
	  int IsFiveDigit = 0, count = 0;

	  // Do your coding below to check

	  while (Q2_input != 0) {
	    Q2_input = Q2_input / 10;
	    count++;					// with each loop, the input is divided by 10. With each iteration, 1 is added to the count of total digits in the input. The loop breaks if the input becomes zero then the while loop breaks.
	  }
	  if (count == 5) {
	    IsFiveDigit = 1;
	  } else {
	    IsFiveDigit = 0;
	  }

	//finally, we must return IsFiveDigit, which must be 1 is the number is five digits and 0 otherwise
	return IsFiveDigit;
}
//===============================================================================================
int Q3(float Q3_input){
	
	/* Question 3: 
	Write a program that takes a student's Q3_input as an input, which is a floating point value,
	and returns:
	4 if the Q3_input is in the range 90-100,
	3 if it is in the range 80-89, 
	2 if it is in the range 70-79,
	1 if it is in the range 60-69 and
	0 if the Q3_input is between 0 and 59.
	If the Q3_input is not in the range 0-100, the program shouldreturn -1
*/	
	// this is the varaible that holds the out value to return
	float GPA;
	
	// Do your coding below to calculate the GPA variable value

	  if ((Q3_input >= 90) && (Q3_input <= 100)) {						//if statement checks if the input is greater than the minimum threshold AND less than the maximum threshold.
	    GPA = 4;
	  }

	  else if ((Q3_input >= 80) && (Q3_input <= 89)) {
	    GPA = 3;
	  }

	  else if ((Q3_input >= 70) && (Q3_input <= 79)) {
	    GPA = 2;
	  }

	  else if ((Q3_input >= 60) && (Q3_input <= 69)) {
	    GPA = 1;
	  }

	  else if ((Q3_input >= 0) && (Q3_input <= 59)) {
	    GPA = 0;
	  }

	  else if (Q3_input < 0 || Q3_input > 100) {					//if the input is not between the minimum threshold OR maximum then it will return -1.
	    return -1;
	  }
	
	
	// finally, we return the GPA
	return GPA;	
}
//===============================================================================================
double Q4(int Q4_input){
	
	// this is the varaible that holds the pi value to return
	double pi=4, denom, n = 1;									// let pi equal to 4 and declare variable "denominator" for the denominator of the fractions in the pi equation. also initialize n to be a counter variable.
	int i = 2;


	// Do your coding below to calculate the pi value

	if (Q4_input == 1)
	{
		pi = 4;
	}
	else {
		for(i = 2; i <= Q4_input; i++){

			denom = (2*n) + 1;								//the denominator is meant to be odd. (2n+1) yields only odd numbers for a integer input n.
			n++;

			if (i % 2 == 0) {								// if the for loop is on an even iteration, the value of pi gets subtracted from 4/denom
				pi = pi - (4/denom);
			}
			else {											// if the for loop is on an odd iteration, the value of pi gets added from 4/denom
				pi = pi + (4/denom);
			}
		}
	}

	// finally, we return the pi value
	return pi;	
}
//===============================================================================================
int Q5(){
	
	// this is the varaible that holds and the total number of triples to return at the end of the function
	int totNumTribles=0;
	
	
	/* Do your coding below
		Use a triple-nested for loop that simply tries all possibilities
		and update the total number of triples if needed
	*/
	
	int side1, side2, hyp;

	for (side1 = 1; side1 <= 400; side1++) {

		for (side2 = 1; side2 <= 400; side2++) {

			if (side1 <= side2) {										//ensures side1 is less than side2

				for (hyp = 1; hyp <= 400; hyp++) {

					if (side1*side1 + side2*side2 == hyp*hyp) {			//if the sum of the square of the sides equal to the square of hypotenuse, then the 3 numbers are pythagorean triples.

						totNumTribles++;
					}
				}
			}
		}
	}
	//finally you should return the total number of tribles.
	return totNumTribles;
}
//===============================================================================================
int Q6(int Q6_input, int perfect[Q6_input]){
	
	
	
		//counts is teh variable that should hold the total number of found perfect numbers
		//you should update it within your code and return it at the end
	    int counts=0, sum = 0, i = 0, x = 0;

		/*
		*
		*perfect is an array that you need to add into it any perfect number you find
		*which means at the end of this function, the perfect[] array should hold all the found perfect numbers in the range
		*you do not need to return perfect because as stated in lectures arrays are already passed by reference. so, modifying them will 
		*autmoatically reflect in the main calling function.
		*/
	    
	    for (i = 1; i <= Q6_input; i++){			//for loop iterates from 1 to the entered input
	    	for (x=(i-1); x>0; x--){				//for loop iterates down from input to 1

	    		if (i % x == 0) {					// if the remainder is 0, then add x to the sum
	    			sum += x;
	    		}
	    	}

	    		if (sum == i){
	    			sum = 0;
	    			perfect[counts] = i;			//adds the perfect number, i, to the array called perfect at index, counts.
	    			counts++;
	    		}
	    		else {
	    			sum = 0;
	    		}
	    	}


	   return counts;

	
}
//===============================================================================================
int Q7a(int Q7_input){
	
	//this is the variable that holds the reversed int.
	int reversedInt=0;

	

	
	// Do your coding logic here
	//Hint: Use the division and remainder operators to separate the number into its individual digits.
	//in this part you can assume the knowledge of the number of digits: seven-digit positive integer
	
	int rem = 0, i;

	
	for (i = 0; i < 7; i++){					//for loop iterates until the counter is greater than or equal to 7. This means the loop breaks if the input is seven digits.

		rem = Q7_input % 10;					//finds the first digit of the input
		reversedInt = reversedInt*10;
		Q7_input = Q7_input/10;					//divides input by 10 to find the next number of the reverse
		reversedInt += rem;						//adds the remainder, which is the first digit of the input, to the reversedInt variable which will be returned later to yield the reverse of the input
	}

		return reversedInt;
	
}
int Q7b(int Q7b_input){
	
	//this is the variable that holds the reversed int.
	int reversedInt=0;
	
	

	// Do your coding logic here
	//Hint: Use the division and remainder operators to separate the number into its individual digits.
	//this part should be generalized for any number of allowed digits
	
	int rem = 0;
	
	while(Q7b_input > 0){						//while loop iterates as long as the input is greater than 0.
		rem = Q7b_input % 10;
		reversedInt = reversedInt*10;
		Q7b_input = Q7b_input/10;
		reversedInt += rem;						//same process used from 7a to find the reversed version of the inputed integer
	}
	

	return reversedInt;

	
	
	
}
