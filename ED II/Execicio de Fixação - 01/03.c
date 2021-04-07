#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *MaiorStr(char mat[][20],int tam);
void QtdVogal(char mat[][20],int tam, int *cont);
void Maior4Maiusc(char vet[][20], char aux[][20],int tam, int *cont);

int main()
{
    char mat[3][20];
    for (int i = 0; i < 3; i++)
    {
        printf("String: ");
        scanf("%s",mat[i]);
    }
    printf("\n");
    printf("Maior: %s\n",MaiorStr(mat,3));
    
    int cont = 0;
    QtdVogal(mat,3,&cont);
    printf("Quantidade de Palavras que iniciam com vogal: %d\n",cont);

    char mat2[3][20];
    int cont2 = 0;
    Maior4Maiusc(mat,mat2,3,&cont2);
    for (int i = 0; i < cont2; i++)
        printf("Palavras maior que 4, que iniciam com letra Maiuscula: %s\n",mat2[i]);
}

char *MaiorStr(char mat[][20],int tam)
{
    char aux[20];
    char *paux;

    paux = aux;
    if(tam > 0)
    {
        strcpy(aux, MaiorStr(mat,tam-1));
        if (strlen(aux) < strlen(mat[tam-1])) 
            strcpy(aux, mat[tam-1]);
    }
    return paux;
}

void QtdVogal(char mat[][20],int tam,int *cont)
{
    if (tam > 0)
    {
        if (mat[tam-1][0] == 'a'||mat[tam-1][0] == 'A'|| mat[tam-1][0] == 'e' || mat[tam-1][0] == 'E' || mat[tam-1][0] == 'i' || mat[tam-1][0] == 'I' || mat[tam-1][0] == 'o' || mat[tam-1][0] == 'O' || mat[tam-1][0] == 'u' || mat[tam-1][0] == 'U')
            *cont = *cont + 1;
        QtdVogal(mat,tam-1,cont);
    }    
}

void Maior4Maiusc(char vet[][20], char aux[][20],int tam, int *cont)
{
    if(tam > 0)
    {
        if(vet[tam-1][0] > 64 && vet[tam-1][0] < 91 && strlen(vet[tam-1]) >= 4)
        {
            strcpy(aux[*cont], vet[tam-1]);
            *cont = *cont + 1;
        }
        Maior4Maiusc(vet,aux,tam-1,cont);
    }
}