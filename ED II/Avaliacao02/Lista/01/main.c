#include "arvoreBin.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Apelidando estrutura que armazenará a árvore
typedef struct unidade
{
	char unidadeNome[50];
	Node *tree;
}Unity;

// Mostra o menu e retorna a opção desejada
int mainMenu(int *opc);

// Inicializa as estruturas com o arquivo de texto passado por arquimento na execução do programa
void mainRead(Unity *unidades, int *contUnidades, const char *argv[]);

// Mostra todo o conteúdo armazedado nas unidades cadastradas
void unityMostrar(Unity *unidades, int contUnidades);

// Mostra todo o conteúdo armazenado em uma unidáde expecífica
void unityBuscar(Unity *unidades, int contUnidades, char *unidade);

// Busca a tradução de uma palavra em uma unidade expecífica
void unityBuscarTraducao(Unity *unidades, int contUnidades, char *palavra, char *modulo);

// Faz a remoção de uma palavra em uma unidade específica
void unityRemocaoPalavra(Unity *unidades, int contUnidades, char *palavra, char *modulo);

// libera a memória alocada para cada unidade
void unityLiberar(Unity *unidades, int contUnidades);



int main(int argc, char const *argv[])
{
	char auxPalavra[50];
	char auxModulo[50];

	Unity *unidades;
	unidades = (Unity *) malloc(sizeof(Unity));
	int contUnidades = 0;

	mainRead(unidades, &contUnidades, argv);


	int opc = 1;
	while(mainMenu(&opc))
	{
		switch (opc)
		{
		case 1:
			unityMostrar(unidades, contUnidades);
			break;
		case 2:
			printf("Digite a unidade que quer mostrar:\n");
			scanf("%s", auxModulo);
			unityBuscar(unidades, contUnidades, auxModulo);
			break;
		
		case 3:
			printf("Digite a palavra que quer buscar:\n");
			scanf("%s", auxPalavra);
			printf("Digite o módulo onde quer procurar:\n");
			scanf("%s", auxModulo);
			unityBuscarTraducao(unidades, contUnidades, auxPalavra, auxModulo);
			break;
		
		case 4:
			printf("Digite a palavra que quer remover:\n");
			scanf("%s", auxPalavra);
			printf("Digite o módulo onde quer remover:\n");
			scanf("%s", auxModulo);
			unityRemocaoPalavra(unidades, contUnidades, auxPalavra, auxModulo);
			break;
		default:
			break;
		}
	}

	unityLiberar(unidades, contUnidades);
	return 0;
}


int mainMenu(int *opc)
{
	printf("MENU\n");
	printf("[1] - Mostrar Todas as Unidades\n");
	printf("[2] - Buscar Unidade\n");
	printf("[3] - Buscar tradução de uma palavra\n");
	printf("[4] - Remover uma Palavra de uma Unidade\n");
	printf("[0] - Sair\n");
	scanf("%d", opc);
	return (*opc);
}


void unityMostrar(Unity *unidades, int contUnidades)
{
	for(int i = 0; i < contUnidades; i++)
	{
		printf("\nUnidade: %s\n", unidades[i].unidadeNome);
		treePrint(unidades[i].tree);
	}
}

void unityBuscar(Unity *unidades, int contUnidades, char *modulo)
{
	int i = 0;
	for(i = 0; i < contUnidades && strcpy(unidades[i].unidadeNome, modulo) == 0; i++);

	if( i == contUnidades)
	{
		printf("Módulo não encontrado!\n");
	}
	else
	{
		treePrint(unidades[i].tree);
	}
}

void unityBuscarTraducao(Unity *unidades, int contUnidades, char *palavra, char *modulo)
{
	int i = 0;
	for(i = 0; i < contUnidades && strcpy(unidades[i].unidadeNome, modulo) == 0; i++);

	if( i == contUnidades)
	{
		printf("Módulo não encontrado!\n");
	}
	else
	{
		Node *busca;
		treeSearch(unidades[i].tree, palavra, &busca);
		if(!busca)
		{
			printf("Palavra não encontrada!\n");
		}
	}
}

void unityRemocaoPalavra(Unity *unidades, int contUnidades, char *palavra, char *modulo)
{
	int i = 0;
	for(i = 0; i < contUnidades && strcpy(unidades[i].unidadeNome, modulo) == 0; i++);

	if( i == contUnidades)
	{
		printf("Módulo não encontrado!\n");
	}
	else
	{
		Node *busca;
		treeSearch(unidades[i].tree, palavra, &busca);
		if(!busca)
		{
			printf("Palavra não encontrada!\n");
		}
		else
		{
			treeRemove(&unidades[i].tree, palavra);
		}
	}
}

void unityLiberar(Unity *unidades, int contUnidades)
{
	for(int i = 0; i < contUnidades; i++)
	{
		treeFree(unidades[i].tree);
	}
	free(unidades);
}

void mainRead(Unity *unidades, int *contUnidades, const char *argv[])
{
	char linha[255];
	char auxNome[50];
	char auxPortugues[50];
	char auxIngles[50];
	FILE *fPtr;
	fPtr = fopen(argv[1], "r");

	while(fscanf(fPtr, "%s", linha) != EOF)
	{
		if(linha[0] == '%')	
		{
			*contUnidades += 1;
			unidades = (Unity *) realloc(unidades, (*contUnidades));
			treeInitialize(&(unidades[(*contUnidades) - 1].tree));


			int j = 0;
			for(int i = 1; linha[i] != '\0'; i++)
			{
				auxNome[j++] = linha[i];
			}
			auxNome[j] = '\0';
			strcpy(unidades[(*contUnidades) - 1].unidadeNome, auxNome);

		}
		else
		{
			int i;
			int j = 0;

			for(i = 0; linha[i] != ':'; i++)
			{
				auxIngles[j++] = linha[i];
			}
			auxIngles[j] = '\0';


			j = 0;
			for(i = i + 1; linha[i - 1] != '\0'; i++)
			{
				if(linha[i] != ',' && linha[i] != '\0')
				{
					auxPortugues[j++] = linha[i];
				}
				else
				{
					auxPortugues[j] = '\0';
					j = 0;
					treeInsert(&(unidades[(*contUnidades) - 1].tree), auxPortugues, auxIngles);
				}
			}
		}
	}
	fclose(fPtr);
}