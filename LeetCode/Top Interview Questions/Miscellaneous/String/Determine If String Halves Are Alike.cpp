class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        answer = True
        n = len(s)
        a = s[0:n//2]
        b = s[n//2:]
        vowels = "aeiouAEIOU"
        da = {}
        db = {}
        
        for i in range(0, len(a)):
            if a[i] not in da:
                da[a[i]] = 1
            else:
                da[a[i]] += 1
        for i in range(0, len(b)):
            if b[i] not in db:
                db[b[i]] = 1
            else:
                db[b[i]] += 1
        ca = 0
        cb = 0
        for letter in vowels:
            if letter in da:
                ca += da[letter]
            if letter in db:
                cb += db[letter]
        if ca != cb:
            answer = False
        
        return answer
