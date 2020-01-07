class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        resposta = []
        for i in range(1, n + 1):
            divisivel3 = False
            divisivel5 = False
            if i % 3 == 0:
                divisivel3 = True
            if i % 5 == 0:
                divisivel5 = True
            #Checando agr para ver que porra eu coloco na lista
            if divisivel3 == False and divisivel5 == False:
                resposta.append(str(i))
            elif divisivel3 == True and divisivel5 == False:
                resposta.append("Fizz")
            elif divisivel3 == False and divisivel5 == True:
                resposta.append("Buzz")
            elif divisivel3 == True and divisivel5 == True:
                resposta.append("FizzBuzz")
        return resposta
