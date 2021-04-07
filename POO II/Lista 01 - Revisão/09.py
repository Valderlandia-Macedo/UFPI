Numero = int(input('Montar a tabuada de: '))
Inicio = int(input('Começar por: '))
Fim = int(input('Termina em: '))
print('Vou montar a tabuada de {} começando em {} e terminando em {}'.format(Numero,Inicio,Fim))
for i in range(Inicio,Fim + 1):
    print('{} X {} = {}'.format(Numero, i, Numero*i))
