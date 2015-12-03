//Find median of a given linked list(Sorted Linked List) 
//MissioRnD2015
//Shilpa Thakur,MGIT
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *create()
{
	int ch;
	struct node *current = NULL;
	struct node *head = NULL;
	do
	{
		struct node *new;

		new = (struct node *)malloc(sizeof(struct node));

		printf("Enter the data : ");
		scanf_s("%d", &new->data);
		new->next = NULL;

		if (head == NULL)
		{
			head = new;
			current = new;
		}
		else
		{
			current->next = new;
			current = new;
		}

		printf("Do you want to enter another element 1.yes 0.no : ");
		scanf_s("%d", &ch);
	} while (ch != 0);
	return head;
}
void median(struct node *head)
{
	struct node *front = head, *back = head;
	struct node *temp=NULL;
	int flag,count=0;
	float med;
	while (front)
	{
		if (front->next == NULL)
		{
			flag = 1;
			break;
		}
		else if (front->next->next == NULL)
		{
			flag = 0;
			break;
		}
		else
		{
			front = front->next->next;
			count++;
		}
	}
	while (count)
	{
		back = back->next;
		count--;
	}
	if (flag == 1)
	{
		printf("There are odd numbers in the linked list and the median is: \n");
		printf("%d", back->data);
	}
	else if (flag == 0)
	{
		temp = back;
		back = back->next;
		med = (temp->data + back->data) / 2;
		printf("There are even number of elements in the linked list and the median is: \n");
		printf("%f",med );
	}
}
void main()
{
	struct node *head1 = NULL;
	printf("Enter first linked list\n");
	head1 = create();
	median(head1);
	getchar();
	getchar();
}