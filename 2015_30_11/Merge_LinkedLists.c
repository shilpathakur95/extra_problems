//Merge two linked list which are in sorted order
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
struct node *create1()
{
	int ch;
	struct node *current=NULL;
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
void merge(struct node *head1,struct node *head2) //Merging the two linked lists
{
	struct node *temp;
	temp = head1;
	while (temp->next!=NULL) //Finding the last node of the first list and pointing it to the head of the other
	{
		temp = temp->next;
	}
	temp->next = head2;
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
void sort(struct node *head1) //Sorting the result list: Sorting the elements by interchanging the numbers and not the nodes
{
	struct node *temp = head1;
	struct node *temp2;
	while (temp)
	{
		temp2 = temp->next;
		while (temp2)
		{
			if (temp2->data < temp->data) //Swapping the two numbers
			{

				temp->data = temp->data + temp2->data;
				temp2->data = temp->data - temp2->data;
				temp->data = temp->data - temp2->data;
			}
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
}

void main()
{
	struct node *head1 = NULL, *head2 = NULL;
	printf("Enter first linked list\n");
	head1=create1();
	printf("Enter second linked list\n");
	head2=create1();
	merge(head1,head2);
	sort(head1);
	display(head1);
}
