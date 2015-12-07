//Print the entered date in words.
//Shilpa Thakur, MGIT
//MissionRnD
#include<stdio.h>
void Logic(char[]);                   //decalaring functions
void Date_print(int[], int);          
int power(int, int);
void one(int);
void two(int);
void Month_print(int[], int);
void Year_print(int[]);
void onedigit(int);
void twodigit(int);
void wrongdate();
main()
{
	char Day[100], character;         //Declaring varaibles
	int iterator = 0;
	printf("Enter date\n");
	do                               //Reading the date character by character using getchar() function
	{
		character = getchar();       //Storing each character in 'character' varaible
		Day[iterator] = character;   //Storing them in 'Day' char array
		iterator++;
	} while (character != '\n');     //End the loop when user presses enter
	Logic(Day);                      //Function call for 'Logic' fucntion
}
void Logic(char Day[100])            //Function definition for 'Logic' function
{
	int count = 0, count1 = 0, iterator2,iterator;               //Declaring variables
	int Date[100], Month[100], Year[100];
	for (iterator = 0; Day[iterator] != '/'; iterator++) //Reading the string till '/' is encountered
	{
		Date[iterator] = Day[iterator]-48;               //Storing each character in 'Date' integer array. Since character array elements are being stored in integer array it is converted into ASCII value staring from 49. Therefore we minus 48 from it.
		count++;                                         //Incrementing count to get the size of 'Date' array
	}
	
	Date_print(Date, count);                       //Function call for 'Date_print' function
	count = count + 1;                             //Incrementing count to skip '/' character
	for (iterator2 = count; Day[iterator2] != '/'; iterator2++) //Reading the string for the month part of the string till next '/' is encountered
	{
		Month[count1] = Day[iterator2]-48;          //Storing each character in 'Month' integer array. Since character array elements are being stored in integer array it is converted into ASCII value staring from 49. Therefore we minus 48 from it.
		count1++;                                   //Incrementing count1 to get the size of 'Month' array
	}
	Month_print(Month, count1);                    //Function call for 'Month_print' function
	iterator2 = 0;                                 //Initailising it to 0 for next loop
	count = count + count1 + 1;                    //Calculating count so that it points to the position where year starts in the string. count is for date,count1 if month and addition of 1 is for skipping '/' character
	for (iterator =count; Day[iterator] != '\0'; iterator++)  //Reading the string for the year part till end of string is encountered
	{
		Year[iterator2] = Day[iterator]-48;      //Storing each character in 'Year' integer array. Since character array elements are being stored in integer array it is converted into ASCII value staring from 49. Therefore we minus 48 from it.
		iterator2++;                            //Incrementing iterator2
	}
	Year_print(Year);                          //Function call for 'Year_print' function
}
void Date_print(int Date[100], int count)     //Function defintion for 'Date_print' function
{
	int number = 0, iterator;
	for (iterator = 0; iterator < count; iterator++)
	{
		number = number + (Date[iterator] * power(10, ((count - 1) - iterator))); //Converting the digits in the array into a number
	}
	if (number > 31)                            //Since there are no dates greater than 31 we call wrongdate() function.
		wrongdate();                            //Function call for 'wrong_date' function
	if (count == 1)                             //If it is a single digit number then call one() function 
		one(number);                           //Function call for 'one' function
	else                                       
	{
		if (Date[0] = 0)                       //If it is a two digit number but starts with a 0 then it is a single digit number so call one() function
			one(number);                      //Function call for 'one' function
		else                                  //If the two digit number does not start with one then call two() function
			two(number);                      //Function call for 'two' function
	}
}
int power(int base, int index)               //Function definition for 'power' function
{
	int iterator, temporary = 1;             //Declaring varaibles
	for (iterator = 1; iterator <= index; iterator++)
	{
		temporary = temporary*base;           //Multiplying the 'temporary' to 'base' 'index' number of times
	}
	return temporary;                       //Resturning the result
}
void one(int number)                        //Function definition for 'one' function
{
	if (number == 1)                       //Printing the digit in verbal form from 1-9
		printf("First of");
	else if (number == 2)
		printf("Second of");
	else if (number == 3)
		printf("Third of");
	else if (number == 4)
		printf("Fourth of");
	else if (number == 5)
		printf("Fifth of");
	else if (number == 6)
		printf("Sixth of");
	else if (number == 7)
		printf("Seventh of");
	else if (number == 8)
		printf("Eighth of");
	else
		printf("Ninth of");
}
void two(int number)                           //Function definition for 'two' function
{
	int iterator = number / 10;                //'iterator' is initialised to first digit of the 2 digit number
	number = number % 10;                      //'number' is initailised to second digit of the two digit number
	if (iterator == 1)                         //If the number falls from 10-19 series printing them accoring to their 'number' value
	{
		if (number == 1)
			printf("Eleventh of");
		else if (number == 2)
			printf("Twelvth of");
		else if (number == 3)
			printf("Thirteenth of");
		else if (number == 4)
			printf("Fourteenth of");
		else if (number == 5)
			printf("Fifteenth of");
		else if (number == 6)
			printf("Sixteenth of");
		else if (number == 7)
			printf("Seventeenth of");
		else if (number == 8)
			printf("Eighteenth of");
		else if (number == 9)
			printf("Ninteenth of");
		else
			printf("Tenth of");
	}
	else if (iterator==2)           //If the number falls in 20-29 series
	{
		printf("Twenty");           //Printing "twenty" as it is common for all numbers
		if (number == 0)            //If the number is 20 then directly printing it
			printf("th of");
		else                       //else send the second digit of the number to 'one' function as its a single digit
			one(number);
	}
	else if (iterator == 3)        //If the number falls in 30-39 series
	{
		printf("Thirty");         //Printing "thirty" as it is common for all numbers
		if (number == 0)          //If the number is 30 then directly printing it
			printf("th of");
		else    //else send the second digit of the number to 'one' function 
			one(number);
	}
}
void Month_print(int Month[100], int count)      //Function definition for 'Month_print' function
{
	int number = 0, iterator;                    //Declaring varaibles
	for (iterator = 0; iterator < count; iterator++)
	{
		number = number + (Month[iterator] * power(10, ((count - 1) - iterator)));  //Converting the digits in the array into a number
	}
	if (number == 1)                                   //Printing the months according to the 'number' value
		printf(" January ");
	else if (number == 2)
		printf(" February ");
	else if (number == 3)
		printf(" March ");
	else if (number == 4)
		printf(" April ");
	else if (number == 5)
		printf(" May ");
	else if (number == 6)
		printf(" June ");
	else if (number == 7)
		printf(" July ");
	else if (number == 8)
		printf(" August ");
	else if (number == 9)
		printf(" September ");
	else if (number == 10)
		printf(" October ");
	else if (number == 11)
		printf(" November ");
	else
		printf(" December ");

}
void Year_print(int Year[100])                      //Function definition for 'Year_print' function
{
	int iterator = 0, number1 = 0, number2 = 0;      //Declaring varaibles
	for (iterator = 0; iterator < 2; iterator++)
		number1 = number1 + (Year[iterator] * power(10, (1 - iterator)));  //Converting the first half digits in the array into a number and storing in 'number1'
	for (iterator = 2; iterator < 4; iterator++)
		number2 = number2 + Year[iterator] * power(10, (3 - iterator));    //Converting the second half digits in the array into a number and storing in 'number2'
	if (number2 > 10)                         //If the second half of the year is greater than 10 then printing both he halves
	{
		twodigit(number1);                   //Printing first half by seding it two 'twodigit' function
		twodigit(number2);                   //Printing second half by seding it two 'twodigit' function
	}
	else                                 //If the seconf half of the year is not greater than 10
	{
		if (Year[1] == 0)                //If the second digit of the 'Year' is 0 eg:2005,1005
		{
			onedigit(Year[0]);           //printing the first digit followed by "thousand and" by calling 'onedigit' function and sending only the first digit of 'Year'
			printf("Thousand and ");
			onedigit(number2);           //printing the secind half of the 'Year' by calling 'onedigit' function as the second half is single digit number
		}
		else                            //else if the second digit of 'Year' is not 0 eg:1905,1804
		{
			twodigit(number1);          //Printing the first half by calling 'twodigit' fucntion as first half of 'year' is a two digit number
			printf(" not ");           // Following it by "not"
			onedigit(number2);         //Following it by second half of the number by calling 'onedigit' as it is a single digit number
		}
	}

}
void twodigit(int number)               //Function definition for 'twodigit' function
{
	int iterator = number / 10;          //Storing the first half of the number in 'iterator'
	number = number % 10;               //Storing the second half of the number in 'number'
	if (iterator == 1)                  //If the number falls from 10-19 series printing them accoring to their 'number' value
	{
		if (number == 0)
			printf("Ten ");
		else if (number == 1)
			printf("Eleven ");
		else if (number == 2)
			printf("Twelve ");
		else if (number == 3)
			printf("Thirteen ");
		else if (number == 4)
			printf("Fourteen ");
		else if (number == 5)
			printf("Fifteen ");
		else if (number == 6)
			printf("Sixteen ");
		else if (number == 7)
			printf("Seventeen ");
		else if (number == 8)
			printf("Eighteen ");
		else
			printf("Nineteen ");
	}
	else if (iterator == 2)                     //If the number falls in 20-29 series
	{
		printf("Twenty ");                      //Printing "twenty" as it is common for all number
		onedigit(number);                       //sending the next digit to 'onedigit' function
	}
	else if (iterator == 3)                      //If the number falls in 30-39 series
	{
		printf("Thirty ");                        //Printing "thirty" as it is common for all number
		onedigit(number);                         //sending the next digit to 'onedigit' function
	}
	else if (iterator == 4)                       //If the number falls in 40-49 series
	{
		printf("Fourty ");                        //Printing "fourty" as it is common for all number
		onedigit(number);                         //sending the next digit to 'onedigit' function
	}
	else if (iterator == 5)                        //If the number falls in 50-59 series
	{
		printf("Fifty ");                          //Printing "fifty" as it is common for all number
		onedigit(number);                          //sending the next digit to 'onedigit' function
	}
	else if (iterator == 6)                         //If the number falls in 60-69 series
	{
		printf("Sixty ");                           //Printing "sixty" as it is common for all number
		onedigit(number);                           //sending the next digit to 'onedigit' function
	}
	else if (iterator == 7)                        //If the number falls in 70-79 series
	{
		printf("Seventy ");                        //Printing "seventy" as it is common for all number
		onedigit(number);                          //sending the next digit to 'onedigit' function
	}
	else if (iterator == 8)                          //If the number falls in 80-89 series
	{
		printf("Eighty ");                           //Printing "eighty" as it is common for all number
		onedigit(number);                            //sending the next digit to 'onedigit' function
	}
	else                                             //If the number falls in 90-99 series
	{
		printf("Ninty ");                            //Printing "ninty" as it is common for all number
		onedigit(number);                            //sending the next digit to 'onedigit' function
	}
}
void onedigit(int number)                        //Function definition for 'onedigit' function
{
	if (number == 1)                             //Printing the numbers in their verbal form
		printf("One ");
	else if (number == 2)
		printf("Two ");
	else if (number == 3)
		printf("Three ");
	else if (number == 4)
		printf("Four ");
	else if (number == 5)
		printf("Five ");
	else if (number == 6)
		printf("Six ");
	else if (number == 7)
		printf("Seven ");
	else if (number == 8)
		printf("Eight ");
	else
		printf("Nine ");
}
void wrongdate()                               //Function definition for 'wrongdate' function
{
	printf("Wrong date");                     //Printing "wrong date" if the date is wrong
}
