#include "Tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct no
{
	int code;
	char model[20];
	char tissue[20];
	float size;
	float length;
	char color[10];

	Node *right;
	Node *left;
};


void treeInitialize(Node **root)
{
	*root = NULL;
}

void treeInsert(Node **root, int code, char *model, char *tissue, float size, float length, char *color)
{
	if(*root == NULL)
	{
		*root = (Node *) malloc(sizeof(Node));
		(*root)->code = code;
		strcpy((*root)->model, model);
		strcpy((*root)->tissue, tissue);
		(*root)->size = size;
		(*root)->length = length;
		strcpy((*root)->color, color);

		(*root)->right = NULL;
		(*root)->left = NULL;
	}
	else
		if(code < (*root)->code)
			treeInsert(&(*root)->left, code, model, tissue, size, length, color);
		else
			treeInsert(&(*root)->right, code, model, tissue, size, length, color);
}

void treeShow(Node *root)
{
	if(root != NULL)
	{
		treeShow(root->left);
		treeShow(root->right);
		printf("%d\n", root->code);
		printf("%s\n", root->model);
	}
}

//Libera os dados armazenados
void treeFree(Node *root)
{
	if(root != NULL)
	{
		treeFree(root->left);
		treeFree(root->right);
		free(root);
	}
}