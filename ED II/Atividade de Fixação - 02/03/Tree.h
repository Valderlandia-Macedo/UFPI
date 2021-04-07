#ifndef ARVORE_H
#define ARVORE_H

typedef struct no Node;

//Inicializa uma Árvore
void treeInitialize(Node **root); 

//Liberar a memória
void treeFree(Node *root);

//Inserir Elemento na Árvore
void treeInsert(Node **root, int code, char *model, char *tissue, float size, float length, char *color); 

//Mostrar todos os Nós da Árvore
void treeShow(Node *root);
#endif 