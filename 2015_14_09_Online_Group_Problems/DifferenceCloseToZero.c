//Given an array of integers. Return two integers whose difference is closest to zero.
//Shilpa Thakur, MGIT
//MissionRnD
#include<stdio.h>
void sort(int[], int);           //Function declaration
void difference(int[], int);
main()
{
	int Array[100], number, iterator;  //Declaring variables
	printf("Enter the size of array \n");
	scanf_s("%d", &number);           //Reading the size of the array
	printf("Enter the array elements \n");
	for (iterator = 0; iterator < number; iterator++)
		scanf_s("%d", &Array[iterator]); //Reading the elements of the array
	sort(Array, number);  //Function call of sort() function
}
void sort(int Array[100], int size)      //Function definition for sort() function: The elements of the array are sorted in ascending order
{
	int iterator, iterator2, temporary;
	for (iterator = 0; iterator < size; iterator++)  //Comparing the elements of the array from left to right with each element of the array to its right side
	{
		for (iterator2 = iterator + 1; iterator2 < size; iterator2++)
		{
			if (Array[iterator] < Array[iterator2]) //Checking if the particular element is greater than an element on its right side
			{
				temporary = Array[iterator];      //Swapping the elements
				Array[iterator] = Array[iterator2];
				Array[iterator2] = temporary;
			}
		}
	}
	difference(Array, size); //Function call of difference() function
}
void difference(int Array[100], int size) //Function definition for difference() function: Checking the minimum difference between the sorted array of elements. Displays the numbers with the difference closest to 0.
{
	int iterator, iterator2, minimum; //Declaring variables
	minimum = Array[0] - Array[1]; //Assuming the difference of first 2 elements is 'minimum'
	for (iterator = 1; iterator < size; iterator++)  //Comparing 'minimum' to the difference of all the other differences
	{
		for (iterator2 = iterator + 1; iterator2 < size; iterator2++)
			if ((Array[iterator] - Array[iterator2]) < minimum)  //If the difference of any two numbers is less than 'minimum' changing the 'minimum' value
				minimum = Array[iterator] - Array[iterator2];
	}
	for (iterator = 0; iterator < size; iterator++) //After getting the minimum difference finding those integers whose difference corresponds to 'minimum'
	{
		for (iterator2 = iterator + 1; iterator2 < size; iterator2++)
		{
			if (Array[iterator] - Array[iterator2] == minimum)
				printf("The two digits whose difference is closest to zero are %d %d and the difference is %d \n", Array[iterator], Array[iterator2],minimum); //Printing those numbers with least difference
		}
	}
}