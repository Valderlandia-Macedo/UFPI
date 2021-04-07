#ifndef BINARYTREE_H
#define BINARYTREE_H

struct no
{
	int value;
	Node *right;
	Node *left;
};

typedef struct no Node;

//Inicializa uma arvore
void treeInitialize(Node **root);

//Inserir valores na arvore
void treeInsert(Node **root, int value);

//Buscar e retorna um no que contem um determinado valor
void treeSearch(Node *root, Node **result, int key);

//Mostra a impressão na arvore
void treePrint(Node *root);

//Liberar Memoria
void treeFree(Node *root);

//Devolve a Altura da arvore
int treeHeight(Node *root);

//Devolve o Numeros de nó e folhas
void treeNumberNodes(Node *root, int *count);

//Dado um elemento vai devolver a profundidade dele na arvore
int treeDepthNode(Node *root, int value, int count);

#endif