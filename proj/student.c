//
// student.c
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"
#include "encrypt.h"


const char* STUFILE = "studentdata.txt";

// keeps track of the number of students in the students array
int numStudents = 0;

// holds the student pointer array
Student* students[100] = {0};


void createStudent(char* fname, char* lname, int age, int id)
{
  // createStudent dynamically creates a Student on the heap and adds that
  // student to the student array
  //  - the firstName and lastName strings should be dynamically created
  //    based on the size of the fname and lname args





 Student* st = (Student*)malloc(sizeof(Student));
 st->firstName = (char*)malloc(strlen(fname)+1);
 st->lastName = (char*)malloc(strlen(fname)+1);
 strcpy(st->firstName, fname);
 strcpy(st->lastName, lname);
 st->age = age;
 st->id = id;
 students[numStudents] = st;
 numStudents++;
}


void deleteStudent(Student* st)
{
  // free the memory associated with a student including the strings
free(st -> firstName);
free(st -> lastName);
free(st);
}


void deleteStudents()
{
  // iterate over the students array deleting every student and setting te pointer
  // values to 0 and adjusting the numStudents to 0

for(int i = 0; i < numStudents; i ++)
{
	deleteStudent(students[i]);
	students[i] = 0;
}
numStudents = 0;


}


void saveStudents(int key)
{
  // save all students in the student array to a file 'studentdata.txt' overwriting
  // any existing file
  //   - the format of the file is one line per student as follows fname lname age id:
  //       tom thumb 15 1234 
  //       james dean 21 2345 
  //       katy jones 18 4532
 
 FILE* fp;
 fp = fopen(STUFILE, "w");
 if(fp){
char buff[256];
 for(int i = 0; i < numStudents; i++)
{
	Student* st = students[i];
	sprintf(buff, "%s %s %d %ld", st->firstName, st->lastName, st->age, st->id);
	if(key != 0){
		caesarEncrypt(buff, key);
}
	printf("Saving %s\n", buff);
	fprintf(fp, "%s\n", buff);
}
	printf("Saved %d students", numStudents);
 fclose(fp);
}
}


void loadStudents(int key)
{
  // load the students from the data file overwriting all exisiting students in memory
 if(numStudents > 0){
	deleteStudents();
}
 FILE* fp;
 fp = fopen(STUFILE, "r");
 while(1){
 if(fp) {
	char b1[256];
	char b2[256];
	char b3[256];
	char b4[256];
	int match = fscanf(fp, "%s %s %s %s", b1, b2, b3, b4);
	if(match == 4){
		if(key != 0){
			caesarDecrypt(b1, key);
			caesarDecrypt(b2, key);
			caesarDecrypt(b3, key);
			caesarDecrypt(b4, key);
		}
		int age;
		long id;
		sscanf(b3, "%d", &age);
		sscanf(b4, "%ld", &id);
		createStudent(b1, b2, age, id);
	}
	else {
	break;
	}
}
}
printf("Loaded %d students", numStudents);
fclose(fp);
}


void printStudent(Student* student)
{
  printf("  Student: %s %s\n", student->firstName, student->lastName);
  printf("    age: %d\n", student->age);
  printf("    id: %ld\n", student->id); 
}


void printStudents()
{
  for (int i = 0; i < numStudents; i++) {
    printf("\n----- student %d ------\n", i);
    printStudent(students[i]);
  }
}



