//Generate all 6 digit numbers with when multiplied by a number(2-6) produces a number that has the same digits as the original number
//Shilpa Thakur,MGIT
//MissionRnD2015
#include<stdio.h>
void generator(); //Function declaration
main()
{
	generator(); //Function call for 'generator'
}
void generator() //Function definition for 'generator':Generates all such numbers
{
	int iterator, num, array1[100], array2[100],limit, temporary1, temporary2, iterator2 = 0, digit,mult, count = 0, iterator3; //Declaring all variables 
	for (mult = 2; mult <= 6; mult++) //Iterating loop for 2 to 6
	{
		limit = 1000000 / mult; //Finding the 'limit' for every multiplier
		for (iterator = 100001; iterator < limit; iterator++) //Iterating the loop for all 6 digit numbers from 1 lakh to the 'limit' value
		{
			num = iterator * mult; //Finding the product called 'num' after multiplying with multiplier 'mul'
			temporary1 = iterator; //Storing the actual number and the product in temporary variables
			temporary2 = num;
			iterator2 = 0;
			count = 0;
			while (temporary1 != 0) //Storing the actual number in an array
			{
				digit = temporary1 % 10;
				temporary1 = temporary1 / 10;
				array1[iterator2] = digit;
				iterator2++;
			}
			iterator2 = 0;
			while (temporary2 != 0) //Storing the product in an array
			{
				digit = temporary2 % 10;
				temporary2 = temporary2 / 10;
				array2[iterator2] = digit;
				iterator2++;
			}

			for (iterator2 = 0; iterator2 < 6; iterator2++) //Iterating the loop for the digits in the product
			{
				for (iterator3 = 0; iterator3 < 6; iterator3++) //Iterating the loop for the digits in the actual number
				{
					if (array1[iterator3] == array2[iterator2]) //If the digit is found 
					{
						array1[iterator3] = -1;              //Replacing the found digit with -1
						count++;                            //Incrementing the 'count'
						break;
					}
				}
				if (count != iterator2 + 1)
					break;  //If a particular digit in product is not found in actual number break the loop
			}
			if (count == 6)
				printf("%d\n", iterator); //If all the 6 digits is are found then display the number
		}
		printf("--------------------------------------------------------------\n");
	}
}