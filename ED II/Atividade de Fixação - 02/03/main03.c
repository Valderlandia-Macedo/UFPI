#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"


int main(int argc, char const *argv[])
{
	
	Node *arvore;
	treeInitialize(&arvore);
	//Criando um ponteiro do tipo arvore e inicializando por referencia;

	
	//Inserindo os valores da arvore;
	treeInsert(&arvore, 150,"Skinny","Jeans",34, 45,"Azul");
	treeInsert(&arvore, 100,"Pantacourt","Linho",44,46,"Vinho");
	treeInsert(&arvore, 180,"Flare","Sarja",38,47,"Caramelo");
	
	//Imprime na tela os valores do codigo e o modelo  
	treeShow(arvore);
	

	treeFree(arvore);
	return 0;
}