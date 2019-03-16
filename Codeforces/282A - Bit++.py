numcomands = eval(input())
i = 1
x = 0
while i <= numcomands:
    comand = input()
    if comand == "X++" or comand == "++X":
        x = x + 1 
    else:
        x = x - 1 
    i = i + 1
print(x)
