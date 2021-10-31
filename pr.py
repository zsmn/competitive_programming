def buscaProximoPrimo(primos):
    ultimoPrimo = primos[len(primos)-1] + 1
    ehPrimo = False
    while not ehPrimo:
        verificado = primo(ultimoPrimo)
        if verificado:
            ehPrimo = True
        else:
            ultimoPrimo += 1
    primos.append(ultimoPrimo)
    

def primo(n):    
    if n <= 1:
        return False
    else: 
        primo = True        
        counter = 0
        while primos[counter] < int(n**0.5)+1:                 
                if n % primos[counter] == 0:
                    primo = False
                if counter + 1 > len(primos) - 1:
                    buscaProximoPrimo(primos)                    
                counter += 1
                    
        return primo
    

primos = [2,3,5,7,11] 
x = 1
while x != 0:
    x = int(input("--> "))
    print(primo(x))
