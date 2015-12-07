//Given an array of unsigned integers and window size identify the winner element index.Winner element : Largest sum in the array including its left and right and itself as suggested by the window size
//Shilpa Thakur,MGIT
//MissionRnD2015
#include<stdio.h>
void winner(int array[100], int n, int size); //Declaring function
main()
{
	int array[100], num,size,iterator;
	printf("Enter size of array \n"); //Reading the size of the array
	scanf_s("%d", &num);
	printf("Enter no.s \n");
	for (iterator = 0; iterator < num; iterator++)
		scanf_s("%d", &array[iterator]); //Reading the elements of the array
	printf("Enter window size \n");
	scanf_s("%d", &size); //Reading the window size
	winner(array,num,size); //Function call for winner()
}
void winner(int array[100],int n,int size) //Function definition for winner()
{
	int iterator,iterator2,array1[100],max,limit; //Declaring variables
	if (size % 2 == 0) //Finding the limit for even sized window
	{
		size = size / 2;
		limit = size - 1;
	}
	else //Finding the limit for odd sized window
	{
		size = size / 2;
		limit = size;
	}
	for (iterator = size; iterator < n-size; iterator++) //Restricting the checking from 'size' to 'n-size'
	{
		array1[iterator] = 0;
		for (iterator2 = iterator - size; iterator2 <= iterator + limit; iterator2++)
		{
			if (iterator2<n)
			array1[iterator] = array1[iterator] + array[iterator2]; //Calculating the sum at each position
		}
	}
	max = size;
	for (iterator = size; iterator < n - size; iterator++) //Finding the maximum value from all sums
	{ 
		if (array1[max] < array1[iterator])
			max = iterator;
	}
	printf("Winner element is at index %d \n value is %d \n the element is %d\n", max,array1[max],array[max]); //Printing the maximum value and the winner element and its index
}