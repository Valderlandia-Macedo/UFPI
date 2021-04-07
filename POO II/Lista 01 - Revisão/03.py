ValorH = float(input('Valor por Horas = '))
Horas = float(input('Horas Trabalhadas = '))

Salario = ValorH * Horas
Ir = (Salario * 1.11) - Salario
Inss = (Salario * 1.08) - Salario
Sindicato = (Salario * 1.05) - Salario
SalarioL = Salario - Ir - Inss - Sindicato 

print('+ Salário Bruto = R$ {}'.format(Salario))
print('- IR (11%) = R$ {}'.format(Ir))
print('- INSS (8%) = R$ {}'.format(Inss))
print('- Sindicato (5%) = R$ {}'.format(Sindicato))
print('= Salário Liquido = R$ {}'.format(SalarioL))

