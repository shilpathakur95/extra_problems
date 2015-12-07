//Given a unsigned number as a string input (it can be of length, max 10000 chars) write a function to find whether the number is divisible by 11 or not.
//Shilpa Thakur, MGIT
//MissionRnD
#include<stdio.h>
int divisibility(char number[10000], int size);  //Declaring function
main()
{
	char number[10000],character;               //Declaring variables
	int iterator = 0,flag;
	printf("Enter the number \n");
	do
	{
		character = getchar();                 //Reading the number in the form of a string
		number[iterator] = character;
		iterator++;
	} while (character != '\n');
	number[iterator - 1] = '\0';
	flag=divisibility(number,iterator-1);     //Function call for divisibility() function
	if (flag == 1)
		printf("%s is divisble by 11", number); //Printing the result
	else
		printf("%s is not divisible by 11", number);
}
int divisibility(char number[10000], int size) //Function definition of divisibility() function: Takes the number and applies divisibilty rule of 11 to it to determine if it is divisible by 11
{
	int iterator,sum=0;
	for (iterator = 0; iterator < size; iterator++)
	{
		if (iterator % 2 == 0)
			sum += number[iterator] - 48;    //Adding alternate digits and subtracting the remaining digits. Ex:- 2345=2-3+4-5
		else
			sum = sum - (number[iterator]-48);
	}
	if (sum % 11 == 0) //If the value of 'sum' is divisible by 11 then the 'number' is divisible by 11
		return 1;
	else
		return 0;
}