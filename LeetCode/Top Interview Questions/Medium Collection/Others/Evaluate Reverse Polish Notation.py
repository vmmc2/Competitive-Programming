class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        tam = len(tokens)
        stack = []
        for i in range(0, tam):
            if tokens[i] != '+' and tokens[i] != '-' and tokens[i] != '/' and tokens[i] != '*':
                stack.append(int(tokens[i]))
            else:
                v1 = stack[-2]
                v2 = stack[-1]
                stack.pop()
                stack.pop()
                if tokens[i] == '+':
                    stack.append(v1 + v2)
                elif tokens[i] == '-':
                    stack.append(v1 - v2)
                elif tokens[i] == '*':
                    stack.append(v1 * v2)
                else:
                    if (v1 > 0 and v2 > 0) or (v1 < 0 and v2 < 0):
                        stack.append(v1 // v2)
                    else:
                        result = abs(v1) // abs(v2)
                        result = result * (-1)
                        stack.append(result)
        return stack[0]
