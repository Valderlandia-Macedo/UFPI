#include <stdio.h>
#include <stdlib.h>

int Divisores(int num, int aux);

int main(int argc, char const *argv[])
{
    int num;
    printf("Numero = ");
    scanf("%d",&num);

    Divisores(num,1);
    return 0;
}

int Divisores(int num, int aux)
{
    if(aux <= num)
    {
        if(num % aux == 0)
            printf("%d ", aux);
        Divisores(num,aux+1);
    }
}