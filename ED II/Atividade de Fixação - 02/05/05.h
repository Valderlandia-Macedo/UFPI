#ifndef Tree_H
#define Tree_H

typedef struct no Node;

//Inicializa uma Árvore
void treeInitialize(Node **root);

//Inserir Elemento na Árvore
void treeInsert(Node **root, int value);

//Recebe a raiz da arvore e o valor de um numero, do qual devolve o 
//pai do numero dado, caso não exista ele vai devolver -1
int treeFather(Node *root, int key);


//Liberar a memória
void treeFree(Node *root);

#endif /* ARVORE_H */