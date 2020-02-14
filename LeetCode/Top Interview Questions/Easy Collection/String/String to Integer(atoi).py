class Solution:
    def myAtoi(self, string: str) -> int:
        #primeira coisa: verificar se a string eh vazia: ""
        if string == "":
            return 0
        #ate ai tudo beleza, vamo agr iterar sobre a string para ver se ela eh valida.
        valid = False #suponho que n eh uma string valida.
        sinal = ""
        newindex = -1
        number = ""
        stlen = len(string)
        for i in range(0, stlen):
            if string[i] != ' ':
                if string[i] != '+' and string[i] != '-' and string[i] != '0' and string[i] != '1' and string[i] != '2' and string[i] != '3' and string[i] != '4' and string[i] != '5' and string[i] != '6' and string[i] != '7' and string[i] != '8' and string[i] != '9':
                    return 0
                elif string[i] == '+':
                    if  len(string) > 1 and string[i + 1] != '0' and string[i + 1] != '1' and string[i + 1] != '2' and string[i + 1] != '3' and string[i + 1] != '4' and string[i + 1] != '5' and string[i + 1] != '6' and string[i + 1] != '7' and string[i + 1] != '8' and string[i + 1] != '9':
                        return 0
                    sinal = '+'
                    newindex = i + 1
                    break
                elif string[i] == '-':
                    if len(string) > 1 and string[i + 1] != '0' and string[i + 1] != '1' and string[i + 1] != '2' and string[i + 1] != '3' and string[i + 1] != '4' and string[i + 1] != '5' and string[i + 1] != '6' and string[i + 1] != '7' and string[i + 1] != '8' and string[i + 1] != '9':
                        return 0
                    sinal = '-'
                    newindex = i + 1
                    break
                elif string[i] == '0' or string[i] == '1' or string[i] == '2' or string[i] == '3' or string[i] == '4' or string[i] == '5' or string[i] == '6' or string[i] == '7' or string[i] == '8' or string[i] == '9':
                    newindex = i
                    break
        print(newindex)
        if newindex  == stlen or newindex == -1:
            return 0
        for i in range(newindex, stlen):
            if string[i] != '0' and string[i] != '1' and string[i] != '2' and string[i] != '3' and string[i] != '4' and string[i] != '5' and string[i] != '6' and string[i] != '7' and string[i] != '8' and string[i] != '9':
                break
            else:
                number = number + string[i]
        answer = int(number)
        if sinal == '-':
            answer = answer*(-1)
        if answer < -2147483648:
            return -2147483648
        if answer > 2147483647:
            return 2147483647
        return answer
                
