//Staunton Sample
//sbsample
//pa2
//Lex.c

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "List.h"
//inSort()
//sorts list by array
List inSort(char* arr[], int ind)
{
	List l = newList();
	append(l, 0);

	for ( int i = 1; i <= ind; i++)
	{

		moveFront(l);

		while ( (index(l)) >= 0 && strcmp(arr[i], arr[get(l)]) >= 0 )
		{
			moveNext(l);
		}
		int listIndex = index(l);
		if (listIndex == -1)
		{
			append(l, i);
		}
		else
		{
			insertBefore(l,i);
		}
	}
	return l;
}
int main(int argc, char* argv[])
{
	// checks for proper number of args
	if (argc < 3)
	{
		printf("error %s requires two files \n", argv[0]);
		exit(1);
	}
	int fileSize = 256;
	FILE *in;
	FILE *out;
	// Read in with fopen
	in  = fopen(argv[1], "r");
	// Read out with fopen
	out = fopen(argv[2], "w");

	char buffer[256];
	int lineCount = 0;
	//counts lines in input
	// Had to look on stack overflow for this.
	while( fgets(buffer, fileSize, in) != NULL)
	{
		lineCount += 1;
	}

	fclose(in);
	//reopen the file
	in = fopen(argv[1], "r");
	char *item;
	char *wordArr = (char *)malloc(lineCount * sizeof(char*));
	int i = 0;
	// copy individual words to new file

	while( fgets(buffer, fileSize, in) != NULL)
	{
		item = malloc((sizeof(lineCount)) * sizeof(char));
		strcopy(item, buffer);
		wordArr[i] = item;
		i++;
		free(item);
	}
	// create new list
	List sortList = newList();
	//sort the list
	sortList = inSort(&wordArr, lineCount);
	//print the list
	int listCount = index(sortList);
	for (moveFront(sortList); listCount; moveNext(sortList))
	{

		fprintf(out, "%d", wordArr[get(sortList)]);

	}

	fclose(in);
	fclose(out);
	freeList(&sortList);
	free(wordArr);

	return 0;
}
