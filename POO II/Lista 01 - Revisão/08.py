aux = 1
while(True):
    num = int(input("Digite um Numero: "))
    if(num > 0 and num < 16):
        for i in range(2,num + 1):
            aux = aux * i 
        print("{}! = {}".format(num, aux))
    else:
        break
