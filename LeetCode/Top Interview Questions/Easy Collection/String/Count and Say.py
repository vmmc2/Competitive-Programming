class Solution:
    def countAndSay(self, n: int) -> str:
        terms = ['1']
        counter = 0
        if n == 1:
            return '1'
        for i in range(0, n-1):
            davez = terms[i]
            tam = len(davez)
            counter = 0
            letra = terms[i][0]
            newstring = ""
            for j in range(0, tam):
                if davez[j] == letra:
                    counter += 1
                elif davez[j] != letra:
                    newstring = newstring + str(counter)
                    newstring = newstring + letra
                    letra = davez[j]
                    counter = 1
            newstring = newstring + str(counter)
            newstring = newstring + letra
            terms.append(newstring)
        print(terms)
        return terms[-1]
            
