luckynumbers = [4,7,44,47,74,77,444,447,474,477,744,747,774,777]
number = eval(input())
flag = 0 #suponho que não é divisível por nenhum luckynumbers
for element in luckynumbers:
    if number % element == 0:
        flag = 1 
if flag == 1:
    print("YES")
else:
    print("NO")
