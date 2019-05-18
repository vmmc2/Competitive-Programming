string = str(input())
newstring = ''
i = 0
tudoupper = 0
contadorupper = 0

while i < len(string):
    if string[i].isupper() == True:
        contadorupper += 1
    i += 1
if contadorupper == len(string):
    print(string.lower())

elif string[0].islower() == True and contadorupper == len(string) - 1:
    newstring += string[0].upper()
    newstring += string[1:].lower()
    print(newstring)
else:
    print(string)
