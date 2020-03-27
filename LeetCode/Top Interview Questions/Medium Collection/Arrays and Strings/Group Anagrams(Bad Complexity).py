from collections import defaultdict

def check_anagram(str1: str, str2: str) -> bool:
    dict1 = defaultdict(int)
    dict2 = defaultdict(int)
    if len(str1) != len(str2):
        return False
    else:
        for i in range(0, len(str1)):
            dict1[str1[i]] += 1
        for i in range(0, len(str2)):
            dict2[str2[i]] += 1
        #hora de fazer a checagem pra ver se as string sao anagramas.
        for k,v in dict1.items():
            if k in dict2:
                if dict1[k] != dict2[k]:
                    return False
            else:
                return False
        return True

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        groups = []
        tam = len(strs)
        for i in range(0, tam):
            if(len(groups)) == 0:
                groups.append([strs[i]]) # Primeiro caso, no qual eu ainda n processei nenhuma string
            else:
                flag = 0 #flag q indica q a string n pertence a nenhum grupo de anagramas.
                for j in range(0, len(groups)):
                    if check_anagram(groups[j][0], strs[i]) == True: #fazendo a checagem se eh anagrama
                        groups[j].append(strs[i])
                        flag = 1
                if flag == 0:
                    groups.append([strs[i]]) #crio um novo grupo de anagramas.
        return groups
