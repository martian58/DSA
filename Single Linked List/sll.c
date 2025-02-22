#include "sll.h"
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>



void createSLL(node **head)
{
	if ( *head == NULL)
	{
		*head=(node*)malloc(sizeof(node));
	}
	node *temp = *head;
	int n;
	printf("How many nodes do you want?\n");
	scanf("%d", &n);
	if(n<=0)
	{
		fprintf(stderr, "invalid number of nodes\n", errno);
		exit(EXIT_FAILURE);
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			printf("Enter the value of node %d\n", i);
			scanf("%d", &(temp->val));
			if (i < n)
			{
				temp->next = (node *) malloc(sizeof(node));
				temp = temp->next;
			}
			if (i == n)
			{
				temp->next = NULL;
			}
		}
	}
}

void displaySLL(node *head)
{
	node *temp = head;
	if (temp == NULL)
	{
		fprintf(stderr, "Linked list does not exist\n", errno);
		exit(-1);
	}
	else
	{
		while (temp != NULL)
		{
			printf("%d -> ", temp->val);
			temp = temp->next;
		}
	}
	printf("NULL");
}

int countNodeSLL(node *head)
{
	node *temp = head;
	int count = 0;
	if(head==NULL)
	{
		fprintf(stderr, "Linked list does not exist\n", errno);
		exit(-1);
	}
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return count;
}

bool searchSLL(node *head, int val)
{
	node *temp = head;
	if(head==NULL)
	{
		fprintf(stderr, "Linked list does not exist\n", errno);
		exit(-1);
	}
	while (temp != NULL)
	{
		if (temp->val == val)
		{
			return true;
		}
		temp = temp->next;
	}
	return false;
}

void insertElementBeginningSLL(node **head, int val)
{
	if(*head==NULL)
	{
		*head=(node*)malloc(sizeof(node));
	}

	node *inserted = (node *) malloc(sizeof(node));
	inserted->val = val;
	inserted->next = *head;
	*head = inserted;
}

void insertElementEndSLL(node *head, int val)
{
	node *temp = head;
	if(head==NULL)
	{
		fprintf(stderr, "Linked list does not exist\n", errno);
		exit(-1);
	}
	node *inserted = (node *) malloc(sizeof(node));
	inserted->val = val;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = inserted;
	inserted->next = NULL;
}

void insertElementMiddleSLL(node *head, int pos, int val)
{
	node *temp = head;
	if(head==NULL)
	{
		fprintf(stderr, "Linked list does not exist\n", errno);
		exit(EXIT_FAILURE);
	}
	node *inserted = (node *) malloc(sizeof(node));
	inserted->val = val;
	if (pos <= 1 || pos >= countNodeSLL(head))
	{
		fprintf(stderr,"Invalid pos\n",errno);
		exit(EXIT_FAILURE);
	}
	else
	{
		for (int i = 1; i < pos - 1; i++)
		{
			temp = temp->next;
		}
		inserted->next = temp->next;
		temp->next = inserted;
	}
}

void deleteElementBeginningSLL(node **head)
{
	if(head==NULL)
	{
		fprintf(stderr, "Linked list does not exist\n", errno);
		exit(EXIT_FAILURE);
	}
	node *temp = *head;
	*head = temp->next;
	free(temp);
}

void deleteElementMiddleSLL(node *head, int pos)
{

	if(head==NULL)
	{
		fprintf(stderr, "Linked list does not exist\n", errno);
		exit(EXIT_FAILURE);
	}
	node *temp = head;
	if (pos >= countNodeSLL(head) || pos < 1)
	{
		fprintf(stderr,"Invalid pos",errno);
		exit(EXIT_FAILURE);
	}
	else
	{
		for (int i = 1; i < pos - 1; i++)
		{
			temp = temp->next;
		}
		node *deleted = temp->next;
		temp->next = deleted->next;
		free(deleted);
	}
}

void deleteElementEndSLL(node *head)
{
	node *temp = head;
	if(head==NULL)
	{
		fprintf(stderr, "Linked list does not exist\n", errno);
		exit(EXIT_FAILURE);
	}
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	free(temp->next);
	temp->next = NULL;
}

void sortSLL(node *head)
{
	if(head==NULL)
	{
		fprintf(stderr, "Linked list does not exist\n", errno);
		exit(-1);
	}
	int n = countNodeSLL(head);
	for (int i = 1; i <= n - 1; i++)
	{
		node *temp = head;
		for (int j = 1; j <= n - i; j++)
		{
			if (temp->val > temp->next->val)
			{
				int tempVal = temp->val;
				temp->val = temp->next->val;
				temp->next->val = tempVal;
			}
			temp = temp->next;
		}
	}
}

