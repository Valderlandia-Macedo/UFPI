num = int(input("Digite um Numero: "))
aux = 1
for i in range(2,num + 1):
    aux = aux * i 
print("{}! = {}".format(num, aux))