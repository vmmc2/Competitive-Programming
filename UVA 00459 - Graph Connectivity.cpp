#include <bits/stdc++.h>

using namespace std;

vector <int> adjlist[50];
int componentes;
int visitados[50];

void dfs(int u){
    visitados[u] = 1;
    for(int j = 0; j < (int)adjlist[u].size(); j++){
        int v = adjlist[u][j];
        if(visitados[v] == 0){
            dfs(v);
        }
    }
}

int main(){
    string str;
    int numcasos, vertices;
    char caractere;
    scanf("%d", &numcasos);
    while(numcasos--){
        cin >> caractere;
        vertices = caractere - 'A' + 1;
        cin.ignore();//Ignora a linha vazia presente entre o numero de casos e os vertices
        while(getline(cin,str) && str != ""){
            //montando as arestas do grafo
            adjlist[str[0] - 'A'].push_back(str[1] - 'A');
            adjlist[str[1] - 'A'].push_back(str[0] - 'A');
        }
        //Chamando a dfs para cada um dos vertices do meu grafo
        for(int i = 0; i < vertices; i++){
            if(visitados[i] == 0){
                componentes++;//Se o vertice nao foi visitado, quer dizer que ele está em uma outra componente conexa do meu grafo.
                dfs(i);
            }
        }
        cout << componentes << endl;
        if(numcasos){//Tem que deixar uma linha vazia entre duas instancias do problema.
            cout << endl;
        }
        //resetando tudao apos processar um caso
        componentes = 0;
        for(int i = 0; i < 50; i++){
            adjlist[i].clear();
        }
        for(int i = 0; i < 50; i++){
            visitados[i] = 0;
        }
    }
    
    return 0;
}
