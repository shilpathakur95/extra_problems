//Given three numbers n1,n2,and r. Merge the table of n1 and n2 and find the r th number. In merging it should eliminate duplicate values 
//Shilpa Thakur,MGIT
//MissionRnD2015
#include<stdio.h>
#include <malloc.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
};
void display(struct node *head,int r)
{
	struct node *new_node;
	int temp=0;
	printf("Linked List :\n");
	new_node = head;
	while (new_node!=NULL)
	{
		printf("%d--->", new_node->data);
		if (r == 1)
			temp = new_node->data;
		new_node = new_node->next;
		r--;
	}
	printf("\nthe entry is %d\n", temp);
}
void display1(struct node *head)
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
void table()
{
	int num1, num2;
	int ch, r, multiplier2, multiplier, flag = 0;
	struct node *temp,*prev;
	struct node *head = NULL;
	printf("Enter two numbers and r\n");
	scanf_s("%d%d%d", &num1, &num2,&r);
	if (num1 > num2)
	{
		num1+=num2;
		num2 = num1-num2;
		num1 -=num2;
	}
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = num1;
	temp->next = NULL;
	prev = temp;
	head = prev;
	multiplier = 2;
	multiplier2 = 1;
	ch = r-1;
	while (ch > 0)
	{
		while (num1*multiplier <= num2*multiplier2&&ch>0)
		{
			temp = (struct node*)malloc(sizeof(struct node));
			temp->data = num1*multiplier;
			prev->next = temp;
			temp->next = NULL;
			prev = temp;
			multiplier++;
			ch--;
		}
		if (ch > 0 && num1*multiplier> num2*multiplier2)
		{
			if (num2*multiplier2 != prev->data)
			{
				temp = (struct node*)malloc(sizeof(struct node));
				temp->data = num2*multiplier2;
				prev->next = temp;
				temp->next = NULL;
				prev = temp;
				ch--;
			}
			multiplier2++;
		}
	}
	display(head, r);
}
void main()
{
	table();
}