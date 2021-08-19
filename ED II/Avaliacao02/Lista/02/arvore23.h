/* TAD: arvore 2-3 */

#ifndef ARVORE23_H
#define ARVORE23_H

/* Dependencia de módulos: */
#include "listaEng.h"

// Apelidando árvore
typedef struct no Node;

// Inicializar a arvore
void treeInitialize(Node **root);

// Recebe uma árvore e um valor e, se encontrado, retorna o nó em que o elemento se encontra, caso contrário: retorna NULL
void treeSearch(Node *root, char *wordKey, Node **result);

// Mostra todos os valores contidos na árvore
void treePrint(Node *root);

// Liberara memória de toda a árvore
void treeFree(Node *root);

// Recebe uma árvore e um valor e o adiciona na arvore
Node *treeInsert(Node **root, char *word, char *wordEnglish, char *promove, Text **promoveEnglish, Node **father);

/* Funções auxiliares na inserção e balanceamemto dos elementos na árvore */
// Recebe um valor e adiciona num nó já existente além de poder adicionar seu filho ao mesmo
void treeUpdateNode(Node **root, char *word, Text *wordEnglish, Node *child);

// Recebe um valor e cria um novo nó com eles além de poder adicionar seu filhos ao mesmo
Node *treeCreateNode(char *word, Text *wordEnglish, Node *childLeft, Node *childCenter, Node *childRight);

// recebe uma árvore e retorna 1 se não tiver filhos, caso contrário, retorna 0
int treeIsLeaf(Node *root);

// Recebe uma árvore e um valor e retorna essa árvore dividida em 2 
Node *treeBreakingNode(Node **root, char *word, Text *listEnglish, char *promove, Text **promoveEnglish, Node *child);


#endif /* ARVORE23_H */
