LitrosV = float(input('Litros Vendidos = '))
print('1. Álcool | 2. Gasolina')
opc = input('Tipo de Combustível: ')

if(opc == 1):
    if(LitrosV <= 20):
        Valor = (LitrosV * 1.03) - 3.45
    elif(LitrosV > 20)
         Valor = (LitrosV * 1.05) - 3.45
    print('Total = R$ {}'.format(Valor))
    
elif(opc == 2):
    if(LitrosV <= 20):
        Valor = (LitrosV * 1.04) - 4.53
    elif(LitrosV > 20)
         Valor = (LitrosV * 1.06) - 4.53
    print('Total = R$ {}'.format(Valor))