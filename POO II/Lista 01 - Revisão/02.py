Peso = float(input('Peso = '))
if(Peso > 50):
    Excesso = (Peso - 50)
    Multa = Excesso * 4
    print('Excesso de Peso = {} Kg'.format(Excesso))
    print('Valor da Multa = R$ {}'.format(Multa))
else:
    print('Não houve Excesso')