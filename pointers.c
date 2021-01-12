#include <stdio.h>

int main()
{
  
  int a;
  int* ptrtoa;

  ptrtoa = &a;

  a = 5;
  printf("The value of a is %d\n", a);

  *ptrtoa = 6;
  printf("The value of a is %d\n", a);

  printf("The value of ptrtoa is %p\n", (void*)ptrtoa);
  printf("It stores the value %d\n", *ptrtoa);
  printf("The address of a is %p\n", (void*)&a);

 float d;
 float e;

 float* ptrtod;
 float* ptrtoe;

 ptrtod = &d;
 ptrtoe = &e;

 *ptrtod = 6.136136;
 *ptrtoe = 1.371371;

 printf("The value of float d is %d and the address is %p\n", d, (void*)&d);

 printf("The value of float e is %d and the address is %p\n", e, (void*)&e);

 float x;
 x = *ptrtoe;
 *ptrtoe = *ptrtod;
 *ptrtod = x;
 
 printf("New value of float e is %f\n", *ptrtoe);
 printf("New value of float d is %f\n", *ptrtod);
}


