#include<stdio.h>
#include<stdlib.h>

int Mdc1(int x, int y, int *result);
int Mdc2(int num, int resto);
    
int main(int argc, char const *argv[])
{
    int vet[4];
    for (int i = 0; i < 4; i++)
        scanf("%d",&vet[i]);
    
    int result;

    Mdc1(vet[0],vet[1],&result);
    Mdc1(vet[2],result,&result);
    Mdc1(vet[3],result,&result);
    printf("%d",result);

    result = Mdc2(vet[0],Mdc2(vet[1],Mdc2(vet[2],vet[3])));
    printf("%d",result);
    return 0;
}

int Mdc1(int x, int y, int *result)
{
    if (x > y)
        if (x % y == 0)
            *result = y;
        else
            Mdc1(y, x % y, result);
    else
        Mdc1(y, x, result);
}

int Mdc2(int num, int resto)
{
    int result;
    if(num > resto)
    {
        if (num % resto == 0)
            result = resto;
        else
            result = Mdc2(resto, num % resto);
    }
    else
        result = Mdc2(resto, num);
    return result;
}