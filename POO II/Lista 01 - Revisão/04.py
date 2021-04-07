ladoA = float(input('Lado A: '))
ladoB = float(input('Lado B: '))
ladoC = float(input('Lado C: '))

if(ladoA == ladoB and ladoA == ladoC):
    print('Triângulo Equilátero')
elif(ladoA == ladoB or ladoA == ladoC or ladoB == ladoC):
    print('Triângulo Isosceles')
elif(ladoA != ladoB and ladoA != ladoC and ladoB != ladoC):
    print('Triângulo Escaleno')
elif(ladoC > (ladoA + ladoB) or ladoA > (ladoB + ladoC) or ladoB > (ladoA + ladoC)):
    print("Não é um Triângulo")
