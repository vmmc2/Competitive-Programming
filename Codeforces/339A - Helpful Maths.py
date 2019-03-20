expressao = input()
answer = []
for element in expressao:
  if element != '+':
    answer.append(int(element))
answer.sort()
i = 0
final = ""
while i < len(answer):
  if i < len(answer) - 1:
    final += str(answer[i])
    final += "+"
  else:
    final += str(answer[i])
  i = i + 1
print(final)
