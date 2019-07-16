flag = 1 #assumo que eh um ciclo
def bfs(partida):
    visited[partida] = 1 
    queue = []
    queue.append(partida)
    while queue:
        vertex = queue.pop()
        if len(graph[vertex]) != 2:
            global flag
            flag = 0
        for i in graph[vertex]:
            if visited[i] == 0:
                visited[i] = 1 
                queue.append(i)
    
numvertices, numedges = map(int, input().split())
cycles = 0
graph = [[] for n in range(numvertices + 1)]
visited = [0]*(numvertices + 1)
for element in range(numedges):
    partida, chegada = map(int, input().split())
    graph[partida].append(chegada)
    graph[chegada].append(partida)
 
for element in range(1, numvertices + 1):
    flag = 1
    if visited[element] == 0:
        bfs(element)
        if flag == 1:
            cycles += 1
print(cycles)
