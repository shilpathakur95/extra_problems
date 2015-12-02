//Write a program to add two linked list (Each node is represented by a digit ) (Note: Unequal Lengths can also be given )
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
	struct node *head = NULL;
	struct node *current = NULL;
	do
	{
		struct node *new_node;

		new_node = (struct node *)malloc(sizeof(struct node));

		printf("Enter the data : ");
		scanf_s("%d", &new_node->data);
		new_node->next = NULL;

		if (head == NULL)
		{
			head= new_node;
			current = new_node;
		}
		else
		{
			current->next = new_node;
			current = new_node;
		}

		printf("Do you want to enter another element 1.yes 0.no : ");
		scanf_s("%d", &ch);
	} while (ch != 0);
}
void add(struct node *head1,struct node *head2) //Adding two linked lists and storing in first linked list
{
	struct node *temp1 = head1;
	struct node *temp2 = head2;
	while (temp1)
	{
		if (temp2->next == NULL&&temp1->next != NULL) //Checking if second linked list is smaller than first
		{
			temp1->data = temp1->data + temp2->data; //Added the last element of second linked list to first linked list and break
			break;
		}
		else if (temp1->next == NULL&&temp2->next != NULL)//Checking if second linked list is larger than first
		{
			temp1->data = temp1->data + temp2->data; //Add the last element of second linked list to first linked list
			temp1->next = temp2->next; //Join the rest of the list to first list and break
			break;
		}
		else
		{
			temp1->data = temp1->data + temp2->data;
		}
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
}
void display(struct node *head1)
{
	struct node *new_node;
	printf("The Linked List :");
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
	struct node *head1, *head2;
		printf("Enter first linked list\n");
		head1=create();
		printf("Enter second linked list\n");
		head2=create();
		add(head1,head2);
		display(head1);
}