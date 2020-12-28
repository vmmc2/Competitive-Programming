class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        d = {}
        morse = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
        for word in words:
            s = ""
            for i in range(0, len(word)):
                s += morse[ord(word[i]) - ord('a')]
            if s not in d:
                d[s] = 1
        return len(d)
            
