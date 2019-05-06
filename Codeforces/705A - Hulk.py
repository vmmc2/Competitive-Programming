num = eval(input())
it = "it"
answer = ""
if num == 1:
    print("I hate it")
else:
    i = 1
    while i <= num:
        if i % 2 != 0 and i == 1:
            answer += "I hate that"
        if i % 2 != 0 and i > 1 and i != num:
            answer += " I hate that"
        if i % 2 == 0 and i != num:
            answer += " I love that"
        if i % 2 != 0 and i == num:
            answer += " I hate it"
        if i % 2 == 0 and i == num:
            answer += " I love it"
        i += 1
print(answer)
