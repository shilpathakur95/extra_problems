//Multiplication of two integers using only bitwise operators
//Shilpa Thakur, MGIT
//MissionRnD
#include<stdio.h>
int logic1_multiply(int, int);    //Declaring functions
int add(int, int);
int logic2_multiply(int, int);
main()
{
	int number1, number2, result1, result2;          //Declaring variables
	printf("Enter the two numbers to be multiplied \n");
	scanf_s("%d%d", &number1, &number2);             //Scanning the numbers
	result1 = logic1_multiply(number1, number2);      //Sending the numbers to logic1_multiply() function
	printf("The product of %d and %d is %d\n", number1, number2, result1);  //Printing the result of logic1_multiply() function
	result2 = logic2_multiply(number1, number2);    //Sending the numbers to logic2_multiply() function
	printf("The product of %d and %d is %d\n", number1, number2, result2);  //Printing the result of logic2_multiply() function
}
int logic1_multiply(int number1, int number2)  //Function definition for logic1_multiply():First we check if 'number2' is odd, if yes add 'number1' to result. 'number1' is doubled and 'number2' is halved, whenever 'number2' is odd add 'number1' to result.
{
	int result = 0;                            //Declaring variables
	while (number2 > 0)
	{
		if (number2 & 01)                     //Checking if 'number2' is odd
		{
			result = add(result, number1);     //Adding 'number1' to result
		}
		number1 <<= 1;                        //Left shifting 'number1'
		number2 >>= 1;                        //RIght shifting 'number2'
	}
	return result;
}
int logic2_multiply(int number1, int number2)     //Function definition for logic2_multiply(): We add the first number to the result equal to the value of seconf number of times
{
	int iterator, result = 0;
	for (iterator = 0; iterator < number2; iterator++)
		result = add(result, number1);             //Adding 'number1' to 'result', 'number2' number of times
	return result;
}
int add(int number1, int number2)   //Function definition of add()
{
	int carry;               //Declaring variables
	while (number2 != 0)
	{
		carry = number1&number2;        //Calcutaing the carry bits that occur if 'number1' and 'number2' are added
		number1 = number1^number2;      //Calculating the sum
		number2 = carry << 1;                   //Left shifting 'number2'
	}
	return number1;
}
	