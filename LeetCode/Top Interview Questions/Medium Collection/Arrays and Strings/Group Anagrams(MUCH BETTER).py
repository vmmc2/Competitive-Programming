from collections import defaultdict

# A funcao ord() de python3 retorna o codigo da tabela ASCII de um char.

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        ans = defaultdict(list) # dicionario que mapeia para listas..
        for string in strs: # iterando sobre cada string
            count = [0]*26 # meu vetor de frequencia. Garantido que temos apenas letras minusculas na strings
            for c in string:
                count[ord(c) - ord('a')] += 1 # fazendo a contagem no vetor de frequencia
            ans[tuple(count)].append(string)
        return ans.values()
