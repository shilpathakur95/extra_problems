//Given an array of structure having students' details, display the details for the given student id
//Shilpa Thakur, MGIT
//MissionRnD
#include<stdio.h>
struct student                           //Creating a structure for all details of the students
{
	char name[100];
	char department[100];
	char section[100];
	char id[30];
};
int logic(int, struct student[]);       //Declaring functions
int check_id(struct student [], int );
main()
{
	int number, iterator,iterator2=0,check;  //Declaring variables
	struct student record[50];
	char c;
	printf("Enter the number of students");
	scanf_s("%d", &number);                 //Reading the number of students
	getchar();
	for (iterator = 0; iterator < number; iterator++) //Reading each detail of every student
	{
		iterator2 = 0;
		printf("Enter student name \n");
		do
		{
			c = getchar();
			record[iterator].name[iterator2] = c;
			iterator2++;
		} while (c != '\n');
		record[iterator].name[iterator2-1] = '\0';
		iterator2 = 0;
		printf("Enter student department \n");
		do
		{
			c = getchar();
			record[iterator].department[iterator2] = c;
			iterator2++;
		} while (c != '\n');
		record[iterator].department[iterator2-1] = '\0';
		iterator2 = 0;
		printf("Enter student section \n");
		do
		{
			c = getchar();
			record[iterator].section[iterator2] = c;
			iterator2++;
		} while (c != '\n');
		record[iterator].section[iterator2-1] = '\0';
		iterator2 = 0;
		printf("Enter student id \n");
		do
		{
			c = getchar();
			record[iterator].id[iterator2] = c;
			iterator2++;
		} while (c != '\n');
		record[iterator].id[iterator2-1] = '\0';
	}
	check=check_id(record,number); //Function call for check_id() function to check if the ids are unique
	if (check = 0)                 //If the ids are unique we continue 
	{
		iterator = logic(number, record); //Function call for logic() function
		if (iterator != -1)               //Checking if the match of ids is found
		{                                //Printing the details
			printf("Student id is %s \n", record[iterator].id);
			printf("Student name is %s \n", record[iterator].name);
			printf("Student belongs to %s department \n", record[iterator].department);
			printf("Student sections is %s \n", record[iterator].section);
		}
		else                               //If no match is found
			printf("no match found");
	}
	else                                       //If the ids are not unique we end the program execution
		printf("Given student ids are not unique \n");
}
int check_id(struct student record[],int number) //Function definition for check_id() function: Checks if the ids are unique
{
	int iterator, iterator1, iterator2;          //Declaring variables
	for (iterator = 0; iterator < number; iterator++)  //Comparing every id with all the other ids
	{
		for (iterator1 = iterator + 1; iterator1 < number;iterator1++)
		{
			iterator2 = 0;
		while ((record[iterator1].id[iterator2] == record[iterator].id[iterator2]) && (record[iterator1].id[iterator2] != '\0') && (record[iterator].id[iterator2] != '\0'))
			iterator2++;
		if (iterator2 != 0)
		{
			if (record[iterator1].id[iterator2] == '\0'&&record[iterator].id[iterator2] == '\0')
				return -1;                           //If two ids match return -1
		}
		}
	}
	return 0; //If no ids match return 0
}
int logic(int number, struct student record[])  //Function definition for logic() function
{
	char identity[100],c;                       //Declaring variables
	int iterator, iterator2=0;
	printf("Enter the required student id \n");
	do                                          //Scanning the required student's id
	{
		c = getchar();
		identity[iterator2] = c;
		iterator2++;
	} while (c != '\n');
	identity[iterator2-1] = '\0';
	for (iterator = 0; iterator < number; iterator++)  //Comparing all ids with the required id
	{
		iterator2 = 0;
		while ((identity[iterator2] == record[iterator].id[iterator2]) && (identity[iterator2] != '\0') && (record[iterator].id[iterator2] != '\0')) //If the characters of the given id and required id are same and are not delimiters increment 'iterator2'
			iterator2++;
		if (iterator2 != 0) //If the characters of an id and required id are same we check if they are of the same length
		{
			if (identity[iterator2] == '\0'&&record[iterator].id[iterator2] == '\0') //If they are of the same length return the index of the id
				return iterator;
			else
				return -1;    //if they are not of same length return -1
		}
	}
	return -1;  //If there is no match at all return -1
}

