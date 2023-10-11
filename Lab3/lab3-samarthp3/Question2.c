#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"



student **create_class_list(char *filename, int *sizePtr){
	
	student **class_list;


	/*write your implementation here*/

	int i;

	FILE *file;
	file = fopen(filename, "r"); //initializes file such that it can be read

	fscanf(file, "%d", sizePtr);

	class_list = (student **)calloc(*sizePtr, sizeof(student *));															//allocate memory

	for (i = 0; i < *sizePtr; i++){																							//iterate through each line on the file
		class_list[i] = (student *)calloc(1, sizeof(student));																//initialize size of pointer variables and setting them to zero through calloc
		fscanf(file, "%d %s %s", &class_list[i]-> student_id, class_list[i]->first_name, class_list[i]-> last_name); 		//changing the value for each variable in the structure
	}

	fclose(file);

	/* finally return the created class list*/
	return class_list;
}

int find(int idNo, student **list, int size)
{
	/*write your implementation here and update the return accordingly*/

	int i;

	for(i = 0; i<size; i++){							//iterate through each student
		if ((list[i]-> student_id) == idNo)				//if studentid matches then return the position of student
			return i;
	}
	return -1;
}

void input_grades(char *filename, student **list, int size)
{

	/*write your implementation here*/
	int i;
	FILE *grades = fopen(filename, "r");													//initialize file for reading

	int studentID, pos;

	for (i=0; i<size; i++){																	//iterate through each student
		fscanf(grades, "%d", &studentID);													//read student id from the grades file

		pos = find(studentID, list, size);													//storing the index of the student obtained from their id

		fscanf(grades, "%d %d", &list[pos]->project1_grade, &list[pos]->project2_grade);	//assign students their project 1 and project 2 grades
	}

	fclose(grades);

}

void compute_final_course_grades(student **list, int size)
{
	
	/*write your implementation here*/
	int i;

	for (i=0; i<size; i++)
	{
		list[i]->final_grade = (list[i]->project1_grade + list[i]->project2_grade)/2.0;		//find student average and stores it in their array
	}
}

void output_final_course_grades(char *filename, student **list, int size)
{
	
	/*write your implementation here*/

	FILE *output = fopen(filename, "w");												//initialize file for writing
	int i;

	fprintf(output, "%d \n", size);														//get number of students

	for (i=0; i<size; i++){																//print student id and grade for each student
		fprintf(output, "%d %lf \n", list[i]->student_id, list[i]->final_grade);
	}
	fclose(output);																		//close file
}


void withdraw(int idNo, student **list, int* sizePtr)
{
	/*write your implementation here*/
	int i;
	int stdFound = 0;

	for (i = 0; i < *sizePtr; i++){									//iterates through students
		if (list[i] -> student_id == idNo){							//if student matches with idNo then
			stdFound = 1;											//indicates student was found
			free(list[i]);											//frees from memory
		}
	}
	if (stdFound == 0){
		printf("Student with ID %d is not within list \n", idNo);		//prints statement if student was not found with corresponding id
	}
}

void destroy_list(student **list, int *sizePtr)
{
	/*write your implementation here*/
	free(list);														//frees all memory from list
	*sizePtr = 0;													//resets student count to zero
}

int studentProgram(char *grades_test, char *students_test, char *output_test ){
    int size;
    student **list = create_class_list(students_test,&size); // create structure


    find(6547, list, size); // finds student with iD of 6547

    input_grades(grades_test, list, size);

    compute_final_course_grades(list, size);
    int sizeofList = size;

    output_final_course_grades(output_test, list, size); //returns the final course grade in the output file

    withdraw(1001, list, &size);//student found in list
    size--;
    withdraw(7281, list, &size); //student found in list
    size--;
    withdraw(6942, list, &size); // student not found in list
    size--;

    destroy_list(list,&size);

return sizeofList;
}
