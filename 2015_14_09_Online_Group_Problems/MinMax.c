//Given an array of integers. Return the maximum and minimum of that array.
//Shilpa Thakur, MGIT
//MissionRnD
#include<stdio.h>
void sort(int[], int);           //Function declaration
main()
{
	int Array[100], number, iterator;  //Declaring variables
	printf("Enter the size of array \n");
	scanf_s("%d", &number);           //Reading the size of the array
	printf("Enter the array elements \n");
	for (iterator = 0; iterator < number; iterator++)
		scanf_s("%d", &Array[iterator]); //Reading the elements of the array
	sort(Array, number);  //Function call of sort() function
	printf("Minimum of the array is %d \n", Array[0]); //Displaying the minimum of the array
	printf("Maximum of the array is %d", Array[number - 1]);  //Displaying the maximum of the array
}
void sort(int Array[100], int size)      //Function definition for sort() function: The elements of the array are sorted in ascending order
{
	int iterator, iterator2, temporary;
	for (iterator = 0; iterator < size; iterator++)  //Comparing the elements of the array from left to right with each element of the array to its right side
	{
		for (iterator2 = iterator + 1; iterator2 < size; iterator2++)
		{
			if (Array[iterator] > Array[iterator2]) //Checking if the particular element is greater than an element on its right side
			{
				temporary = Array[iterator];      //Swapping the elements
				Array[iterator] = Array[iterator2];
				Array[iterator2] = temporary;
			}
		}
	}
}