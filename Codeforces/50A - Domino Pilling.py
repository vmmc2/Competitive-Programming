dominoarea = 2
linha, coluna  = input().split()
#convertendo de string para inteiro
linha = int(linha)
coluna = int(coluna)
#calculando a area do tabuleiro
area = linha*coluna
#resposta
dominos = area//dominoarea
print(dominos)
