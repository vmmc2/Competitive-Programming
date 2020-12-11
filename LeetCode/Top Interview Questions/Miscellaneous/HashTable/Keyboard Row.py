class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        answer = []
        firstRow = {
            'q' : 1,
            'Q' : 1,
            'w' : 1,
            'W' : 1,
            'e' : 1,
            'E' : 1,
            'r' : 1,
            't' : 1,
            'T' : 1,
            'y' : 1,
            'Y' : 1,
            'u' : 1,
            'U' : 1,
            'i' : 1,
            'I' : 1,
            'o' : 1,
            'O' : 1,
            'p' : 1,
            'P' : 1,
        }
        secondRow = {
            'a' : 1,
            'A' : 1,
            's' : 1,
            'S' : 1,
            'd' : 1,
            'D' : 1,
            'f' : 1,
            'F' : 1,
            'g' : 1,
            'G' : 1,
            'h' : 1,
            'H' : 1,
            'j' : 1,
            'J' : 1,
            'k' : 1,
            'K' : 1,
            'l' : 1,
            'L' : 1,
        }
        thirdRow = {
            'z' : 1,
            'Z' : 1,
            'x' : 1,
            'X' : 1,
            'c' : 1,
            'C' : 1,
            'v' : 1,
            'V' : 1,
            'b' : 1,
            'B' : 1,
            'n' : 1,
            'N' : 1,
            'm' : 1,
            'M' : 1,
        }
        for element in words:
            ok = True
            fRow = 0
            sRow = 0
            tRow = 0
            for i in range(0, len(element)):
                if element[i] in firstRow:
                    fRow = 1
                elif element[i] in secondRow:
                    sRow = 1
                elif element[i] in thirdRow:
                    tRow = 1
            if fRow + sRow + tRow != 1:
                ok = False
            if ok == True:
                answer.append(element)
        return answer
        
