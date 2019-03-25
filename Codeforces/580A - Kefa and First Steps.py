tamanho = eval(input())
entrada = map(int, input().split())
dp = list(entrada)
resposta = 0
contador = 0
for i in range(0, tamanho):
    if i > 0:
        if dp[i] >= dp[i-1]:
            contador += 1
        else:
            resposta = max(resposta, contador)
            contador = 0
resposta = max(resposta, contador)
print(resposta + 1)
