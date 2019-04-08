palavra = str(input())
resposta = []
analise = ['h','e','l','l','o']
i = 0
h = 0
e = 0
l = 0
o = 0
while i < len(palavra):
    if palavra[i] == 'h':
        if h == 0:
            resposta.append(palavra[i])
            h += 1
    if palavra[i] == 'e' and h > 0:
        if e == 0:
            resposta.append(palavra[i])
            e += 1
    if palavra[i] == 'l' and h > 0 and e > 0:
        if l < 2:
            resposta.append(palavra[i])
            l += 1
    if palavra[i] == 'o' and h > 0 and e > 0 and l >= 2:
            resposta.append(palavra[i])
            break
    i += 1
if resposta == analise:
    print("YES")
else:
    print("NO")
