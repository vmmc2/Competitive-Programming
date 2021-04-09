#include <bits/stdc++.h>
#include <sstream>

/*
Objetivo: Encontrar o diametro de uma arvore (tree)

* O que eh o diametro de uma arvore? Eh a maior distancia entre dois
vertices quaisquer presentes nessa arvore (tree).

1) Solucao Naive
-- Para cada vertice da arvore, roda uma dfs a partir dele e guardar o vertice
mais distante da origem e qual eh essa distancia.
-- Vai atualizando o valor dessa variavel a medida que for necessario.
-- Complexidade: O(V*(V + E))

2) Solucao Otima
-- Escolhe um vertice qualquer da arvore e roda uma dfs a partir dele.
-- Pega o vertice que ta mais longe desse primeiro vertice e guarda ele.
-- Roda uma segunda dfs a partir desse segundo vertice. O vertice que estiver
mais longe dessa segunda origem e sua respectiva distancia eh o diametro da arvore.
-- Complexidade: O(V + E)
*/

using namespace std;

void dfs(int source, vector<vector<int>> &adjlist, vector<bool> &visited, vector<int> &dist){
    
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    

    return 0;
}
