# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "List.h"

List newList()
{
	List *list = (List*) malloc(sizeof(list));
	node -> front = NULL;
	node -> back = NULL;
	node -> cursor = -1;
	node -> index = NULL;
	node -> length = 0;

	return list;
}

Node *newNode(int data)
{
	Node *node = (Node*)malloc(sizeof(node));
	node -> value = data;
	node -> next = NULL;
	node -> previous = NULL;

	return node;
}

int length(List L)
{
	return L -> lengthl
}

int index(List L)
{
	return L -> cursor;
}

int front(List L)
{
	
	return L -> front -> value;
	
}

int back(List L)
{
	return L -> back -> value;
}

int get(List L)
{
	return L -> index -> value; 
}

int equals(List A, List B)
{
	Node aFinder = A -> front;
	Node bFinder = B -> front;

	if (A -> length == NULL ||   B -> length == NULL)
	{
		return 0;
	}
	else if (A -> length != B -> length )
	{
		return 0;
	}
	else
	{
		for (int i = 0; i < A -> length; i++)
		{
			if (aFinder -> value != bFinder -> value)
			{
				return 0;
			}
			else
			{
				aFinder = aFinder -> next;
				bFinder = bFinder -> next; 
			}
		}
	}
	return 1;
}

void clear(List L)
{
	if(L -> index != NULL)
		{
			L -> index = NULL;
		}
	if(L -> back != NULL)
		{
			L -> back = NULL;
		}
	for (int i = 0; i < L-> length; i++)
	{
		if (L -> length > 0)
		{	
			Node *temp = L -> front;
			L -> front =  L -> front -> next;
			L-> front -> previous = NULL;
			temp -> next = NULL;
			free(temp);


		}
		
		cursor = - 1
		length = 0;	

	}
}





