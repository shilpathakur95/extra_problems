// Given a number represent it in base Fibonacci series
//Shilpa Thakur,MGIT
//MissionRnD2015
#include<stdio.h>
void fib(); //Function declaration
main()
{
	int num,test,iterator;
	printf("Enter no. of tests\n");
	scanf_s("%d", &test); //Scanning the number of tests
	for (iterator = 0; iterator < test; iterator++)
	{
		printf("Enter number\n");
		scanf_s("%d", &num); //Scanning the number
		fib(num);
	}
}
void fib(int num) //Function definition of fib(): Takes the number and prints its fibonacci representation
{
	int iterator = 0, iterator2, it1, sum = 0, array1[100] = { 0 };
	int x1 = 0, x2 = 1, x3 = 1;
		while (sum < num)
		{
			sum += x3; iterator++; //Adding the fibonacci series such that the 'sum' is less than given number
			x3 = x1 + x2;
			x1 = x2;
			x2 = x3;
		}
		iterator--;
		array1[iterator] = 1; //Initialising the position where 'sum' is closest to 'num' as 1
		iterator2 = iterator; //Storing that index position in 'iterator2'
		sum = x1; //Storing the last fibonacci number encountered in 'sum'
		while (sum != num)
		{
			iterator--;
			if (sum < num)
			{
				x3 = x2 - x1; //If 'sum; is less than the given number then adding the fibonacci series to the left of index position
				x2 = x1;
				x1 = x3;
				sum += x3;
				array1[iterator] = 1; //Initialising all those index positions to 1
			}
			else
			{
				iterator++; //If sum is greater than the given number then we subtract the last added digit and initialize its position as 0 in 'array1'
				sum -= x3;
				array1[iterator] = 0;
			}
		}
		if (sum == num) //If we get the correct representation we find the optimal representation
		{
			iterator = 0;
			while (iterator<=1) //Performing the check twice to make it most optimal
			{
				for (it1 = iterator2; it1 >= 0; it1--)
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
			iterator++;
		}
			for (it1 = iterator2; it1 >= 0; it1--) //Printing the result
			{
				printf("%d", array1[it1]);
			}
			printf("\n");
		}
}