lixo = int(input())
stones = str(input())
i = 0
count = 0
while i < len(stones) - 1:
    if(stones[i] == stones[i+1]):
        count += 1
    i += 1
print(count)
