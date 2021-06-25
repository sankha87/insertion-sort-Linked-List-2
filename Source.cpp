// C program for insertion sort on a linked list 		O(n^2)
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
#include<stdlib.h> 
#include <conio.h>

struct Node
{
	int data;
	struct Node *next;
};

struct Node* push(struct Node*, int);
void append(struct Node*, int);
void printList(struct Node*);
//struct Node* sortedInsert(struct Node*, struct Node*);

struct Node* insertionSort(struct Node *head_ref)			//O(n^2)
{
	struct Node *sorted = NULL;				// Initialize sorted linked list 

	while (head_ref != NULL)				//O(n)
	{
		struct Node *nextnode = head_ref->next;

		struct Node *current;

			if (sorted == NULL || sorted->data >= head_ref->data)		/* Special case for the head end */
			{
				head_ref->next = sorted;
				sorted = head_ref;
			}
			else
			{
				current = sorted;
				while (current->next != NULL &&	current->next->data < head_ref->data)		//O(n)
					current = current->next;
				
				head_ref->next = current->next;
				current->next = head_ref;
			}
		head_ref = nextnode;
	}
	return sorted;
}

int main()
{
	struct Node *head = NULL;
	int n, *num, i;
	printf("How many numbers ? ");
	scanf("%d", &n);
	num = (int*)malloc(n * sizeof(int));
	printf("Enter numbers to be inserted: \n");
	for (int i = 0; i<n; i++)
		scanf("%d", num + i);

	head = push(head, *(num + 0));

	for (int i = 1; i<n; i++)
		append(head, *(num + i));

	printf("\nLinked List before sorting \n");
	printList(head);

	head = insertionSort(head);

	printf("\nLinked List after sorting \n");
	printList(head);

	_getch();
}

Node* push(Node *head_ref, int num)
{
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
	if (new_node == NULL)
	{
		printf("Stack Overflow \n");
		return NULL;
	}
	else
	{
		new_node->data = num;
		new_node->next = head_ref;
		head_ref = new_node;
		return head_ref;
	}
}

void append(Node *head_ref, int num)
{
	if (head_ref == NULL)
	{
		printf("This function cannot be used to add a node to an Empty list \n");
		return;
	}
	struct Node *head_ref2 = head_ref;
	struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->data = num;
	new_node->next = NULL;
	while (head_ref2->next != NULL)
		head_ref2 = head_ref2->next;
	head_ref2->next = new_node;
}

void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}