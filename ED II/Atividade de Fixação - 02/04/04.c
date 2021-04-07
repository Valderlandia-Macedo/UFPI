#include "04.h"
#include <stdlib.h>
#include <stdio.h>
struct no
{
	int value;
	Node *right;
	Node *left;
};

void treeInitialize(Node **root)
{
	*root = NULL;
}

void treeInsert(Node **root, int value)
{
	if(*root == NULL)
	{
		*root = (Node *) malloc(sizeof(Node));
		(*root)->value = value;
		(*root)->left = NULL;
		(*root)->right = NULL;
	}
	else
		if(value > (*root)->value)
			treeInsert(&(*root)->right, value);
		else
			treeInsert(&(*root)->left, value);
}

void treeFree(Node *root)
{
	if(root != NULL)
	{
		treeFree(root->left);
		treeFree(root->right);
		free(root);
	}
}

void treeMult5(Node *root, int *result)
{
	if(root != NULL)
	{
		if(root->value > 20 && (root->value % 5 == 0))
			*result *= root->value;

		treeMult5(root->left, result);
		treeMult5(root->right, result);
	}
}