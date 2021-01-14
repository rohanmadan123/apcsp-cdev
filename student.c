#include <stdio.h>



// student structure
//struct Student...

struct Student
{
	char firstName[256];
	char lastName[256];
	int age;
	int id;
};

void printStudent(struct Student* student)
{
	printf("-------student-------\n");
	printf("Student Full Name: %s %s\n", student->firstName, student->lastName);
	printf("Age: %d\n", student->age);
	printf("ID: %d\n", student->id);
}


void printAllStudents(struct Student students[], int num)
{
  // call printStudent for each student in students
  for(int i = 0; i < num; i++){
	printStudent(&students[i]);
}
}

int main()
{


  struct Student student[256];
  // an array of students
  //xxx students;
  char input[256];
  int numStudents = 0;
  while (1)
  {
    char c;
    printf("\nEnter a to add, p to print, q to quit:");
    fgets(input, 256, stdin);
    if (sscanf(input, "%c", &c) != 1) continue;
    if (c == 'q') 
    {
      break;
    }
    else if (c == 'p')
    {
      // print all students
      printAllStudents(student, numStudents);
      continue;
    }
    else if (c == 'a')
    {
      // enter a new student
	printf("Enter a new student\n");
	printf("First name: \n");
	fgets(input, 256, stdin);
	sscanf(input, "%s", &student[numStudents].firstName);

	printf("Last Name: \n");
	fgets(input, 256, stdin);
	sscanf(input, "%s", &student[numStudents].lastName);

	printf("Age: \n");
	fgets(input, 256, stdin);
	sscanf(input, "%d", &student[numStudents].age);

	printf("ID: \n");
	fgets(input, 256, stdin);
	sscanf(input, "%d", &student[numStudents].id);

      numStudents++;
    }
  }
  
  printf("\nGoodbye!\n");
}
