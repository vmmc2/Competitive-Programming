class Solution:
    def isHappy(self, n: int) -> bool:
        if n == 1:
            return True
        d = {}
        ok = True
        while ok:
            temp = 0
            d[n] = d.get(n, 0) + 1
            s = str(n) #converto o numero para string.
            for i in range(0, len(s)): #itero sobre os digitos e vou computando a nova soma.
                temp += (ord(s[i]) - ord('0'))**2
            n = temp
            if n == 1:
                break
            if n in d:
                ok = False
                break
        return ok
            
            
