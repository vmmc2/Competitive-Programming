dictionary = {"red" : "Reality", "purple" : "Power", "green" : "Time", "blue" : "Space", "orange" : "Soul", "yellow" : "Mind"}
registro = {"red" : 0, "purple" : 0, "green" : 0, "blue" : 0, "orange" : 0, "yellow" : 0}
numgems = int(input())
i = 1 
count = 0
answer = []
while i <= numgems:
    present = str(input())
    registro[present] = 1
    i = i + 1
for element in registro:
    if(registro[element] == 0):
        count = count + 1
        answer.append(dictionary[element])
print(count)
for elemento in answer:
    print(elemento)
