#include <bits/stdc++.h>
#include <sstream>

//Da para usar o conceito de in/out para resolver o seguinte problema: Dada uma arvore com uma certa raiz e dados dois vertices A e B. Cheque se A ta na sub-arvore de B ou se B
//ta na sub-arvore de A.
//Para isso, a gente monta os vetores "in" e "out" dos vertices, rodando uma dfs a partir da raiz da arvore. O vetor "in" indica o instante em que a dfs em um vertice especifico
//comecou a ser executada. O vetor "out" indica o instante especifico em que a execucao da dfs em um vertice especifico foi finalizada.
//Para que B esteja na sub-arvore de A devemos ter que: in[A] < in[B] e out[A] > out[B].

using namespace std;

int time = 1;

void dfs(int source, vector<vector<int>> &adjlist, vector<bool> &visited, vector<int> &in, vector<int> &out){
    visited[source] = true;
    in[source] = time++;
    for(int i = 0; i < (int)adjlist[source].size(); i++){
        int u = adjlist[source][i];
        if(visited[u] == false){
            dfs(u, adjlist, visited, in, out);
        }
    }
    out[source] = time++;
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    int numVertex = 18;
    int numEdges = 12;
    vector<vector<int>> adjlist(numVertex, vector<int>());
    vector<bool> visited(numVertex, false);
    vector<int> in(numVertex);
    vector<int> out(numVertex);

    for(int i = 0; i < numEdges; i++){
        cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    dfs(0, adjlist, visited, in, out);
    

    return 0;
}
