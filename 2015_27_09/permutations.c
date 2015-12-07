//Printing all possible permatations of a given string(String should be maximum an 8 digit number)
//Shilpa Thakur, MGIT
//MissionRnD
#include<stdio.h>
void permutation(char *string, int a, int size); //Declaring functions
void swap(char *first, char *second);
void main()
{
	char string[10], character; //Declaring variables
	int iterator=0;
	printf("Enter the string \n");
	do
	{
		character = getchar();       //Reading string
		string[iterator] = character;
		iterator++;
	} while (character != '\n');
	string[iterator - 1] = '\0';
	printf("The permutations are:\n");
	permutation(string, 0, iterator - 2);//Function call for permutation() function
}
void permutation(char *string, int iterator, int size) //Function definition for permutation() function: Takes the starting address of string, an iterator and size of the string. Prints all possible permutations using recursion
{
	int iterator2;
	if (iterator == size) //If iterator and size point to same index position then print the string
		printf("%s \n", string);
	else
	{
		for (iterator2 = iterator; iterator2 <= size; iterator2++) //Iterating the loop for the size of the string
		{
			swap(string + iterator, string + iterator2); //Function call for swap() function: Swaps the given positions
			permutation(string, iterator + 1, size); //Function call for permutation() function 
			swap(string + iterator, string + iterator2); //Function call for swap() function: Swapping back the previously swapped numbers
		}
	}
}
void swap(char *first, char *second) //Function definition for swap() function: Swaps the elements at the positions passed
{
	char temporary;
	temporary = *first;
	*first = *second;
	*second = temporary;
}