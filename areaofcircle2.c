#include <stdio.h>
#include <math.h>
// for testing only - do not change
void getTestInput(int argc, char* argv[], float* a, int* b)
{
  if (argc == 3) {
    sscanf(argv[1], "%f", a);
    sscanf(argv[2], "%d", b);
  }
}



// add your areaOfCircle function here - it must NOT printf, instead it must
// return the result to be printed in main

float areaOfCircle(float radius)
{
 float area;
 area = radius*radius*M_PI;
 return area;

}

int start;
int reps;

void userInput()
{
	char input[256];

	printf("Input lower: \n");
	while(1)
	{
		fgets(input, 256, stdin);
		if (sscanf(input, "%d", &start) == 1 && (start > 0)) break;
		printf("Not a valid number - try again!\n");
	}
	printf("Input upper: \n");
	while(1)
	{
		fgets(input, 256, stdin);
		if (sscanf(input, "%d", &reps) == 1 && (reps > start)) break;
		printf("Not a valid number - try again!\n");
	}
	reps = reps - start +1;
	for(int i = 0; i < reps; i++)
	{
		printf("Area of circle for %d is %f\n", start+i, areaOfCircle(start + i));
	}
}


int main(int argc, char* argv[]) 
{
  // the two variables which control the number of times areaOfCircle is called
  // in this case 5.2, 6.2, 7.2
  float start = 5.2;
  int reps = 3;
  
  // for testing only - do not change
  getTestInput(argc, argv, &start, &reps);

  //printf("calculating area of circle starting at %f, and ending at %f\n", start, start+reps-1);
  
  // add your code below to call areaOfCircle function with values between
  // start and end
 // for(float i = start; i < start+reps-1; i++)
//{
 //printf("Area of circle = %f\n", areaOfCircle(i));
//}

userInput();
}
