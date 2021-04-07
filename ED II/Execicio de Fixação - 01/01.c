#include <stdio.h>
#include <stdlib.h>

void altera1(int **p, int *a)
{ 
	**p = *a;
	*a = *a +50;
}

void altera2(int **p, int *b)
{   
	*p = b;
	*b = *b +30;
}

int main()
{
	int x,y;
	int *px, *py;

	x = 10;
	y = x + 20;
	
	px = &x;
	py = &y;


	printf("x = %d, End. x = %p, px = %p, y = %d \n",x,&x, px,y);
	altera1(&px, &y);
	printf("x = %d, End. x = %p, px = %p, y = %d \n",x,&x, px,y);
	getchar();

	printf("y = %d, End. y = %p, py = %p, x = %d \n",y,&y, py,x);
	altera2(&py, &x);
	printf("y = %d, End. y = %p, py = %p, x = %d \n",y,&y, py,x);
	getchar();

return(0);
}

/*  
-----------------------------------------------------------------------------
01 - 
	(a) Qual a diferença entre px e x?
		
		px = É um ponteiro do tipo inteiro, que aponta para o endereço 
		de memoria da variavel x;
		x = É uma variavel do tipo inteiro que recebe como valor 10;

	(b) Qual a diferença entre px e py?

		px = aponta para o endereço da variavel X;
		py = aponta para o endereço da variavel y;

	(c) Quais são os valores impressos pelo primeiro printf?
	
		x = 10, End. x = 0x7fffc7145c60, px = 0x7fffc7145c60, y = 30
	
	(d) O que muda do primeiro printf para o segundo?

		O valor de x, e consequentemente o valor de y já que neste caso 
		y = x + 20. Após a função altera1 esses valores foram alterados 
		Obtendo o seguinte resultado:
		x = 30, End. x = 0x7fffc7145c60, px = 0x7fffc7145c60, y = 80

	(e) Quais os valores impressos pelo terceiro print?
	
		y = 80, End. y = 0x7fffc7145c64, py = 0x7fffc7145c64, x = 30
		(f) O que muda do terceiro para o quarto print?	
		O valor de x é alterado, e py deixa de apontar para o endereço 
		de y e passar a apontar para o endereço de x
		Obtendo o seguinte resultado:
		y = 80, End. y = 0x7fffc7145c64, py = 0x7fffc7145c60, x = 60

	(g) Explique a diferença entre o altera1 e o altera2
		Na função altera1, recebe por parâmentro o endereço de px e o endereço
		de y onde ela altera o valor armazenado no endereço dessa variavel. 
		Enquanto na função altera2 recebe o endereço de py e o endereço de x.

-----------------------------------------------------------------------------
*/