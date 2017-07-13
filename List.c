# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "List.h"


typedef struct NodeObj
{
	int value;
	struct nodeObj* next;
	struct nodeObj* previous;

}NodeObj;

typedef NodeObj* Node;

typedef struct ListObj
{
	Node front;
	Node back;
	Node index;
	int cursor;
	int length;
}ListObj;

List newList()
{
	List L = malloc(sizeof(ListObj));
	L -> front = NULL;
	L -> back = NULL;
	L -> cursor = -1;
	L -> index = NULL;
	L -> length = 0;

	return(L);
}

Node newNode(int data)
{
	Node node = malloc(sizeof(NodeObj));
	node -> value = data;
	node -> next = NULL;
	node -> previous = NULL;

	return node;
}

int length(List L)
{
	if (L -> length)
	{
		printf("List Error: calling length() on NULL List reference\n");
      	exit(1);
	}
	else
	{
		return L -> length;
	}
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
	Node aFind = A -> front;
	Node bFind = B -> front;

	if (A -> length == 0 ||   B -> length == 0)
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
			if (aFind -> value != bFind -> value)
			{
				return 0;
			}
			else
			{
				aFind = (Node) aFind -> next;
				bFind = (Node) bFind -> next; 
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
			Node temp = L -> front;
			L -> front =  L -> front -> next;
			L -> front -> previous = NULL;
			temp -> next = NULL;
			free(temp);


		}
		
		L -> cursor = -1;
		L -> length = 0;	

	}
}

void moveFront(List L)
{
	if (length > 0)
	{
		L -> cursor = 0;
		L -> index = L -> front;

	}
}

void moveBack(List L)
{
	if (L -> length >0)
	{
		L -> cursor = L -> length -1;
		L -> index =  L -> back;
	}
}

void movePrev(List L)
{
	if (L -> cursor > 0)
	{
		L -> cursor -= 1;
		L -> index = L -> index -> previous;
	}
	else if ( L -> cursor == 0)
	{
		L -> cursor = -1;
		L -> index = NULL;
	}	
}

void moveNext(List L)
{
	if (L -> cursor >= 0 && L -> cursor != L -> length - 1)
	{
		L -> cursor = -1;
		L -> index = L -> index -> next;
	}
	else if (L -> cursor == L -> length - 1)
	{
		L -> cursor = -1;
		L -> index = NULL;
	}
}

void prepend(List L, int data)
{
	Node n = newNode(data);
	if (L -> front == NULL && L -> back == NULL)
	{
		L -> front = n;
		L -> back = n;
	}
	else
	{
		n -> next = L -> front;
		L -> front -> previous = n;
		L -> front = n;
		if (L -> cursor >= 0)
		{
			L -> cursor += 1;
		}	
	}
	L -> length += 1;

}







