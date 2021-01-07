#include<stdio.h>

int main()
{
  int a = 545;

  // print value and size of an int variable
  printf("int a value: %d and size: %lu bytes\n", a, sizeof(a));
 char c = 'b';
  // print value and size of a char variable
 printf("int c value: %c and size %lu bytes\n", c, sizeof(c));
 float d = 12;
 // print value and size of a float variable
 printf("int d value: %f and size %lu bytes\n", d, sizeof(d));
 double y = 22.834;
 // print value and size of a double variable
 printf("int y value: %f and size %lu bytes\n", y, sizeof(y));
}


