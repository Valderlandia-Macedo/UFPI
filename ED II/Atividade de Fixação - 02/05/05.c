#include "05.h"
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

int treeFather(Node *root, int key)
{
	int result = -1;
	if(root != NULL)
	{
		if(root->left)
			if ((root->left)->value == key)
				result = root->value;

		else if(root->right)
			if ((root->right)->value == key)
				result = root->value;

		else
			if(root->value > key)
				result = treeFather(root->left, key);
			else
				result = treeFather(root->right, key);
	}
	return result;
}