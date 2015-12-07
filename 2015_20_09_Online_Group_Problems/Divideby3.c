//An unsigned number Q is formed by taking input P which is an unsigned integer in string format, K: number of times P repeated to form Q. write a function to find whether the number Q is divisible by 11 or not .Ex: Q : 123123123 P : 123 K : 3
//Shilpa Thakur, MGIT
//MissionRnD
#include<stdio.h>
int logic(char string[100], int times, int size);  //Declaring function
main()
{
	char P[100], character;                       //Declaring variables
	int iterator = 0, K, flag;
	printf("Enter the string \n");
	do
	{                                            //Reading the string 'P'
		character = getchar();
		P[iterator] = character;
		iterator++;
	} while (character != '\n');
	P[iterator - 1] = '\0';
	printf("Enter K value \n");
	scanf_s("%d", &K);                          //Scanning the number of times 'P' has to be multiplied
	flag = logic(P, K, iterator - 1);
	for (iterator = 0; iterator<K; iterator++)
		printf("%s", P);                       //Printing the string formed by taking 'P' string 'K' times
	if (flag == 1)
		printf(" is divisible by 3");         //Printing the result
	else
		printf(" is not divisible by 3");
}
int logic(char string[100], int times, int size)  //Function definition of logic() function: Takes the string, size of the string and the number of times it should be regenerated
{
	int iterator, iterator2, iterator3 = 0, sum = 0;  //Declaring variables
	for (iterator = 0; iterator < times; iterator++) //Iterating the loop for 'times' number of times
	{
		for (iterator2 = 0; iterator2 < size; iterator2++) //Iterating the loop for the 'size' of the 'string'
				sum += string[iterator2] - 48;           //Taking the sum of all digits Eg:- 2222 = 2+2+2+2=6
	}
	if (sum % 3 == 0)                      //If the 'sum' is divisible by 11 then the 'string' is divisible by 11
		return 1;
	else
		return 0;
}