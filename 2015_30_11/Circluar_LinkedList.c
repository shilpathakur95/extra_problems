//Add a node to the circular linked list
//MissionRnD2015
//Shilpa Thakur,2015
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
}*head=NULL;
struct node *create()
{
	int ch;
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
			current->next = head;
		}
		else
		{
			current->next = new;
			current = new;
			current->next = head;
		}

		printf("Do you want to enter another element 1.yes 0.no : ");
		scanf_s("%d", &ch);
	} while (ch != 0);
	return head;
}

void display()
{
	struct node *new_node;
	printf("The Linked List :\n");
	new_node = head;
	while (new_node->next != head)
	{
		printf("%d--->", new_node->data);
		new_node = new_node->next;
	}
	printf("%d", new_node->data);
	printf("\n");
}
void insert_start(int num)
{
	struct node *temp,*temp2=head;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = num;
	temp->next = head;
	while (temp2->next!=head)
		temp2 = temp2->next;
	temp2->next = temp;
	head = temp;
}
void insert_pos(int num, int pos)
{
	struct node *temp, *temp2 = head;
	int it=1;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = num;
	if (pos != 1)
	{
		while (it < pos - 1)
		{
			if (temp2->next != head)
			{
				temp2 = temp2->next;
				it++;
			}
			else
			{
				printf("Position is greater than list\n");
				return;
			}
		}
		temp->next = temp2->next;
		temp2->next = temp;
	}
	else
		insert_start(num);
}
void insert_end(int num)
{
	struct node *temp, *temp2 = head;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = num;
	while (temp2->next != head)
		temp2 = temp2->next;
	temp2->next = temp;
	temp->next = head;
}
main()
{
	int choice,num,pos;
	printf("Enter elements\n");
	create();
	display();
	printf("Enter your choice\n");
	do
	{
		printf("1.Insert at start 2.Insert at position 3.Insert at end 4.Exit\n");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:printf("Enter element\n");
			scanf_s("%d", &num);
			insert_start(num);
			display();
			break;
		case 2:printf("Enter element\n");
			scanf_s("%d", &num);
			printf("Enter position at which the element should be inserted\n");
			scanf_s("%d", &pos);
			insert_pos(num,pos);
			display();
			break;
		case 3:printf("Enter element\n");
			scanf_s("%d", &num);
			insert_end(num);
			display();
			break;
		}
	} while (choice != 4);
}