void reverseSLL(node *head)
{
	if(head==NULL)
	{
		fprintf(stderr, "Linked list does not exist\n", errno);
		exit(-1);
	}
	int size = countNodeSLL(head);
	node *temp = head;
	int arr[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = temp->val;
		temp = temp->next;
	}
	temp = head;
	for (int i = size - 1; i >= 0; i--)
	{
		temp->val = arr[i];
		temp = temp->next;
	}
}

void insertSLL(node *head1, node *head2, int pos)
{
	node *temp1 = head1;
	node *temp2 = head2;
	if (temp1 == NULL || temp2 == NULL)
	{
		fprintf(stderr,"At least one of your lists doesn't exist\n",errno);
		exit(EXIT_FAILURE);
	}
	if(pos<=1||pos>= countNodeSLL(head1))
	{
		fprintf(stderr,"Invalid pos\n",errno);
		exit(EXIT_FAILURE);

	}
	else
	{
		for (int i = 1; i < pos - 1 && temp1 != NULL; i++)
		{
			temp1 = temp1->next;
		}
		while (temp2->next != NULL)
		{
			temp2 = temp2->next;
		}
		temp2->next = temp1->next;
		temp1->next = head2;
	}
}

void insertSLLBeginning(node **head1, node *head2)
{
	node *temp2 = head2;
	if (*head1 == NULL || head2 == NULL)
	{
		fprintf(stderr,"At least one of your lists doesn't exist\n",errno);
		exit(EXIT_FAILURE);
	}
	else
	{
		while (temp2->next != NULL)
		{
			temp2 = temp2->next;
		}
		temp2->next = *head1;
		*head1 = head2;
	}
}


void deleteSLL(node **head, int index1, int index2, int numberOfNodes)
{
	if (*head == NULL || index1 <= 0 || index2 > numberOfNodes || index1 > index2)
	{
		fprintf(stderr,"Invalid parameters or list doesn't exist\n",errno);
		exit(EXIT_FAILURE);
	}
	node *temp = *head;
	node *prev = NULL;
	int currentIndex = 1;
	while (temp != NULL && currentIndex < index1)
	{
		prev = temp;
		temp = temp->next;
		currentIndex++;
	}
	while (temp != NULL && currentIndex <= index2)
	{
		node *nextNode = temp->next;
		free(temp);
		temp = nextNode;
		currentIndex++;
	}
	if (prev == NULL)
	{
		*head = temp;
	}
	else
	{
		prev->next = temp;
	}
}
void insertSLLEnd(node *head1, node *head2)
{
	node *temp1 = head1;
	if (head1 == NULL || head2 == NULL)
	{
		fprintf(stderr,"At least one of your lists doesn't exist\n",errno);
		exit(EXIT_FAILURE);
	}
	else
	{
		while (temp1->next != NULL)
		{
			temp1 = temp1->next;
		}
		temp1->next = head2;
	}
}


node *sliceSLL(node *head, int index1, int index2, int numberOfNodes)
{
	node *temp = head;
	node *newHead = NULL;
	node *newTail = NULL;
	if (index1 <= 0 || index2 > numberOfNodes || index1 > index2)
	{
		fprintf(stderr,"Invalid slice parameters\n",errno);
		exit(EXIT_FAILURE);
	}
	for (int i = 1; i < index1; i++)
	{
		if (temp == NULL)
		{
			printf("Invalid slice parameters\n");
			return NULL;
		}
		temp = temp->next;
	}
	while (temp != NULL && index1 <= index2)
	{
		node *newTemp = (node *) malloc(sizeof(node));
		newTemp->val = temp->val;
		newTemp->next = NULL;
		if (newHead == NULL)
		{
			newHead = newTemp;
			newTail = newTemp;
		}
		else
		{
			newTail->next = newTemp;
			newTail = newTemp;
		}
		temp = temp->next;
		index1++;
	}
	return newHead;
}

void createCircularSLL(node **start)
{
	if(*start==NULL)
	{
		*start=(node*)malloc(sizeof(node));
	}
	node *temp = *start;
	int n;
	printf("How many nodes do you want?\n");
	scanf("%d", &n);
	if (n <= 0)
	{
		fprintf(stderr,"Invalid number of nodes\n",errno);
		exit(EXIT_FAILURE);
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			printf("Enter the value of node %d\n", i);
			scanf("%d", &(temp->val));
			if (i < n)
			{
				temp->next = (node *) malloc(sizeof(node));
				temp = temp->next;
			}
			if (i == n)
			{
				temp->next = *start;
			}
		}
	}
}

