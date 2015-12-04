//Given a linked list which is in pattern like combination of ascending and descending. Sort it.(First all ascending numbers occur ,next all descending nums )
//MissionRnD2015
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
void rec(struct node *point1, int count)
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
	count = count - 2;
	point1 = point1->next;
	if (count>0)
		rec(point1, count);
}
void sort(struct node *head)
{
	struct node *temp=head;
	struct node *num1=NULL;
	int count=0;
	while (temp->next!=NULL)
	{
		if (temp->next->data < temp->data)
		{
			num1 = temp;
			break;
		}
		temp = temp->next;
	}
	if (num1 == NULL)
		return;
	while (temp)
	{
		temp = temp->next;
		count++;
	}
	printf("%d", count);
	rec(num1, count-1);
}
void display(struct node *head1)
{
	struct node *new_node;
	printf("The Linked List :\n");
	new_node = head1;
	while (new_node != NULL)
	{
		printf("%d--->", new_node->data);
		new_node = new_node->next;
	}
	printf("NULL");
}
void main()
{
	struct node *head;
	printf("Enter the linked list\n");
	head=create();
	sort(head);
	display(head);
}
