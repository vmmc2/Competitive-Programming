string = input()
if len(string) < 7:
    print("NO")
else:
    if(string.find("1111111") != -1 or string.find("0000000") != -1):
        print("YES")
    else:
        print("NO")
