class Solution:
    def toGoatLatin(self, S: str) -> str:
        l = S.split(' ')
        words = []
        s = " "
        a = "a"
        
        counter = 1
        for word in l:
            if word[0] == 'a' or word[0] == 'e' or word[0] == 'i' or word[0] == 'o' or word[0] == 'u' or word[0] == 'A' or word[0] == 'E' or word[0] == 'I' or word[0] == 'O' or word[0] == 'U':
                newword = word + "ma" + ("a"*counter)
                words.append(newword)
            else:
                newword = word[1:] + word[0] + "ma" + ("a"*counter)
                words.append(newword)
            counter += 1
        
        return s.join(words)
