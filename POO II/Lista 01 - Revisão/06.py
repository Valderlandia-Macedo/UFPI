def Potencia(Base,Expoente):
    if (Expoente == 1):
        return Base
    if (Expoente == 0):
        return 1
    else:
        return(Potencia(Base,Expoente-1)*Base)

Base = int(input('Base = '))
Expoente = int(input('Expoente = '))
Resultado = Potencia(Base, Expoente)
print('{}'.format(Resultado))