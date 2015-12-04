//Reverse an Linked list , using recursion
//MissionRnD2015
//Shilpa Thakur,MGIT
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
}*head = NULL;
void display();
int create()
{
	int ch,count=0;
	struct node *current = NULL;
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
		count++;
	} while (ch != 0);
	return count;
}
void rec(struct node *point1,int count)
{
	int iterator;
	struct node *point2;
	point2 = point1;
	for (iterator = count; iterator >0; iterator--)
	{
		point2 = point2->next;
	}
	point1->data += point2->data;
	point2->data = point1->data - point2->data;
	point1->data -= point2->data;
	count=count-2;
	point1 = point1->next;
	if (count>0)
		rec(point1, count);
}
void display()
{
	struct node *new_node;
	printf("The Linked List :\n");
	new_node = head;
	while (new_node != NULL)
	{
		printf("%d--->", new_node->data);
		new_node = new_node->next;
	}
	printf("NULL");
}
void main()
{
	int len;
	len=create();
	rec(head,len-1);
	display();
}