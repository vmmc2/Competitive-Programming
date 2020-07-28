class Solution:
    def trailingZeroes(self, n: int) -> int:
        # Explicacao: Perceba que se um numero tem 4 fatores 10 na sua composicao, entao ele tem 4 zeros no final. Se ele tem 1 fator 10 na sua composicao, entao ele tem 1 zero no final. Se ele nao tem fator 10 na sua composicao, entao ele nao tem zeros no final.
        exp = 1
        answer = 0
        ok = True
        while ok:
            zeros = n//(5**exp)
            if zeros == 0:
                break
            answer += zeros
            exp += 1
        return answer
