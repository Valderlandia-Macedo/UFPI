#include "listaEng.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 50

struct texto
{
	char word[MAX];
	Text *next;
};

void listInitialize(Text **head)
{
	*head = NULL;
}

void listInsert(Text **head, char *string)
{
	if(*head == NULL)
	{
		*head = (Text *) malloc(sizeof(Text));
		strcpy((*head)->word, string);
		(*head)->next = NULL;
	}
	else
	{
		Text *new;
		new = (Text *) malloc(sizeof(Text));
		strcpy(new->word, string);
		new->next = *head;
		*head = new;
	}
}

void listRemove(Text **head, char *string)
{
	if(head != NULL)
	{
		Text *anterior;
		Text *aux;
		aux = *head;
		anterior = NULL;
		while(aux != NULL && strcmp(aux->word, string) != 0)
		{
			anterior = aux;
			aux = aux->next;
		}

		if(anterior == NULL)
		{
			*head = aux->next;
			free(aux);
		}
		else if(aux != NULL)
		{
			anterior->next = aux->next;
			free(aux);
		}
		
	}
}

void listPrint(Text *head)
{
	if(head != NULL)
	{
		printf(" %s", head->word);
		if(head->next)
			printf(",");
		else
			printf(".\n");

		listPrint(head->next);
	}
}

void listFree(Text *head)
{
	if(head != NULL)
	{
		listFree(head->next);
		free(head);
	}
}
