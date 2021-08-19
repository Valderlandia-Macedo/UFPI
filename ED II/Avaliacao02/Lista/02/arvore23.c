#include "arvore23.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX 50

struct no
{
	int nWords;		// Número de palavras no nó
	char lWord[MAX];	// Palavra da esquerda(primeiro valor)
	Text *lEnglish;	//

	char rWord[MAX];	// Palavra da direita(segundo valor)
	Text *rEnglish;	//

	Node *left;		// Nó da esquerda
	Node *center;	// Nó do meio
	Node *right;	// Nó da direita
};


void treeInitialize(Node **root)
{
	*root = NULL;
}

int treeIsLeaf(Node *root)
{
	int leaf = 0;
	if(root->left == NULL && root->center == NULL && root->right == NULL)
		leaf = 1;

	return leaf;
}

Node *treeCreateNode(char *word, Text *listEnglish, Node *childLeft, Node *childCenter, Node *childRight)
{
	Node *new;
	new = (Node *) malloc(sizeof(Node));
	strcpy(new->lWord, word);
	new->lEnglish = listEnglish;
	new->nWords = 1;
	new->left = childLeft;
	new->center = childCenter;
	new->right = childRight;

	return new;
}

void treeUpdateNode(Node **root, char *word, Text *listEnglish, Node *child)
{
	int cmp = strcmp(word, (*root)->lWord);
	if(cmp >= 0)
	{
		strcpy((*root)->rWord, word);
		(*root)->rEnglish = listEnglish;
		(*root)->right = child;
	}
	else
	{
		strcpy((*root)->rWord, (*root)->lWord);
		(*root)->rEnglish = (*root)->lEnglish;

		strcpy((*root)->lWord, word);
		(*root)->lEnglish = listEnglish;

		(*root)->right = (*root)->center;
		(*root)->center = child;
	}
	(*root)->nWords = 2;
}

Node *treeBreakingNode(Node **root, char *word, Text *listEnglish, char *promove, Text **promoveEnglish, Node *child)
{
	Node *aux;
	int cmpL = strcmp(word, (*root)->lWord);
	int cmpR = strcmp(word, (*root)->rWord);
	if(cmpL < 0)
	{
		strcpy(promove, (*root)->lWord);
		*promoveEnglish = (*root)->lEnglish;
		
		strcpy((*root)->lWord, word);
		(*root)->lEnglish = listEnglish;
	}
	else if(cmpR > 0)
	{
		strcpy(promove, (*root)->rWord);
		*promoveEnglish = (*root)->rEnglish;

		strcpy((*root)->rWord, word);
		(*root)->rEnglish = listEnglish;
	}
	else
	{
		strcpy(promove, word);
		*promoveEnglish = listEnglish;
	}
	aux = treeCreateNode((*root)->rWord, (*root)->rEnglish, (*root)->right, child, NULL);

	(*root)->nWords = 1;
	(*root)->right = NULL;

	return aux;
}

Node *treeInsert(Node **root, char *word, char *wordEnglish, char *promove, Text **promoveEnglish, Node **father)
{
	Node *paux;
	
	Text *list;
	Node *busca;
	treeSearch(*root, word, &busca);
	if(busca)
	{
		if(busca->nWords == 2 && (strcmp(word, busca->rWord) == 0))
		{
			listInsert(&busca->rEnglish, wordEnglish);
		}
		else
		{
			listInsert(&busca->lEnglish, wordEnglish);
		}
		paux = NULL;
	}
	else
	{

		listInitialize(&list);
		listInsert(&list, wordEnglish);

		if(*root == NULL)
		{
			*root = treeCreateNode(word, list, NULL, NULL, NULL);
			paux = NULL;
		}
		else
		{
			if(treeIsLeaf(*root))
			{
				if((*root)->nWords == 1)
				{
					treeUpdateNode(root, word, list, NULL);
					paux = NULL;
				}
				else
				{
					paux = treeBreakingNode(root, word, list, promove, promoveEnglish, NULL);
				}
			}
			else
			{
				if(strcmp(word, (*root)->lWord) < 0)
					paux = treeInsert(&(*root)->left, word, wordEnglish, promove, promoveEnglish, root);

				else if(((*root)->nWords == 1) || (strcmp(word, (*root)->rWord) < 0))
					paux = treeInsert(&(*root)->center, word, wordEnglish, promove, promoveEnglish, root);

				else
					paux = treeInsert(&(*root)->right, word, wordEnglish, promove, promoveEnglish, root);
			}
		}

		if(paux != NULL)
		{
			if(father == NULL)
			{
				*root = treeCreateNode(promove, *promoveEnglish, (*root), paux, NULL);
				paux = NULL;
			}
			else if((*father)->nWords == 1)
			{
				treeUpdateNode(father, promove, *promoveEnglish, paux);
				paux = NULL;
			}
			else
			{
				char guardar[50];
				Text *guardarLista;
				strcpy(guardar, promove);
				guardarLista = *promoveEnglish;

				paux = treeBreakingNode(father, guardar, guardarLista, promove, promoveEnglish, paux);
			}
		}
	}

	return paux;
}

void treeSearch(Node *root, char *wordKey, Node **result)
{
	*result = NULL;
	if(root != NULL)
	{
		if((strcmp(root->lWord, wordKey) == 0) || (root->nWords == 2 && (strcmp(root->rWord, wordKey) == 0)))
		{
			*result = root;
		}
		else if(strcmp(wordKey, root->lWord) < 0)
			treeSearch(root->left, wordKey, result);
		else if(root->right && (strcmp(wordKey, root->rWord) > 0))
			treeSearch(root->right, wordKey, result);
		else
			treeSearch(root->center, wordKey, result);
	}
}

void treeFree(Node *root)
{
	if(root != NULL)
	{
		treeFree(root->left);
		treeFree(root->center);
		treeFree(root->right);

		listFree(root->lEnglish);
		if(root->nWords == 2)
			listFree(root->rEnglish);
		free(root);
	}
}

void treePrint(Node *root)
{
	if(root != NULL)
	{
		treePrint(root->left);
		printf("%s :", root->lWord);
		listPrint(root->lEnglish);
		treePrint(root->center);
		if(root->nWords == 2)
		{
			printf("%s :", root->rWord);
			listPrint(root->rEnglish);
			treePrint(root->right);
		}
	}
}
