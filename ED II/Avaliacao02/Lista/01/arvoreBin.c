#include "arvoreBin.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 50

struct no
{
    char word[MAX];
    Text *english;
    Node *right;
    Node *left;
};

void treeInitialize(Node **root)
{
    *root = NULL;
}

void treeInsert(Node **root, char *word, char *wordEnglish)
{
	if(*root == NULL)
	{
		*root = (Node *) malloc(sizeof(Node));
		(*root)->left = NULL;
		(*root)->right = NULL;
		strcpy((*root)->word, word);
		
		listInitialize(&(*root)->english);
		listInsert(&(*root)->english, wordEnglish);
	}
	else
	{
		int cmp = strcmp(word, (*root)->word);

		if(cmp > 0)
			treeInsert(&(*root)->right, word, wordEnglish);
		else
			if(cmp < 0)
				treeInsert(&(*root)->left, word, wordEnglish);
			else
				listInsert(&(*root)->english, wordEnglish);
	}
}

void treeSearch(Node *root, char *word, Node **result)
{
	*result = NULL;
	if(root != NULL)
	{
		int cmp = strcmp(word, root->word);
		if(cmp == 0)
		{
			*result = root;
			printf("%s:", (*result)->word);
			listPrint(root->english);
		}
		else
			if(cmp < 0)
				treeSearch(root->left, word, result);
			else
				treeSearch(root->right, word, result);
	}
}


void treeMin(Node *root, Node **result)
{
	*result = NULL;
	if(root != NULL)
	{
		Node *aux;
		aux = root;
		while (aux->left != NULL)
		{
			aux = aux->left;
		}
		*result = aux;
	}
}

void treeRemove(Node **root, char *word)
{
	if(*root != NULL)
	{
		int cmp = strcmp(word, (*root)->word);
		if(cmp < 0)
			treeRemove(&(*root)->left, word);
		else if(cmp > 0)
			treeRemove(&(*root)->right, word);
		else
		{
			if((*root)->left == NULL && (*root)->right == NULL)
			{
				free(*root);
				*root = NULL;
			}
			else if((*root)->left == NULL && (*root)->right != NULL)
			{
				Node *aux;
				aux = (*root)->right;
				free(*root);
				*root = aux;
			}
			else if((*root)->left != NULL && (*root)->right == NULL)
			{
				Node *aux;
				aux = (*root)->left;
				free(*root);
				*root = aux;
			}
			else
			{
				Node *aux;
				Text *auxEnglish;
				char auxWord[20];
				treeMin((*root)->right, &aux);

				auxEnglish = aux->english;
				strcpy(auxWord, aux->word);
				treeRemove(root, aux->word);
				(*root)->english = auxEnglish;
				strcpy((*root)->word, auxWord);
			}
		}
	}
}


void treePrint(Node *root)
{
	
	if(root != NULL)
	{
		treePrint(root->left);
		printf("%s :", root->word);
		listPrint(root->english);
		treePrint(root->right);
	}
}

void treeFree(Node *root)
{
	if(root != NULL)
	{
		treeFree(root->left);
		treeFree(root->right);

		listFree(root->english);
		free(root);
	}
}
