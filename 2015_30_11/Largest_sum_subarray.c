//Given an array with both positive and negative integers, find the sub-array with the largest sum and minimum length
//MissionRnD2015
//Shilpa Thakur,MGIT
#include<stdio.h>
void subarr(int A[100], int size);
main()
{
	int size,it,A[100];
	printf("enter size of array\n");
	scanf_s("%d", &size);
	printf("Enter array\n");
	for (it = 0; it < size; it++)
	{
		scanf_s("%d", &A[it]);
	}
	subarr(A, size);
}
void subarr(int A[100], int size)
{
	int maximum=0, max_here = 0, iterator = 0, iterator2 = 0, iterator3;
	maximum = 0;
	while (iterator<size)
	{
		max_here+= A[iterator];
		if (max_here <= 0)
		{
			max_here = 0;
			maximum = 0;
			iterator2 = iterator + 1;
		}
		if (maximum < max_here)
		{
			maximum = max_here;
			iterator3 = iterator;
		}
		iterator++;
	}
	printf("The sub array is:\n");
	for (iterator = iterator2; iterator <= iterator3;iterator++)
		printf("%d\t", A[iterator]);
	printf("\nThe sum is %d", maximum);
}