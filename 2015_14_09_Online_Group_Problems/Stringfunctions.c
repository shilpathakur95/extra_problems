//Performing string handling operations on the given strings(strlen,strcat,strcmp,strsub,trim)
//Shilpa Thakur, MGIT
//MissionRnD
#include<stdio.h>
int strlen(char[]);                                         //Decalring functions
void strcat(char[],char[]);
int strcmp(char[], char[]);
void strsub(char[], int, int);
void trim(char[]);
main()
{
	char string1[100],string2[100],string3[100],string4[100],string5[100], character;      //Declaring variables
	int iterator = 0,length,start;
	printf("Enter the first string to concat \n");
	do                                                         //Reading the first string for concatination
	{
		character = getchar();
		string1[iterator] = character;
		iterator++;
	} while (character != '\n');
	string1[iterator-1] = '\0';
	iterator = 0;
	printf("Enter the second string to concat \n");
	do                                                          //Reading the second string for concatination
	{
		character = getchar();
		string2[iterator] = character;
		iterator++;
	} while (character != '\n');
	string2[iterator-1] = '\0';
	length = strlen(string1);                                  //Function call for strlen() function
	printf("Length of string %s is %d \n", string1,length);    //Printing the length of first string
	length = strlen(string2);
	printf("Length of string %s is %d \n", string2, length);  //Function call for strlen() function
	strcat(string1, string2);                                 //Printing the length of second string
	iterator = 0;
	printf("Enter the first string to compare \n");
	do                                                        //Reading the first string for comparing
	{                                              
		character = getchar();
		string3[iterator] = character;
		iterator++;
	} while (character != '\n');
	string3[iterator - 1] = '\0';
	iterator = 0;
	printf("Enter the second string to compare \n");
	do                                                        //Reading the second string for concatination
	{
		character = getchar();
		string4[iterator] = character;
		iterator++;
	} while (character != '\n');
	string4[iterator - 1] = '\0';
	length=strcmp(string3, string4);                         //Function call for strcmp() function
	printf("the comparision of the strings is %d \n", length); //Printing the result of the comparision
	iterator = 0;
	printf("Enter the string to print its substring \n");
	do                                                         //Reading the main string
	{
		character = getchar();
		string4[iterator] = character;
		iterator++;
	} while (character != '\n');
	string4[iterator - 1] = '\0';
	printf("Enter the start position and length of substring \n");  
	scanf_s("%d%d", &start, &length);                           //Reading the start position and length for the subsrting
	strsub(string4, start, length);                             //Function call for strsub() function
	iterator = 0;
	printf("Enter the string to be trimmed \n");
	getchar();
	do                                                        //Reading the text to be trimmed
	{
		character = getchar();
		string5[iterator] = character;
		iterator++;
	} while (character != '\n');
	string5[iterator - 1] = '\0';
	trim(string5);                                           //Function call for trim() function
}
int strlen(char string[100])      //Function definition for strlen() function:Returns the length of the given string
{
	int iterator, length = 0;
	for (iterator = 0; string[iterator] != '\0'; iterator++)
		length++;                 //Incrementing 'length' for each character in 'string'
	return length;                //Returning the length
}
void strcat(char string1[100], char string2[100]) //Function definition for strlcat() function: Concats to strings i.e. adds the second string to the first string
{
	int length1,iterator;
	length1 = strlen(string1); //Finding the length of the first string
	for (iterator = 0; string2[iterator] != '\0'; iterator++)
	{
		string1[length1] = string2[iterator]; //Adding the second string to the first string
		length1++;
	}
	string1[length1] = '\0';
	printf("The strings after concatenation are %s %s \n", string1, string2); //Displaying both the strings are concatination
}
int strcmp(char string1[100], char string2[100])  //Function definition for strlcmp() function: Compares both the strings. Returns 0 if string1=string2, 1 if string1>string2, -1 if string1<string2
{
	int iterator;                         //declaring variables 
	for (iterator = 0; string1[iterator] != '\0'; iterator++) //Comparing each character of string1 to string2
	{
		if (string1[iterator] - string2[iterator] != 0)       //Checking if the string characters are different
		{
			if (string1[iterator] - string2[iterator] > 0)    //If character of string1 > string 2 we return 1
				return 1;
			else                                              //else we return -1
				return -1;
		}
	}
	if (string1[iterator] == '\0'&&string2[iterator] != '\0')  //If both strings are equal but string1 is shorter than string2 return -1
		return -1;
	else
		return 0;                                             //If they are of same length return 0
}
void strsub(char string[100], int start, int length)  //Function definition for strsub() function:Displays the substring of the main string where the start position and length of substring is specified
{
	int iterator,iterator2=0;                       //Declaring variables
	char substring[100];
	for (iterator = start; iterator < (start + length); iterator++)   //Storing the substring in 'substring' from the 'start' to the 'length'
	{
		if (string[iterator] != '\0')
		{
			substring[iterator2] = string[iterator];
			iterator2++;
		}
		else
		{
			printf("The length is longer than the given string \n"); //If the given length exceeds the main string then printing a error message
			return 0;
		}
	}
	substring[iterator2] = '\0';
	printf("The substring is %s", substring);
}
void trim(char string[100])    //Function definition for trim() function:Trims the given text of all the unnecessary spaces(leading,in between,trailing)
{
	int iterator, iterator2;  //Declaring variables
	for (iterator = 0; string[iterator] != '\0'; iterator++)
	{
		if ((string[0] == ' ') || (string[iterator] == ' ') && (string[iterator + 1] == ' ')) //Check for consecutive spaces
		{
			for (iterator2 = iterator; string[iterator2] != '\0'; iterator2++)   
			{
				string[iterator2] = string[iterator2 + 1];               //Removing the extra space 
			}
			string[iterator2] = '\0';                                    //Adding delimiter to the changed string
			iterator--;                                                 //Decrementing 'iterator'
		}
	}
	for (iterator = strlen(string) - 1; iterator >= 0; iterator--)  //Check for trailing spaces
	{
		if (string[iterator] == ' ')
			string[iterator] = '\0';                                //Adding delimiter if there is a space
		else
			break;
	}
	printf("The string after trim is\n%s", string);  //Printing the new string 
}
