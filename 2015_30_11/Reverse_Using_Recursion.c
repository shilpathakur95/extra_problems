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
};
struct node *create()
{
	int ch;
	struct node *current = NULL;
	struct node *head = NULL;
	do
	{
		struct node *new_node;

		new_node = (struct node *)malloc(sizeof(struct node));

		printf("Enter the data : ");
		scanf_s("%d", &new_node->data);
		new_node->next = NULL;

		if (head == NULL)
		{
			head = new_node;
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
	return head;
}
void find(struct node *head)
{
	struct node *temp = head;
	struct node *prev=NULL;
	while (temp->next!=NULL)
	{
		prev = temp;
		temp = temp->next;
	}
	if (prev != NULL)
	{
		temp->next = prev;
		prev->next = NULL;
		find(head);
	}
	else
		temp->next = prev;
}
void display(struct node *head)
{
	struct node *new_node;
	printf("Linked List :\n");
	new_node = head;
	while (new_node != NULL)
	{
		printf("%d--->", new_node->data);
		new_node = new_node->next;
	}
	printf("NULL\n");
}
void main()
{
	struct node *head;
	struct node *temp;
	head=create();
	printf("Original ");
	display(head);
	temp = head;
	while (temp->next!=NULL)
	{
		temp = temp->next;
	}
	find(head);
	head = temp;
	printf("Reverse ");
	display(head);
}