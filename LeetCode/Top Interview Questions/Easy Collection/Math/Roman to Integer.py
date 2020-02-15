class Solution:
    def romanToInt(self, s: str) -> int:
        dicio = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        tam = len(s)
        number = 0
        if tam == 1:
            return dicio[s[0]]
        else:
            i = 0
            while i <= tam - 1:
                if s[i] == 'I':
                    if i < tam - 1:
                        if s[i + 1] == 'V':
                            number += 4
                            i += 1
                        elif s[i + 1] == 'X':
                            number += 9
                            i += 1
                        else:
                            number += 1
                    else:
                        number += 1
                elif s[i] == 'V':
                    number += 5
                elif s[i] == 'X':
                    if i != tam - 1:
                        if s[i + 1] == 'L':
                            number += 40
                            i += 1
                        elif s[i + 1] == 'C':
                            number += 90
                            i += 1
                        else:
                            number += 10
                    else:
                        number += 10
                elif s[i] == 'L':
                    number += 50
                elif s[i] == 'C':
                    if i != tam - 1:
                        if s[i + 1] == 'D':
                            number += 400
                            i += 1
                        elif s[i + 1] == 'M':
                            number += 900
                            i += 1
                        else:
                            number += 100
                    else:
                        number += 100
                elif s[i] == 'D':
                    number += 500
                elif s[i] == 'M':
                    number += 1000
                i += 1
            return number
            
