//Covert given binary number to octal number
//Shilpa Thakur, MGIT
//MissionRnD
#include<stdio.h>
int octal(char number[100], int octalnum[100], int size); //Declaring functions
int power(int base, int num);
main()
{
	int iterator=0,octalnum[100],size; //Declaring variables
	char number[100], character;
	printf("Enter binary number \n");
	do
	{
		character = getchar();          //Reading binary string
		number[iterator] = character;
		iterator++;
	}while (character != '\n');
	number[iterator - 1] = '\0';
	size=octal(number,octalnum, iterator-1); //Function call for octal() function
	for (iterator = size; iterator >=0; iterator--)
		printf("The octal representation is %d", octalnum[iterator]); //Printing result
}
int octal(char number[100], int octalnum[100],int size)//Function definition for octal() function:Takes binary number and converts it into octal and stores is in 'octalnum' array. Returns the size of 'octalnum' array
{
	int iterator, iterator2 = 0, n=0,sum=0;  //Declaring variables
	for (iterator = size - 1; iterator >= 0; iterator--)
	{
		if (n < 3)                 //Grouping 3 bits starting from least significant bit and converting them to decimal
		{
			sum += (number[iterator]-48) * power(2, n);
		}
		else if (n==3)            
		{
			n = 0;
			octalnum[iterator2] = sum;  //Storing the decimal obtained from grouping three bits
			sum = 0;
			sum += (number[iterator] - 48) * power(2, n); //Calculating the 'sum' for current iteration
			iterator2++;
		}
		n++;
	}
	if (n != 0)                //Storing the last group in 'octalnum'
	{
		octalnum[iterator2] = sum;
		iterator2++;
	}
	return iterator2 - 1;
}
int power(int base, int num) //Function definition of power() function: Takes the base and power value and returns base to the power of power value
{
	int iterator;
	long int power = 1;
	for (iterator = 1; iterator <= num; iterator++)
		power = power*base;
	return power;
}