# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "List.h"




typedef struct NodeObj
{
	int value;
	struct NodeObj* next;
	struct NodeObj* previous;

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

int ind(List L)
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
			L -> front = temp -> next;
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

void append(List L, int data)
{
	Node n = newNode(data);
	if ( L -> front == NULL && L -> back == NULL)
	{
		L -> front = n;
		L -> back = n; 
	}
	else
	{
		n -> previous = L -> back;
		L -> back -> next = n;
		L -> back = n;
	}

	L -> length += 1;
}

void insertBefore(List L, int data)
{
	Node n = newNode(data);
	if (L -> cursor > 0)
	{
		n -> next = L -> index;
		L -> index -> previous -> next = n;
		n -> previous = L -> index -> previous;
		L ->index -> previous = n; 
		L -> length += 1;
		L -> cursor += 1;
	}
	else if (L -> cursor == 0)
	{
		n -> next = L -> index;
		L -> index -> previous = n;
		L -> front = n;
		L -> length += 1;
		L -> cursor += 1; 
	}
}


void insertAfter(List L, int data)
{
	Node n = newNode(data);
	if (L -> cursor < L -> length - 1 && L -> cursor != -1)
	{
		
		n -> previous = L -> index;
		n -> next = L -> index -> next;
		L -> index -> next -> previous = n;
		L -> index -> next = n;
		L -> length += 1;
	}
	else if (L -> cursor ==L -> length -1)
	{
		n -> previous = L -> index;
		L -> index -> next = n;
		L -> length += 1;
		L -> back = n; 
	}
	
}


void deleteFront(List L)
{
	
	if (L -> length > 1 && L -> cursor == -1)
	{
		
		L -> front = L -> front -> next;
		L -> front -> previous = NULL;
		L -> length -= 1;
		
	}
	else if (L -> length > 1 && L -> cursor != 0)
	{
		
		L -> front = L -> front -> next;
		L -> front -> previous = NULL;
		L -> length -= 1;
		L -> cursor -= 1;

	}
	
	else if (L -> length > 1 && L -> cursor == 0)
	{
		
		L -> front = L -> front -> next;
		L -> front -> previous = NULL;
		L -> length -= 1;
		L -> cursor = -1;
		L -> index = NULL;
	}
	else if	(L -> length == 1 && L -> cursor == 0)
	{
		L -> front = NULL;
		L -> back = NULL;
		L -> cursor = -1;
		L -> index = NULL;
		L -> length = 0;
	}
	
	
	else if (L -> length == 1 && L -> cursor == -1)
	{
		
		L -> front = L -> front -> next;
		L -> length = 0;
		
	}
}

void deleteBack(List L)
{	
	if (L -> length > 1 && L -> cursor < L -> length - 1)
	{
		L -> back = L -> back -> previous;
		L -> back -> next = NULL;
		L -> length -= 1;
		
	}
	else if (L -> length == 1 && L -> cursor == 0)
	{
		L -> front = NULL;
		L -> back = NULL;
		L -> cursor = -1;
		L -> index = NULL;
		L -> length = 0;
	} 
	else if(L -> length > 1 && L -> cursor == L -> length - 1)
	{
		L -> back = L -> back -> previous;
		L -> cursor = -1;
		L -> index = NULL;
		L -> length -= 1;
	}
	else if (L -> length == 1 && L -> cursor == -1)
	{
		L -> front = NULL;
		L -> back = NULL;
		L -> length = 0;
		
	}
}

void delete(List L)
{
	Node temp;
	if (L -> index == L -> front)
	{
		temp = L -> front;
		L -> front = L -> front -> next;
		L -> front -> previous = NULL;
		temp -> next = NULL;
		L -> index = NULL;
		L -> cursor = -1;

	}
	else if (L -> index == L -> back)
	{
		temp = L -> back;
		L -> back = L -> back -> previous;
		L -> back -> next = NULL;
		temp -> previous = NULL;
		L -> index = NULL;
		L -> cursor = -1;
	}
	else
	{
		L -> index -> previous -> next = L -> index -> next;
		L -> index -> next -> previous = L -> index -> previous;
		L -> index -> next = NULL;
		L -> index -> previous = NULL;
		temp = L -> index;
		free(L -> index);
		L -> index = NULL;
		L -> cursor = -1;
    }

    if(temp)
    {
    	free(temp);
    }
    L -> length -= 1;
	temp = NULL;
}

List copy(List L)
{
	List newL = newList();
	Node tempNode = L -> front;
	for (int i = 0; i <= L -> length - 1; i++)
	{
		append(newL, tempNode -> value);
		tempNode = tempNode-> next;
	}

	return newL;
}

void printList(FILE* out, List L);

