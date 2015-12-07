//Min Rank of a given number. Given an unsigned integer number as input,find the index of the number(index starts from 0) in all permutations of the number, sorted in asccending order.
//Shilpa Thakur, MGIT
//MissionRnD
#include<stdio.h>
int store_in_array(int,int[],int[]);   //Declaring functions
int factorial(int);
int permutation(int[], int);
int check_repeat(int[], int, int);
main()
{
	int number,count, result, Array1[100], Array2[100]; //Declaring variables 
	printf("enter number");
	scanf_s("%d", &number);
	count=store_in_array(number,Array1,Array2); //Calling store_in_array() function 
	result=permutation(Array1, count);          //Calling permutation() function
	printf("The index of %d is %d", number, result);
}
int store_in_array(int number, int Array1[100], int Array2[100]) //Function definition of store_in_array(): The number is split and stored in an array
{
	int remainder, result = 0;                           //Declaring variables 
	int iterator1 = 0, iterator2 = 0, count = 0;
	while (number != 0)
	{
		remainder = number % 10;                        //Finding the remainder of number/10
		Array2[iterator1] = remainder;                  //Storing remainder in 'Array2'
		count++;                                        //incrementing 'count'
		iterator1++;                                    //incrementing 'iterator'
		number = number / 10;                          //Diving number by 10
	}
	for (iterator1 = count - 1; iterator1 >= 0; iterator1--)   //Since the 'number' is stored in reverse, storing it in correct order
	{
		Array1[iterator2] = Array2[iterator1];                //Storing the number in correct order in 'Array1'
		iterator2++;
	}
	
	return count;                                        //Returning size of the 'Array1'
}
int permutation(int Array1[100],int count)              //Function definition of permutation() function: Finding the permutations of all numbers above the given number.
{
	int iterator1,iterator2,flag=1,result=0,results,repeat;    //Declaring variables 
		for (iterator1 = 0; iterator1 < count; iterator1++)
		{
			for (iterator2 = iterator1 + 1; iterator2 < count; iterator2++)
			{
				if (Array1[iterator2] < Array1[iterator1])      //Checking if the next element is smaller than the current element
				{
					results = factorial(count - (iterator1 + 1)); //Initialising the factorial value to a temporary varaible 'results'
					repeat = check_repeat(Array1, iterator1,count); //Test case: If there are any reapeated digits is checked by calling check_repeat() function. It returns the number of times a value is repeated in a set. Eg:2313=2
					results = results / factorial(repeat); //Dividing 'results' with the factorial of the number of the number of times a digit is repeated
					result = result + results;       //Adding the temporary varaible 'results' to the actual 'result'
				}
			}
		}
	return result;  //Returning the permutations for the number of elements above the given number i.e the index of the given number
}
int factorial(int number)                            //Function definition for factorial() function: Finding the factorial of the given number
{
	int iterator, factorial=1;                       //Declaring variables 
	for (iterator = 1; iterator <= number; iterator++)
		factorial= factorial*iterator;                //Multipying 'factorial' with all the numbers from one to the given number
	return factorial;                                 //Returning the factorial
}
int check_repeat(int Array1[100], int iterator,int count)
{
	int iterator1,iterator2,repeat=1;
	for (iterator1 = iterator; iterator1 < count; iterator1++)
	{
		for (iterator2 = iterator1 + 1; iterator2 < count; iterator2++)
		{
			if (Array1[iterator1] == Array1[iterator2])
				repeat++;
		}
	}
	return repeat;
}