void displayCircularSLL(node *start)
{
	node *temp = start;
	if(start==NULL)
	{
		fprintf(stderr, "Linked list does not exist\n", errno);
		exit(-1);
	}
	else
	{
		do
		{
			printf("%d ->", temp->val);
			temp = temp->next;
		} while (temp != start);
	}
}

void insertElementBeginningCircularSLL(node **start, int val)
{
	if(start==NULL)
	{
		fprintf(stderr, "Linked list does not exist\n", errno);
		exit(-1);
	}
	node *inserted = (node *) malloc(sizeof(node));
	node *temp = *start;
	inserted->val = val;
	inserted->next = *start;
	while (temp->next != *start)
	{
		temp = temp->next;
	}
	temp->next = inserted;
	*start = inserted;
}

void insertElementMiddleCircularSLL(node *start, int pos, int val)
{
	if(start==NULL)
	{
		fprintf(stderr, "Linked list does not exist\n", errno);
		exit(-1);
	}
	node *temp = start;
	if (pos <= 1)
	{
		printf("Invalid pos");
		return;
	}
	else
	{
		node *inserted = (node *) malloc(sizeof(node));
		inserted->val = val;
		for (int i = 1; i < pos - 1; i++)
		{
			temp = temp->next;
		}
		inserted->next = temp->next;
		temp->next = inserted;
	}
}

void insertElementEndCircularSLL(node *start, int val)
{
	if(start==NULL)
	{
		fprintf(stderr, "Linked list does not exist\n", errno);
		exit(-1);
	}
	node *temp = start;
	node *inserted = (node *) malloc(sizeof(node));
	inserted->val = val;
	while (temp->next != start)
	{
		temp = temp->next;
	}
	temp->next = inserted;
	inserted->next = start;
}

bool searchCircularSLL(node *start, int val)
{
	if(start==NULL)
	{
		fprintf(stderr, "Linked list does not exist\n", errno);
		exit(-1);
	}
	node *temp = start;
	do
	{
		if (temp->val == val)
		{
			return true;
		}
		temp = temp->next;
	} while (temp != start);
	return false;
}

void deleteElementBeginningCircularSLL(node **start)
{
	if(start==NULL)
	{
		fprintf(stderr, "Linked list does not exist\n", errno);
		exit(-1);
	}
	node *deleted = *start;
	node *temp = *start;
	while (temp->next != *start)
	{
		temp = temp->next;
	}
	*start = deleted->next;
	temp->next = *start;
	free(deleted);
}

void deleteElementMiddleCircularSLL(node *start, int pos)
{
	if(start==NULL)
	{
		fprintf(stderr, "Linked list does not exist\n", errno);
		exit(-1);
	}
	node *temp = start;
	if (pos <= 1)
	{
		printf("Invalid pos");
	}
	else
	{
		for (int i = 1; i < pos - 1; i++)
		{
			temp = temp->next;
		}
		node *deleted = temp->next;
		temp->next = deleted->next;
		free(deleted);
	}
}

void deleteElementEndCircularSLL(node *start)
{
	if(start==NULL)
	{
		fprintf(stderr, "Linked list does not exist\n", errno);
		exit(-1);
	}
	node *temp = start;
	while (temp->next->next != start)
	{
		temp = temp->next;
	}
	free(temp->next);
	temp->next = start;
}

int countNodeCircularSLL(node *start)
{
	if(start==NULL)
	{
		fprintf(stderr, "Linked list does not exist\n", errno);
		exit(-1);
	}
	int count = 0;
	node *temp = start;
	if (temp->next == NULL)
	{
		return count;
	}
	else
	{
		do
		{
			count++;
			temp = temp->next;
		} while (temp != start);
		return count;
	}
}

void reverseCircularSLL(node *start)
{
	if(start==NULL)
	{
		fprintf(stderr, "Linked list does not exist\n", errno);
		exit(-1);
	}
	int n = countNodeCircularSLL(start);
	int arr[n];
	node *temp = start;
	for (int i = 0; i < n; i++)
	{
		arr[i] = temp->val;
		temp = temp->next;
	}
	for (int i = n - 1; i >= 0; i--)
	{
		temp->val = arr[i];
		temp = temp->next;
	}
}

void sortCircularSLL(node *start)
{
	if(start==NULL)
	{
		fprintf(stderr, "Linked list does not exist\n", errno);
		exit(-1);
	}
	int n = countNodeCircularSLL(start);
	for (int i = 1; i <= n - 1; i++)
	{
		node *temp = start;
		for (int j = 1; j <= n - i; j++)
		{
			if (temp->val > temp->next->val)
			{
				int tempVal = temp->val;
				temp->val = temp->next->val;
				temp->next->val = tempVal;
			}
			temp = temp->next;
		}
	}
}