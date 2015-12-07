//Given 3 unsigned integers as input X,Y,Z. FInd X to the power Y modulo Z.
//Shilpa Thakur, MGIT
//MissionRnD
#include<stdio.h>
int logic1_storeinarray(int, int, int);            //Declaring functions
int logic2_separatemodulus(int, int, int);
int powerfunction(int, int);
void main()
{
	int X, Y, Z,result1,result2;                   //Declaring variables
	printf("Enter the values for X,Y,Z \n");
	scanf_s("%d%d%d", &X, &Y, &Z);                 //Scanning the three integers
	result1=logic1_storeinarray(X, Y, Z);          //Sending the numbers to logic1_storeinarray() function
	printf("%d power %d modulo %d is %d \n ",X,Y,Z, result1); //Printing the result of logic1_storeinarray() function
	if (Y <= 20)                                       //This logic works only for small values of Y 
	{
		result2 = logic2_separatemodulus(X, Y, Z);        //Sending the numbers to logic2_storeinarray() function
		printf("%d power %d modulo %d is %d \n ", X, Y, Z, result2);//Printing the result of logic2_storeinarray() function
	}

}
int logic1_storeinarray(int base, int power,int modulo)    //Function definition of logic1_storeinarray(): Storing the values of X power Y modulus Z for the range where the values are not repeated in an array
{
	int Array[100], iterator1;                 //Declraing varaibles
		for (iterator1 = 0; iterator1 <= base; iterator1++)
		{
			Array[iterator1] = powerfunction(base, iterator1) % modulo;   //Storing X power Y mod Z in an array in the range Y=0 to X
		}
	return Array[(power % (base + 1))]; //Returning the result
}
int powerfunction(int base, int number)    //Funtion definition of power() function: Calculating 'base' power 'index'
{
	int iterator,power=1;                  //Declraing varaibles
	for (iterator = 1; iterator <= number; iterator++)
	{
		power = power*base;               //Multiplying 'power' with 'base', 'number' number of times
	}
	return power;
}
int logic2_separatemodulus(int base, int power, int modulo) //Function definition of logic2_separatemodulus(): Logic is (x*y)%m=((x%m)*(y%m))%m
{
	int iterator,result=1;                    //Declraing varaibles
	for (iterator = 1; iterator <= power; iterator++)
	{
		result = result*(base%modulo);       //Multiplying 'base%modulo' to the result 'power' number of times
	}
	result = result%modulo;
	return result;
}