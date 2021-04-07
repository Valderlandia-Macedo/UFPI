#ifndef Tree_H
#define Tree_H

typedef struct no Node;

//Inicializa uma Árvore
void treeInitialize(Node **root);

//Inserir Elemento na Árvore
void treeInsert(Node **root, int value);

//verifica se o valor armazenado é multiplo de 5 e maior que 20
//e retorna o produto desses valores
void treeMult5(Node *root, int *result);

//Liberar a memória
void treeFree(Node *root);

#endif