def compress(s1: str) -> str:
    s2 = []
    index = 0
    tam = len(s1)
    counter = 1
    while index <= tam - 1:
        if index > 0:
            if index == tam - 1:
                if s1[index] == s1[index - 1]:
                    counter += 1
                    s2.append(s1[index] + str(counter))
                else:
                    s2.append(s1[index - 1] + str(counter))
                    s2.append(s1[index] + '1')
                break
            if s1[index] == s1[index - 1]:
                counter += 1
            elif s1[index] != s1[index - 1]:
                s2.append(s1[index - 1] + str(counter))
                counter = 1
        index += 1
    return "".join(s2)
        

def main():
    s1 = "aaaaabc"
    compressed = compress(s1)
    if len(compressed) >= len(s1):
        print(s1)
    else:
        print(compressed)
        
main()
