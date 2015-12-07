//Sort an array of 0s and 1's
//MissionRnD2015
//Shilpa Thakur,MGIT
#include<stdio.h>
main()
{
	int A[100],i,num,count0=0,count1=0; //Declaring the variables 
	printf("Enter the size of the array \n");
	scanf("%d",&num);
	print("Enter the digits in the array \n);
	for(i=0;i<num;i++)
		scanf("%d",&A[i]);
	for(i=0;i<num;i++) 
	{
		if(A[i]==0)        
			count0++;  //Since 0 is encountered incrementing the count for 0
	}
	for(i=0;i<count0;i++) //Printing all the 0's first as it is a sorted list
		A[i]=0;
	for(i=count0;i<num;i++) //Printing all the 1's next
		A[i]=1;
	printf("The array is: \n");
	for (i = 0; i<num; i++)
		printf("%d\t", A[i]);
}
