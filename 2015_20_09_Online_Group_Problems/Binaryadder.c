//Given two strings which are unsigned integer numbers (in string format) write an adder to add the numbers. Lenghts of both can be different.
//Shilpa Thakur, MGIT
//MissionRnD
#include<stdio.h>
int adder(char number1[100], char number2[100], int size1, int size2); //Declaring functions
void reverse(int array[100], int array1[100], int size);
int power(int base, int num);
main()
{
	char number1[100], number2[100], character;                        //Declaring variables
	int iterator1 = 0, iterator2 = 0, sum;
	printf("Enter the first number \n");
	do                                                               //Reading first number
	{
		character = getchar();
		number1[iterator1] = character;
		iterator1++;
	} while (character != '\n');
	number1[iterator1 - 1] = '\0';
	printf("Enter the second number \n");
	do                                                               //Reading second number
	{
		character = getchar();
		number2[iterator2] = character;
		iterator2++;
	} while (character != '\n');
	number2[iterator2 - 1] = '\0';
	sum = adder(number1, number2, iterator1 - 1, iterator2 - 1);            //Function call for adder() function
	printf("The sum is %d", sum);                                   //Printing the sum


}
int adder(char number1[100], char number2[100], int size1, int size2)//Function definition of adder() function: Takes two numbers and returns their sum
{
	int iterator1, iterator2 = 0, size, result[100], carry = 0, answer = 0, array[100]; //Declaring variables
	if (size1 <= size2)
		size = size1;                                                       //Assigning 'size' the least size of the two numbers
	else
		size = size2;
	for (iterator1 = size - 1; iterator1 >= 0; iterator1--)
	{
		if (size1>size2)                                                   //Checking if first number is bigger
			answer = (number1[iterator1 + (size1 - size2)] - 48) + (number2[iterator1] - 48) + carry;
		else if (size2>size1)                                              //Checking if second number is bigger
			answer = (number1[iterator1] - 48) + (number2[iterator1 + (size2 - size1)] - 48) + carry;
		else                                                               //Checkinng if both numbers are equal
			answer = (number1[iterator1] - 48) + (number2[iterator1] - 48) + carry;
		if (answer >= 10)
		{
			result[iterator2] = answer % 10;
			carry = answer / 10;                                         //Generating carry if the 'answer' is a two digit number
		}
		else
		{
			result[iterator2] = answer;
			carry = 0;
		}
		iterator2++;
	}
	if (size1 != size2)                                                 //Checking if the numbers are of unequal lengths 
	{
		if (size1 > size2)                                              //Checking if first number is bigger
		{
			for (iterator1 = size1 - size2 - 1; iterator1 >= 0; iterator1--)
			{
				answer = number1[iterator1] - 48 + carry;                //Storing the remaining digits of first number in 'result'
				if (answer >= 10)
				{
					result[iterator2] = answer % 10;
					carry = answer / 10;
				}
				else
				{
					result[iterator2] = answer;
					carry = 0;
				}
				iterator2++;
			}
			result[iterator2] = carry;
		}
		else                                                             //Checking if second number is bigger
		{
			for (iterator1 = size2 - size - 1; iterator1 >= 0; iterator1--)
			{
				answer = number2[iterator1] - 48 + carry;                //Storing the remaining digits of second number in 'result'
				if (answer >= 10)
				{
					result[iterator2] = answer % 10;
					carry = answer / 10;
				}
				else
				{
					result[iterator2] = answer;
					carry = 0;
				}
				iterator2++;
			}
			result[iterator2] = carry;
		}
	}
	else
		result[iterator2] = carry;                                //If the numbers are of equal length storing the carry in 'result'
	size = iterator2 + 1;
	reverse(result, array, size);                             //Since digits are stored in reverse order in 'result' we call reverse() function
	answer = 0;
	for (iterator1 = 0; iterator1 < size; iterator1++)
		answer = answer + array[iterator1] * power(10, size - iterator1 - 1); //Generating final answer by summing the digits of 'array'
	return answer;
}
void reverse(int array[100], int array1[100], int size) //Function definition of reverse() function: Reverses the digits in a given array and stores it in 'array1'
{
	int iterator, iterator2 = 0;
	for (iterator = size - 1; iterator >= 0; iterator--)
	{
		array1[iterator2] = array[iterator];          //Storing the digits in 'array1'
		iterator2++;
	}
}
int power(int base, int num) //Function definition of power() function: Takes the base and power value and generates 'base' to the power of 'num'
{
	int iterator, power = 1;
	for (iterator = 0; iterator < num; iterator++)
	{
		power = power*base;
	}
	return power;
}