//Adding two numbers of same length from left to right where the sum of MSBs of the two numbers is less than 9.
//Shilpa Thakur, MGIT
//MissionRnD
#include<stdio.h>
void adder(char number1[100], char number2[100], int size); //Declaring function
main()
{
	char number1[100], number2[100], character; //DEclaring variables
	int size1=0, size2=0;
	printf("Enter the numbers\n");
	do
	{                                      //Reading the numbers
		character = getchar();
		number1[size1] = character;
		size1++;
	} while (character != '\n');
	number1[size1 - 1] = '\0';
	do
	{
		character = getchar();
		number2[size2] = character;
		size2++;
	} while (character != '\n');
	number1[size2 - 1] = '\0';
	if (size1 != size2)                   //Checking if they are of the same size
		printf("They are not of same length");
	else
		adder(number1, number2, size1 - 1);  //Function call for adder() function
}
void adder(char number1[100], char number2[100], int size)//Function definition for adder() function: Takes two numbers and their length and adds them from left to right
{
	int iterator1=0, iterator2=0, pointer1, carry,temp; 
	int result[100];
	result[0] = number1[0] - 48 + number2[0] - 48; //Storing the sum of LSB bits
	for (iterator2 = 1; iterator2 < size; iterator2++)
	{
		result[iterator2] = number1[iterator2] - 48 + number2[iterator2]-48; //Adding and storing result from left to right
		if (result[iterator2]<9) //If the sum at 'iterator2' position is less than 9 then we bring 'iterator1' to 'iterator2'
			iterator1 = iterator2;
		 else if (result[iterator2]>9) //If the sum is greater than 9
		{
			temp = result[iterator2];
			result[iterator2] = temp % 10; //Storing the LSB of the two digit sum at 'iterator2' position
			carry = temp / 10; //Calculating carry at 'iterator2' position
			for (pointer1 = iterator2 - 1; pointer1 >= iterator1; pointer1--)
			{
				result[pointer1] += carry; //Adding carrry to the bits at LHS of 'iterator2' poisition till 'iterator1'
				temp = result[pointer1]; //If adding 'carry' generates a 'carry' in other bits then 
				result[pointer1] = temp % 10; //Storing the LSB of the addition of 'carry' to 'pointer1' position
				carry = temp / 10; //Calculating carry at 'pointer1' position
			}
			iterator1 = iterator2;
		}
	}
	printf("-------\n");
	for (iterator1 = 0; iterator1 < size; iterator1++)
	printf("%d", result[iterator1]);
	printf("\n-------");
}