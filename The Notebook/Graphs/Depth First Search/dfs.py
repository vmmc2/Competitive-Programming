visited = []

def initializeVisited(numVertex):
    global visited 
    visited = [0 for i in range(0, numVertex)]
    return


def dfs(adjList, source):
    global visited 
    visited[source] = 1
    for i in range(0, len(adjList[source])):
        u = adjList[source][i]
        if visited[u] == 0:
            dfs(u)
    return


def main():
    numVertex = 100
    adjList = [[] for i in range(0, numVertex)]
    initializeVisited(numVertex)
    # ... put edges in the adjlist ...
    x = 10
    dfs(adjList, x)
    return


if __name__ == "__main__":
    main()
