class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if strs == []:
            return ""
        found = True
        prefix = ""
        base = ""
        #primeira parte: descobri quem eh a menor string presente
        maxprefixlen = 10000000000
        for element in strs:
            if len(element) < maxprefixlen:
                maxprefixlen = len(element)
                base = element
        #No caso em que eu tenho que a menor string presente na minha list tem tamamho 4.
        #eu tenho que iterar da seguinte forma: [0:1] -> [0:2] -> [0:3] -> [0:4]
        for i in range(1,maxprefixlen + 1):
            found = True
            for string in strs:
                if base[0:i] != string[0:i]:
                    found = False
                    break
            #quando eu itero por todo mundo. se found ainda estiver "True" quer dizer que esse prefixo ta presente
            #de boa.
            if found == False:
                break
            else:
                prefix = base[0:i]
        return prefix
        
