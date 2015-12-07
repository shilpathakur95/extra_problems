//Given a string and a delimiter,return the tokens
//Shilpa Thakur, MGIT
//MissionRnD
#include<stdio.h>
int return_array(char string[100], char array[100][100],char character);              //Function declaration
main()
{
	char string[100], array[100][100], character;     //Declaring variables
	int iterator = 0, size;
	printf("Enter the string \n");
	do                                               //Reading the string
	{
		character = getchar();
		string[iterator] = character;
		iterator++;
	} while (character != '\n');
	string[iterator - 1] = '\0';
	printf("Enter the delimiter \n");
	character = getchar();                           //Reading the delimiter
	size = return_array(string, array,character);                //Function call for return_array() function
	printf("The array elements are : \n");
	for (iterator = 0; iterator <= size; iterator++)
	{
		printf("%s \n", array[iterator]);           //Printing the array elements
	}

}
int return_array(char string[100], char array[100][100],char character)  //Function definition for return_array() function: Stores the elements of the 'string' in a 2d 'array'. Returns the size of the 'array'
{
	int iterator2, iterator3 = 0, iterator4 = 0;                //declaring variables
	for (iterator2 = 0; string[iterator2] != '\0'; iterator2++)  //For every character in the sentence
	{
		if (string[iterator2] != character)                            //If the character is not delimiter then store it in a 2d array
		{
			array[iterator3][iterator4] = string[iterator2];
			iterator4++;
		}
		else                                                    //when a delimiter is encountered then we jump to storing the next cluster
		{
			array[iterator3][iterator4] = '\0';
			iterator3++;
			iterator4 = 0;
		}
	}
	array[iterator3][iterator4] = '\0';                        //delimiting the last array cluster
	return iterator3;                                              //returning the size of the 'array'
}