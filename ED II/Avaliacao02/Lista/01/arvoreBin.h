/* TAD: arvore binária */

#ifndef ARVOREBIN_H
#define ARVOREBIN_H

/* Dependencia de módulos: */
#include "listaEng.h"

// Apelidando árvore
typedef struct no Node;

// Inicializar a lista
void treeInitialize(Node **root);

// Recebe a palavra em portugues e inglês e insere arvore
void treeInsert(Node **root, char *word, char *wordEnglish);

// Recebe a palavra e busca a existencia na arvore
void treeSearch(Node *root, char *word, Node **result);

// Remove um elemento da árvore que contenha a palavra chave
void treeRemove(Node **root, char *word);

// Mostra todos os valores contidos na árvore
void treePrint(Node *root);

// Liberara memória de toda a árvore
void treeFree(Node *root);

/* Funções auxiliares a remoção de um elemento da árvore */
// Retorna o menor elemento da árvore
void treeMin(Node *root, Node **result);

#endif /* ARVOREBIN_H */
