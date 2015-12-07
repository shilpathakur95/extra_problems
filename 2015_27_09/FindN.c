//Find n in a series where first n+1 numbers are in ascending order followed by a smaller number followed by n 0s
//Shilpa Thakur, MGIT
//MissionRnD
#include<stdio.h>
int logic(int Array[100]);   //Declaring function
main()
{
	int Array[100] = { 1, 2, 3,4,5,6,7, 9, 6, 0, 0, 0,0,0,0,0}; //Assigning the array elements in the given pattern
	int n;
	n = logic(Array);                                  //Function call for logic() function
	printf("The value of n is %d", n);
}
int logic(int Array[100]) //Function definition for logic() function: Takes the array in given format and returns 'n' value
{ 
	int iterator=1,iterator2=1,temporary,limit; //Declaring variables
	while (Array[iterator] != 0)
		iterator = iterator * 2;      //Doubling 'iterator' for determining a limit position where element is 0. Since the value of n will lie between 'iterator' and limit value
	limit = iterator;                 //When such position is found we assign its value to 'limit'  
	iterator=iterator/2;              //The start of the limited frame which has to be checked is marked by 'iterator'
	while (Array[iterator]!=0)
	{
		iterator2 = 1;
		do
		{
			temporary = iterator + iterator2; //From the 'iterator+1' position checking for 0 element 
			iterator2 = iterator2 * 2;        //If zero is not found then taking iterator+2,iterator+4,iterator+8.....
		} while (Array[temporary] != 0);
		iterator2 = iterator2 / 4;
		if (temporary > limit)  //If the position of zero exceeds 'limit' then limit is assumed to be the first zero and n is limit-2
			return limit - 2;
		else
			iterator = temporary - iterator2; //Else shifting the start of the frame to the last position which was non-zero
	} 
	return iterator-2 ;
}