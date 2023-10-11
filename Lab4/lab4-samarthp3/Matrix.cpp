
#include "Matrix.h"
#include <iostream>
#include <stdexcept>
#include <stdlib.h>
using namespace std;

Matrix::Matrix(){
 rowsNum=3;
 colsNum=3;
 matrixData=NULL;
 matrixData = (int**)malloc(rowsNum*sizeof(int*));

    // Allocate rows for fake "2D array":
    for (int i = 0 ; i < rowsNum ; ++i )
    {
       matrixData[i] = (int*) malloc(colsNum*sizeof(int));
    }

    for (int i = 0 ; i < rowsNum ; ++i )
    	for (int j = 0 ; j < colsNum ; ++j )
    		matrixData[i][j]=0;
}

Matrix::Matrix( int row, int col ){

	int i, j;

	if(row <= 0) {
		rowsNum = 3;			//defaults row count to 3 if input is 0, otherwise sets row to user input
	}
	else {
		rowsNum = row;
	}

	if (col <= 0) {				//defaults column count to 3 if input is 0, otherwise sets columns to user input
		colsNum = 3;
	}
	else {
		colsNum = col;
	}

	matrixData = (int **)malloc(rowsNum*sizeof(int*)); 			//allocate memory to rows

	for (i=0; i<rowsNum;++i){
		matrixData[i]=(int*) malloc(colsNum*sizeof(int));		//allocate memory to columns
	}

	for (i=0;i<rowsNum;++i){
		for (j=0;j<colsNum;++j){
		matrixData[i][j]=0;										//sets all elements to 0
		}
	}
}


Matrix::Matrix(int row, int col, int** table){
	
	int i,j;

	this->rowsNum=row;											//access row from structure
	this->colsNum=col;											//access column from structure


	matrixData=(int **)malloc(rowsNum*sizeof(int*));			//allocate memory for row

	for (i=0;i<rowsNum;++i){
		matrixData[i]=(int*) malloc(colsNum*sizeof(int));		//allocate memory for column
	}


	for (i=0;i<rowsNum;++i){
		for (j=0;j<colsNum;++j){
			matrixData[i][j]=table[i][j];						//sets each element in each position to be the same as the one in table
		}
	}
}

int Matrix::getElement(int i, int j){

	if( i<0 || i>=rowsNum || j<0 || j>=colsNum){
		throw out_of_range("Invalid indexes.");					//if i or j are less than 0, or they're greater than the number of rows/columns, then output "Invalid indexes."
		return -1;
	}

	return matrixData[i][j];									//otherwise, return the element at i j
}

bool Matrix::setElement(int x, int i, int j){

	if((i>=0 && i<rowsNum)&&(j>=0 && j<colsNum)) {
		matrixData[i][j]=x;										//assign the value of x to the element on the matrix located at i j if the input i and j values are valid indexes
		 return true;
	 }
	return false;
}


Matrix Matrix::copy(){

	Matrix copy=Matrix(this->rowsNum,this->colsNum,this->matrixData);		//copy the matrix and returns a deep copy
    return copy;
}


void Matrix::addTo( Matrix m ){

	int i,j;

	if((this->rowsNum != m.rowsNum) || (this->colsNum != m.colsNum))
	{
		throw invalid_argument("Invalid operation");						//if the i j values of the input matrix do not match that of the current matrix, then returns "Invalid operation"
	}

	for(i=0;i<(this->rowsNum);i++){

		for(j=0;j<(this->colsNum);j++){

			 this->matrixData[i][j] += m.matrixData[i][j];					//adds the ij'th element of matrix1 to matrix2 and returns the added matrix
		}
	}
}


Matrix Matrix::subMatrix(int i, int j){

	int r, c;

	if((i>=(this->rowsNum)) || (i<0) || (j>=(this->colsNum)) || (j<0))
	{
		throw out_of_range("Submatrix not defined");						//return "Submatrix not defined" if the ij values are invalid
	}

	Matrix subM = Matrix (i+1, j+1);

	for (r=0;r<=i;r++){
		for (c=0;c<=j;c++){
			subM.matrixData[r][c] = (this->matrixData[r][c]);			//returns a submatrix of the main matrix by getting the ij values from the main matrix and assigning it to the subM matrix
		}
	}
	return subM;
}


int Matrix::getsizeofrows(){

	return (this->rowsNum);									//returns the amount of rows
}


int Matrix::getsizeofcols(){

    return (this->colsNum);									//returns the amount of columns
}


bool Matrix::isUpperTr(){

	int i,j;

	for(i=0;i<rowsNum;i++){
		for(j=0;j<i;j++){
			if((this->matrixData[i][j]) != 0)				//if the jth element is not equal to zero for values that have a j index less than i, then it cannot be upper triangular
			{
				return false;
			}
		}
	}
	return true;											//returns true if its upper triangular
}

string Matrix::toString(){

	int i,j;

	string str = "";										//initialize empty string

	for(i=0;i<rowsNum;i++){
		for(j=0;j<colsNum;j++)
		{
			str += to_string(matrixData[i][j]) + " ";		//takes the ij element of the matrix and adds it to the string with a blank
		}
		str += "\n";
	}

	return str;
}
