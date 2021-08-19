#include "arvore23.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	Node *raiz;
	char *promove;
	Text **promoveT = malloc(sizeof(Text *));
	treeInitialize(&raiz);
	treeInsert(&raiz, "fazticeira", "witchcraft", promove, promoveT, NULL);
	treeInsert(&raiz, "dragão", "dragon", promove, promoveT, NULL);
	treeInsert(&raiz, "lindo", "beautiful", promove, promoveT, NULL);
	treeInsert(&raiz, "linda", "beautiful", promove, promoveT, NULL);
	treeInsert(&raiz, "bela", "beautiful", promove, promoveT, NULL);
	treeInsert(&raiz, "bonito", "beautiful", promove, promoveT, NULL);
	treeInsert(&raiz, "programa", "software", promove, promoveT, NULL);
	treeInsert(&raiz, "aplicativo", "software", promove, promoveT, NULL);

	treePrint(raiz);
	treeFree(raiz);

	return 0;
}
