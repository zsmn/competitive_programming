def strings2Tamanho(lista):
    if len(lista) == 1:
        return [len(lista[0])]
    elif len(lista) < 1:
        return [0]
    else:
        a = [len(lista[0])]
        lista.remove(lista[0])        
        return a + strings2Tamanho(lista)

print(strings2Tamanho([]))
