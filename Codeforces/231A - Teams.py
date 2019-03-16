numcasos = eval(input())
problems = 0
i = 0
while i < numcasos:
    count = 0 # a cada caso tenho que ver se eu posso resolver 2 ou mais problemas
    string = input()
    if string[0] == '1':
        count = count + 1 
    if string[2] == '1':
        count = count + 1
    if string[4] == '1':
        count = count + 1 
    if count >= 2:
        problems = problems + 1
    i = i + 1
print(problems)
