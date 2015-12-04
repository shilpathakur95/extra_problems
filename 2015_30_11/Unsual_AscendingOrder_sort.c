//Sorted a linked list which is in ascending order but two numbers are changed.Ex: 1->2->3->15->10->4->20; O/p:1-2-3-4-10-15-20
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
void sort(struct node *head)
{
	struct node *temp=head;
	struct node *num1=NULL;
	int count = 1;
	while (temp->next!=NULL)
	{
		if (temp->next->data < temp->data&&count == 1)
		{
			num1 = temp;
			count++;
		}
		else if (temp->next->data < temp->data&&count == 2)
		{
			temp = temp->next;
			break;
		}
		temp = temp->next;
	}
	if (num1 == NULL)
		return;
	count = num1->data;
	num1->data = temp->data;
	temp->data = count;
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
