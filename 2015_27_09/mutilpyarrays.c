//Multiplication of 2 binary arrays A , B.  A takes Max 10 digits B takes Max 5 digits. Convert them into binary and join them . multiply both arrays .Store each 32 bits converted to decimal in C array
//Shilpa Thakur, MGIT
//MissionRnD
#include<stdio.h>
void binary(int Array[320], int size);  //Declaring functions
int answer(int result[160][480], int Array1[320], int size1, int Array2[320], int size2); 
void add(int[][480], int, int);
void finalanswer(int result[][480], int fixedpoint, int size);
int power(int base, int num);
void main()
{
	int size1, size2, Array1[320] = { 0 }, Array2[160] = { 0 }, Array3[160][480] = { 0 }, iterator,iterator3;
	printf("Enter the size of first array\n"); //Reading the size of first array (max size 10)
	scanf_s("%d", &size1);
	printf("Enter array1 elements \n");
	for (iterator = 0; iterator < size1; iterator++)
	{
		scanf_s("%d", &Array1[32 * iterator]); //Reading the elements of first array and storing them at multiples of 32 positions i.e. 0,32,64...
	}
	printf("Enter the size of second array\n");
	scanf_s("%d", &size2);        //Reading the size of second array (max size 5)
	printf("Enter array2 elements \n");
	for (iterator = 0; iterator < size2; iterator++)
	{
		scanf_s("%d", &Array2[32 * iterator]); //Reading the elements of second array and storing them at multiples of 32 positions i.e. 0,32,64...
	}
	binary(Array1, size1); //Function call for binary() function
	binary(Array2, size2);  //Function call for binary() function
	iterator=answer(Array3, Array1, size1 * 32, Array2, size2 * 32); //Function call for answer() function
	finalanswer(Array3, iterator,(size1+size2)*32); //Function call for finalanswer() function
	 iterator3 = 0; 
	 printf("The resultant array elements are: \n");
	 while(iterator3*32 <= (size1 + size2 - 1) * 32)
	{
		printf("%d\t", Array3[iterator][32*iterator3]);
		iterator3++;
	}
	getchar();
	getchar();
}
void binary(int Array[320], int size)//Function definition for binary() function:Takes the array and its size. Converts array elements into binary of 32 bits and joins all the binary converted elements.
{
	int iterator1, iterator2, number;
	for (iterator1 = 0; iterator1 <= (size - 1) * 32; iterator1++)
	{
		number = Array[iterator1]; //Storing the element in 'number' i.e the elements at 0,32,64...
		iterator2 = iterator1 + 31; 
		while (number != 0)
		{
			if (number % 2 == 0)
				Array[iterator2] = 0; //Coverting the 'number' into binary and storing from right to left of the 32 bits 
			else
				Array[iterator2] = 1;
			number = number / 2;
			iterator2--;
		}
		while (iterator2 >= iterator1)
		{
			Array[iterator2] = 0; //Rest of the bits are padded with 0s
			iterator2--;
		}
		iterator1 = iterator1 + 31;
	}
}
int answer(int result[][480], int Array1[], int size1, int Array2[], int size2)//Function definition for answer() function:Takes resultant array,2 arrays, their sizes. Multiplies the given arrays and stores result in 'result' array
{
	int iterator = 0, count = 0, iterator2, iterator3 = 0, iterator4, x, iterator5, variablepoint = 0, fixedpoint = 0, n = 0;
	for (iterator2 = size2 - 1; iterator2 >= 0; iterator2--) //Iterating for second array 
	{
		iterator4 = (size1 + size2) - 1 - iterator3; //iterator4 points to the right most bit from where the result of the multiplication will be stored
		x = iterator4;
		if (count == 2) //After two digits of array2 are multiplied with all digits of array1 we add the 2 results
		{
			for (iterator5 = (size1 + size2) - 1; iterator5 >= size2-iterator3; iterator5--)
			{
				result[fixedpoint][iterator5] = result[fixedpoint][iterator5] + result[variablepoint][iterator5]; // 'fixedpoint' points to first row,'variablepoint' points to second row
				if (result[fixedpoint][iterator5] > 1) //Incase the answer is greater than one we call add() function
					add(result, fixedpoint, iterator5);
			}
			count = 1; //After adding first two rows the count and 'iterator3' is assigned as 1 because the result is stored at first row
			iterator3 = 1;
		}
		if (Array2[iterator2] == 1) //Multiplication is done only if the second array element is 1.
		{
			for (iterator = size1 - 1; iterator >= 0; iterator--) //Iterating the loop for array1 elements
			{
				result[iterator3][iterator4] = Array1[iterator] * Array2[iterator2]; //Storing the result of multiplication on 'result'. 'iterator3' gives row index, 'iterator4' gives coloumn index
				iterator4--; //Decrementing the coloumn index for each element multiplication
			}
			count++; //Incrementing count after each multiplication of array1 elements with single element of 'array2' elements
			if (count == 2) 
				variablepoint = iterator3;
			else if (count == 1)
				fixedpoint = iterator3;
		}
		iterator3++; //Incrementing 'iterator3' for next iteration
	}
	return fixedpoint;
}
void add(int result[][480], int fixedpoint, int iterator5) //Function definition for add() function: Takes the 'result' array and the position where the answer is > 1
{
	if (result[fixedpoint][iterator5] == 2) //Checking if the answer is 2 i.e 10
	{
		result[fixedpoint][iterator5] = 0; //0 is stored at that place
		result[fixedpoint][iterator5 - 1]++; //Add 1 to the left side bit
	}
	else                             //If answer is 3 i.e. 11
	{
		result[fixedpoint][iterator5] = 1; //1 is stored at that place
		result[fixedpoint][iterator5 - 1]++;  //Add 1 to the left side bit
	}
}
void finalanswer(int result[][480],int fixedpoint, int size) //Function call for finalanswer() function: Takes the resultant array and starts coverting them to decimal at every 32 bits.
{
	int iterator, number = 0,n=0;
	for (iterator = size-1; iterator >= 0; iterator--) //Iterating the loop for the size of the coloumns in the result array
	{
		number += result[fixedpoint][iterator] * power(2, n); //Converting them to decimal and adding
		n++;
		if (n == 32) //After 32 bits being coverted to decimal
		{
			result[fixedpoint][iterator] = number; //Store the decimal store it in that 32th position
			n = 0; //Assign n and number to 0
			number = 0;
		}
	}
}
int power(int base, int num)
{
	int iterator,pow=1;
	for (iterator = 1; iterator <= num; iterator++)
	{
		pow = pow*base;
	}
	return pow;
}