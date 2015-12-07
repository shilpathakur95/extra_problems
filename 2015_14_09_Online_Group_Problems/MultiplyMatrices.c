//Multiplication of two matrices
//Shilpa Thakur, MGIT
//MissionRnD
#include<stdio.h>
#include<stdlib.h>
void read_array(int A[][10], int row,int col);                              //Declaring functions
void mul_array(int Array1[][10], int row1, int Array2[][10], int col2, int Result[][10], int col1);
void display(int A[][10], int row, int col);
main()
{
	int Array1[10][10], Array2[10][10], Result[10][10];  //Declaring variables
	int row1, col1, row2, col2;
	printf("enter row and coloumn size for array1 \n");
	scanf_s("%d%d",&row1, &col1);                        //Reading the size of first matrix
	printf("enter row and coloumn size for array2 \n");
	scanf_s("%d%d",&row2, &col2);                        //Reading the size of second matrix
	if (col1 == row2)                                    //Checking if the coloumn size of first matrix is equal to the row size of second matrix
	{ 
		printf("enter array1 elements \n");
		read_array(Array1, row1, col1);                 //Reading the elements of first matrix
		printf("enter array2 elements \n");
		read_array(Array2, row2, col2);                 //Reading the elements of second matrix
		mul_array(Array1, row1, Array2, col2, Result, col1);  //Function call for mul_array() function
		display(Result, row1, col2);                          //Function call for display() funcion
	}
	else
		printf("Matrices can't be multiplied ");

}
void read_array(int Array[][10], int row, int col)   //Function definition of read_array() function: Reads the elements of an array by taking its row and coloumn size
{
	int iterator1, iterator2;                        //Declaring variables
	for (iterator1 = 0; iterator1 < row; iterator1++)  
	{
		for (iterator2 = 0; iterator2 < col; iterator2++)
		{
			scanf_s("%d", &Array[iterator1][iterator2]);   //Reading the elements
		}
	}
	
}
void mul_array(int Array1[][10],int row1, int Array2[][10],int col2, int Result[][10],int col1) //Function definition of mul_array() function: Multiplies two arrays by taking input as both the arrays and resultant array and size of both the arrays. Row of 1st matrix and coloumn of 2nd matrix is the same
{
	int iterator1, iterator2, iterator3;                     //Declaring variables
	for (iterator1 = 0; iterator1 < row1; iterator1++)
	{
		for (iterator2 = 0; iterator2 < col1; iterator2++)
		{
			Result[iterator1][iterator2] = 0;
			for(iterator3 = 0; iterator3 < col2; iterator3++)
			{
				Result[iterator1][iterator2] = Result[iterator1][iterator2] + Array1[iterator1][iterator3] * Array2[iterator3][iterator2]; //Multiplying the elements and storing the product in 'Result' array
			}
		}
	}
}
void display(int Result[][10], int row, int col)     //Function definition of display() function: Displays an array by taking the array and its size as input
{
	int iterator1, iterator2;                         //Declaring variables
	printf("the resultant matrix is : \n");
	for (iterator1 = 0; iterator1 < row; iterator1++)   
	{
		for (iterator2 = 0; iterator2 < col; iterator2++)
		{
			printf("%d\t", Result[iterator1][iterator2]);  //Displaying the elements of a row
		}
		printf("\n");                               //Shifting to next row
	}
}