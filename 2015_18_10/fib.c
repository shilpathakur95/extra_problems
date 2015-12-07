// Given a number represent it in base Fibonacci series. Using backtracking
//Shilpa Thakur,MGIT
//MissionRnD2015
#include<stdio.h>
void backtracking(); //Function declaration
main()
{
	int num, test, iterator;
	printf("Enter no. of tests\n");
	scanf_s("%d", &test); //Scanning the number of tests
	for (iterator = 0; iterator < test; iterator++)
	{
		printf("Enter number\n");
		scanf_s("%d", &num); //Scanning the number
		backtracking(num);
	}
}
void backtracking(int num) //Function definition of fib(): Takes the number and prints its fibonacci representation
{
	int iterator = 0, iterator2, it1, sum = 0,temp, array1[100];
	int x1 = 0, x2 = 1, x3 = 1;
	sum = num; //Storing the num in 'sum'
	for (iterator = 0; iterator < 100; iterator++)
		array1[iterator] = -1;
	iterator = 0;
	while (sum != 0)
	{
		if (array1[iterator] == -1) //If the fibonacci number is not calculated
		{
			array1[iterator] = x3; //Calculate and store that number in 'array1'
			sum -= array1[iterator]; iterator++; //Subracting the fibonacci series from 'sum'
			x3 = x1 + x2;
			x1 = x2;
			x2 = x3;
		}
		else
		{
			sum -= array1[iterator]; iterator++; //If the fibonacci number is already calculated we simply subtract it from 'sum'
		}
		if (sum < 0) //Checking if 'sum' is negative and backtracking
		{
			iterator2 = iterator - 1;
			while (array1[iterator2] > (sum*-1)||array1[iterator2]==0)
				iterator2--; //Finding the position where fibonacci element is less that the positive value of 'sum'
			for (it1 = iterator2; it1<=iterator-1; it1++)
				sum += array1[it1]; //Making 'sum' positive by adding back the numbers that made it negative
			array1[iterator2] = 0; //Since that particular number makes 'sum' negative we initialize it to 0
			iterator = iterator2; //Iterating again from that position	
		}
	}
	for (it1 = 0; it1 < iterator; it1++)
	{
		if (array1[it1] > 0) //Wherever the series is not zero initialize that position to 1
			array1[it1] = 1;
	}
	iterator2 = 0;
	while (iterator2 <= 1) //Performing the check twice to make it most optimal
	{
		for (it1 = iterator - 1; it1 >= 0; it1--)
		{
			if (it1 > 2 && array1[it1] == 1 && array1[it1 - 1] == 0 && array1[it1 - 2] == 0) //If there are two 0s to the right side of a 1 we can initialise those two places as 1
			{
				array1[it1] = 0;
				array1[it1 - 1] = 1; array1[it1 - 2] = 1;
			}
		}
		if (array1[1] == 1 && array1[0] == 0) //If there is a 1 at LSB-1 and 0 at LSB we swap them
		{
			array1[1] = 0; array1[0] = 1;
		}
		iterator2++;
	}
	for (it1 = iterator-1; it1 >= 0; it1--)
		printf("%d", array1[it1]); //Printing the result
	printf("\n");
}
