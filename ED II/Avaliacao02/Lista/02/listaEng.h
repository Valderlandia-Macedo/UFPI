/* TAD: lista encadeada */

#ifndef LISTAENG_H
#define LISTAENG_H

// Apelidando lista
typedef struct texto Text;

// Inicializar a lista
void listInitialize(Text **head);

// Recebe a linha e insere na cabeça  da lista
void listInsert(Text **head, char *string);

// Remove um elemento da lista que contenha a chave
void listRemove(Text **head, char *string);

// Recebe a lista e mostra todos os elementos
void listPrint(Text *head);

// Libera a memóriade toda a lista
void listFree(Text *head);

char *listWord(Text *head);
#endif /* LISTAENG_H */
