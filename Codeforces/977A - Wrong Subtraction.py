number, times = input().split(' ')
number = eval(number)
times = eval(times)
 
for element in range(0, times):
    if number % 10 == 0:
        number = number/10
    else:
        number = number - 1
print(int(number))  
