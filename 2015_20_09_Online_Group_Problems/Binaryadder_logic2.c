//Given two strings which are unsigned integer numbers(in string format) write an adder to add the numbers.Lenghts of both can be different.
//Shilpa Thakur,MGIT
//MissionRnD
#include<stdio.h>
int power(int, int);                            //Declaring functions
int fulladder(int, int);
int converter(char [], int );
main()
{
	char number1[100], number2[100], character;                     //Declaring variables
	int iterator1 = 0, iterator2 = 0, sum,num1,num2;
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
	num1=converter(number1, iterator1 - 1);            //Function call for converter() function
	num2=converter(number2, iterator2 - 1);            //Function call for converter() function
	sum = fulladder(num1, num2);                         //Function call for fulladder() function
	printf("The sum is %d", sum);
}
int converter(char number[100], int size) //Function definition for converter() function: Takes a number in string format and returns the number in int format
{
	int iterator,num[100],digit=0;       //Declaring variables
	for (iterator = 0; iterator < size; iterator++)
		num[iterator] = number[iterator] - 48;  //Storing the digits of string format in a int array
	for (iterator = 0; iterator < size; iterator++)
		digit = digit+num[iterator] * power(10, size - iterator - 1); //Coverting it into int format
	return digit;
}
int fulladder(int num1, int num2) //Function definition for fulladder() function: Takes two numbers converts them into binary and adds them. Returns their sum in decimal form
{
	int array1[32], array2[32], sum[32], carry = 0,  iterator1 = 0,iterator2, count = 0, n = 0,answer=0; //Declaring variables
	while (num1 != 0)
	{                                                //Converting first number into binary. Binary bits are stored in reverse order
		if (num1 % 2 == 0)
			array1[iterator1] = 0;
		else
			array1[iterator1] = 1;
		iterator1++;
		count++;
		num1 = num1 / 2;
	}
	for (iterator1 = count; iterator1 < 32; iterator1++)
	array1[iterator1] = 0;                           //Padding the remaining bits with zeros.
	count = 0;
	iterator2 = 0;
	while (num2 != 0)
	{                                                 //Converting second number into binary. Binary bits are stored in reverse order
		if (num2% 2 == 0)
			array2[iterator2] = 0;
		else
			array2[iterator2] = 1;
		iterator2++;
		count++;
		num2 = num2 / 2;
	}
	for (iterator2 = count; iterator2 <32; iterator2++)
	array2[iterator2] = 0;                           //Padding the remaining bits with zeros.
	for (iterator2 = 0; iterator2 < 32; iterator2++)
	{
		sum[iterator2] = (array1[iterator2] + array2[iterator2] + carry) % 2; //Calculating the sum of each place in 'array1' and 'array2' from left to right as the binary bits were stored in reverse order.
		carry = (array1[iterator2] + array2[iterator2] + carry) / 2;  //Calculating the carry at each place 
	}
	for (iterator1 = 0; iterator1 <=32; iterator1++)
	{
		answer = sum[iterator1] * power(2, n) + answer;  //Coverting the 'sum' to decimal form
		n++;
	}
	return answer;   
}
int power(int base, int num) //Function definition of power() function: Takes the base and power value and returns base to the power of power value
{
	int iterator, power=1;
	for (iterator = 1; iterator <= num; iterator++)
		power = power*base;
	return power;
}

