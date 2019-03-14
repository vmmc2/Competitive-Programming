string = input() # a entrada vai ficar armazenada na variavel string
string = string.lower() # converte a string para tudo minusculo
answer = ""
for element in string: # para cada elemento presente em string
    if element != 'a' and element != 'e' and element != 'i' and element != 'o' and element != 'u' and element != 'y':
        answer = answer + "." + element
print(answer)
