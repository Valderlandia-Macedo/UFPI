#include "arvore.h"
#include <stdlib.h>
#include <stdio.h>

struct no
{
	int value;
	Node *right;
	Node *left;
};

//Inicializa o ponteiro, passado por referencia, com null;
void treeInitialize(Node **root)
{
	*root = NULL;
}

//Recebe o nó raiz da árvore e o valor do novo nó e o insere na árvore;
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

//Recebe a raiz da árvore e a libera por completo;
void treeFree(Node *root)
{
	if(root != NULL)
	{
		treeFree(root->left);
		treeFree(root->right);
		free(root);
	}
}

//Recebe a raiz e retorna o produto dos numeros divisiveis por 5 e maior que 20 encontrados na arvore através de uma variavél inicilizada com 1 passada por referencia;
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
