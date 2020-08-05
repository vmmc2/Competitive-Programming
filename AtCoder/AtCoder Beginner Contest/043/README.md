# Explicacao para os problemas dificeis do contest

## Problema D
* Deve-se observar que se existir uma substring desbalanceada Y dentro da string X, entao essa substring Y tem tamanho 2 ou 3.
* Nao sei provar isso formalmente, mas da pra ter uma ideia intuitiva do porque isso ser verdade.
```
- Se a gente achar uma substring de tamanho 4 que seja unbalanced, pela definicao, isso quer dizer que ela tem 3 ocorrencias de um caractere especifico. Nao importa como a gente rearranje esses caracteres, em qualquer permutacao, 2 deles ficaram juntos. Ou seja, temos uma substring de tamanho 2 unbalanced dentro dessa substring de tamanho 4.
- O mesmo raciocinio eh valido para strings de tamanho 6, 8 ou qualquer outro numero par.
- Agora vendo isso para uma substring de tamanho impar, comecando com uma substring de tamanho 5. Supondo que ela seja unbalanced, entao ela tem 3 ocorrencias de um caracter especifico, qualquer que seja a permutacao desses caracteres, eh possivel encontrar uma substring de tamanho 3 unbalanced dentro dessa substring de tamanho 5. Isso vale para outras substrings de tamanho impar que sejam unbalanced.
```
