//Given an array of elements, find the winner element: if there are k or more occurrences of that digit. If there are less than k occurances convert others digits such that cost of convention is least. Find cost
//Shilpa Thakur,MGIT
//MissionRnD2015
#include<stdio.h>
int win(int array[100], int n, int k);
main()
{
	int array[100], n,iterator,k,cost; 
	printf("Enter size of array \n");
	scanf_s("%d", &n); //Reading size of array
	printf("Enter no.s \n");
	for (iterator = 0; iterator < n; iterator++)
		scanf_s("%d", &array[iterator]); //Scanning the elements of the array
	printf("Enter occurance \n");
	scanf_s("%d", &k); //Scanning the occurance value 'k'
	cost=win(array,n,k);
	printf("Cost is %d", cost); //Printing the cost
}
int win(int array[100],int size,int k)//Function definition for win(): Takes the array,its size and occurance value. Returns the cost value for the occurance 
{
	int iterator, iterator2, iterate,index[100], count[100] = { 0 }, cost[100] = { 0 }, counter = 1, min, diff, temp;
	for (iterate = 0; iterate < size; iterate++) //storing indices in 'index' aarray
		index[iterate] = iterate;
	for (iterator = 0; iterator < size; iterator++) //Arranging the elements with their indices in ascending orders
	{
		for (iterator2 = iterator + 1; iterator2 < size; iterator2++)
		{
			if (array[iterator] > array[iterator2])
			{
				temp = array[iterator];
				array[iterator] = array[iterator2];
				array[iterator2] = temp;
				temp = index[iterator];
				index[iterator] = index[iterator2];
				index[iterator2] = temp;
			}
		}
	}
	for (iterator = 0; iterator < size; iterator++)//Calcutaing the number of times each element occurs and storing it in an array 'count'
	{
		if (array[iterator] == array[iterator + 1]) //If the adjacent elements are same increment 'counter'
			counter++;
		else
		{
			count[iterator] = counter; //If different element is encountered store its 'counter' value in 'count' array
			if (counter == k) //If the element occurs 'k' number of times then that is the winner element. Cost is 0
			{
				printf("The winner element is %d", array[iterator]);
				return 0;
			}
			else
			counter = 1; //Initializing counter to 1 for next element
		}
	}
	for (iterate = 0; iterate < size; iterate++)
	{
		if (count[iterate] > 0)
		{
			diff = k - count[iterate]; //Calculating the difference between 'k' i.e. occurances needed and occurances of that particular number
			counter = count[iterate] - 1;
			iterator = 1;
			iterator2 = 1;
			while (diff > 0)
			{
				if ((iterate + iterator2 < size&&iterate - counter - iterator >= 0 && array[iterate + iterator2] - array[iterate] < array[iterate] - array[iterate - counter - iterator]) || iterate - counter - iterator<0) //If the element to the right of current element is closer to it than the element on the left,then we change right element to  current element
				{
					cost[iterate] += array[iterate + iterator2] - array[iterate]; //'cost' is the difference between the element on the right and the current element
					iterator2++;
				}
				else if ((iterate - counter - iterator >= 0 && iterate + iterator2 < size&& array[iterate + iterator2] - array[iterate] >= array[iterate] - array[iterate - counter - iterator]) || iterate == size - 1 || iterate + iterator2>=size)//If the element to the left of current element is closer to it than the element on the right,then we change left element to current element or if the current element is on the extreme right
				{
					cost[iterate] += array[iterate] - array[iterate - counter - iterator]; //'cost' is the difference between the element on the left and the current element
					iterator++;
				}
				diff--;
			}
		}
	}
	for (iterate = 0; iterate < size; iterate++)
	{
		if (cost[iterate] != 0) //Finding the first position where the value of cost is not 0 and considering it as minimum value
		{
			min = iterate;
			break;
		}
	}
	for (iterate = min+1; iterate < size; iterate++) //Finding the minimum cost in 'cost' array
	{ 
			if (cost[iterate] < cost[min]&&cost[iterate]!=0)
				min = iterate;
	}
		printf("Winner element is %d at index %d\n", array[min],index[min]); //Printing the result
		return cost[min];
}