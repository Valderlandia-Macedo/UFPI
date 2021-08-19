/* TAD: arvore binária */

#ifndef ARVOREBIN_H
#define ARVOREBIN_H

/* Dependencia de módulos: */
#include "lista.h"

// Apelidando árvore
typedef struct no Node;

// Inicializar a arvore
void treeInitialize(Node **root);

// Recebe a palavra e a linha onde ela se encontra e a insere na arvore
void treeInsert(Node **root, char *wold, int line);

// Recebe uma palavra e busca a existencia na arvore, além de contar o numero de passos
void treeSearch(Node *root, char *wold, Node **result, int count);

// Remove um elemento da árvore que contenha a palavra chave
void treeRemove(Node **root, char *word);

// Remove um elemento da lista e, se existir apenas 1 elemento, remove o elemento da árvore 
int treeRemoveLine(Node **root, char *word, int line);

// Mostra todos os valores contidos na árvore
void treePrint(Node *root);

// Liberara memória de toda a árvore
void treeFree(Node *root);

/* Funções auxiliares a remoção de um elemento da árvore */
// Retorna o menor elemento da árvore
void treeMin(Node *root, Node **result);

#endif /* ARVOREBIN_H */
