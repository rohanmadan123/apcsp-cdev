#include <stdio.h>
#include <string.h>


int main ()
{
	char alph1[26];
	char alph3[26];

	for(int i = 0; i < 26; i++){
		alph1[i] = 97 + i;
	}

	alph1[26] = '\0';
	char alph2[] = "abcdefghijklmnopqrstuvwxyz";

	printf("Alphabet string 1: %s\n", alph1);
	printf("Alphabet string 2: %s\n", alph2);

	if(strcmp(alph1, alph2) == 0)
		printf("The strings are the same\n");
	else
		printf("The strings are different\n");

	for(int i = 0; i < 26; i++){
		alph1[i] = 65 + i;
}
	printf("Updated alphabet string 1: %s\n", alph1);


	if(strcmp(alph1, alph2) == 0)
		printf("The strings are the same\n");
	else
		printf("The strings are different\n");


	strcpy(alph3, alph1);
	strcat(alph3, alph2);

	printf("Alphabet string 3: %s\n", alph3);

	if(strcmp(alph1, alph3) == 0)
		printf("The strings are the same\n");
	else
		printf("The strings are different\n");
}
