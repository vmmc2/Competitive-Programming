numcasos = eval(input())
i = 0
while i < numcasos:
    frase = input()
    tamanho = len(frase)
    if tamanho > 10:
        inicio = frase[0]
        final = frase[-1]
        meio = int(len(frase)) - 2
        print(frase[0] + str(meio) + final)
    else:
        print(frase)
    i = i + 1
