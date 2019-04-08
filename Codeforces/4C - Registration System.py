hashtable = {}
requests = eval(input()) #numero de vezes que vai ter que rodar
for element in range(0,requests):
    name = input()
    if name in hashtable:
        hashtable[name] += 1
        print(name + str(hashtable[name]))
    else:
        hashtable[name] = 0
        print("OK")
        
