def separaString(string):
    string += " "
    listaPalavras = []
    listaSimbolos = []
    palavra = ""
    simbolos = [",",".",";","?",":"," "]
    for letra in string:
        if letra not in simbolos:
            palavra += letra
        else:
            listaSimbolos.append(letra)
            if palavra != "":
                listaPalavras.append(palavra)
                palavra = ""
    return listaPalavras,listaSimbolos
        
def retiraSubstring(lista,listaSimbolos,substring):
    count = 0
    for palavra in lista:          
        if palavra == substring:
            lista.remove(palavra)
            listaSimbolos.remove(listaSimbolos[count])
        else:            
            indice_da_letra = 0
            palavraFinal = ""
            parcial = ""
            for letra in palavra:              
                if letra == substring[indice_da_letra]: 
                    parcial += letra
                    if indice_da_letra + 1 < len(substring):
                        indice_da_letra += 1
                else:  
                    if parcial != substring:
                        palavraFinal += parcial
                    indice_da_letra = 0
                    parcial = ""
                    if letra == substring[0]:
                        parcial += letra
                        indice_da_letra += 1
                    else:
                        palavraFinal += letra
            
        if palavraFinal == "":
            lista.remove(palavra)
            listaSimbolos.remove(listaSimbolos[count])
        else:
            lista[count] = palavraFinal
        count += 1
            

def juntaString(lista,simbolos):
    texto = ""
    ordem = 0
    for palavra in lista:
        texto += palavra + simbolos[ordem]
        ordem += 1
    return texto
    
      
string = input("--> ")
substring = input("--> ")
lista,simbolos = separaString(string)
retiraSubstring(lista,simbolos,substring)
print(juntaString(lista,simbolos))
