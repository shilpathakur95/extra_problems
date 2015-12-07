//Converting a decimal number to its base -2 representation
//Shilpa Thakur, MGIT
//MissionRnD
#include<stdio.h>
int binary(int number, int array[100]);                     //Declaring functions
void reverse(int array[100], int size, int array2[100]);
main()
{
	int number,array[100],array2[100],size,iterator;       //Declaring variables
	printf("Enter the number");                           
	scanf_s("%d", &number);                                //Reading the number
	size=binary(number, array);                            //Function call for binary() function
	reverse(array,size,array2);                            //Function call for reverse() function
	printf("The result is ");                              //Printing the result
	for (iterator = 0; iterator < size; iterator++)
	{
		printf("%d", array2[iterator]);
	}
}
int binary(int number, int array[100])  //Function definition of binary() function: Takes a number and converts it into its base -2 representation and stores it in an 'array'. Returns the size of that array
{
	int iterator=0;                   //Declaring variables
	while (number != 0)
	{
		if (number%-2 < 0)           //If dividing the number with -2 gives negative remainder then add 1 to quotient and the remainder becomes positive
		{
			array[iterator] = 1; //Remainder is stored in the 'array'
			number = (number / -2) + 1; //Calculating quotient for next iteration
		}
		else
		{
			array[iterator] = number%-2; //Remainder is stored in the 'array'
			number = number / -2;  //Calculating quotient for next iteration
		}
		iterator++;
	}
	return iterator;
}
void reverse(int array[100], int size,int array2[100]) //Function definition for reverse() function: Reverses the elements of a given array
{
	int iterator,iterator2=0; //Declaring variables
	for (iterator = size-1; iterator >=0; iterator--)
	{
		array2[iterator2] = array[iterator]; //Storing elements in 'array2' in reverse order
		iterator2++;
	}
}