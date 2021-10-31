numero = int(input("Digite o número para saber sua raiz cúbica: "))
count = 1
a = 0
while count < numero**0.5:
    if count*count*count == numero:
        a = 1
        print("A raiz cúbica de",numero, "é",count)
    count += 1

if a == 1:
    pass

else:
    print("Não tem") 
