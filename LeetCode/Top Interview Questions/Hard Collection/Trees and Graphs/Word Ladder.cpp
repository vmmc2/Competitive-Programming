#include <unordered_map>

class Solution {
public:
    bool isEdge(string s1, string s2){
        if((int)s1.length() != (int)s2.length()) return false;
        int diff = 0;
        for(int i = 0; i < (int)s1.length(); i++){
            if(s1[i] != s2[i]) diff++;
        }
        if(diff == 1) return true;
        return false;
    }
    void bfs(int source, vector<int> &dist, vector<vector<int>> &adjlist, vector<int> &visited){
        dist[source] = 0;
        visited[source] = 1;
        queue<int> fila;
        fila.push(source);
        while(!fila.empty()){
            int x = fila.front();
            fila.pop();
            for(int i = 0; i < (int)adjlist[x].size(); i++){
                int v = adjlist[x][i];
                if(visited[v] == 0){
                    visited[v] = 1;
                    dist[v] = 1 + dist[x];
                    fila.push(v);
                }
            }
        }
        return;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //primeiro passo: verificar se "endword" ta presente em "wordlist"
        int present = 0; //suponho que nao ta presente
        int n = (int)wordList.size();
        for(int a = 0; a < n; a++){
            if(endWord == wordList[a]) present = 1;
        }
        if(present == 0) return 0;
        
        //agr tem que tratar os outros casos...
        //associando cada string a um numero/vertice do meu futuro grafo.
        unordered_map<string,int> mapa;
        mapa[beginWord] = 0;
        vector<vector<int>> adjlist;
        vector<int> dist;
        vector<int> visited;
        dist.resize(n + 1, 10000000);
        visited.resize(n + 1, 0);
        adjlist.resize(n + 1);
        int sentinel = 1;
        for(int a = 0; a < n; a++, sentinel++){
            mapa[wordList[a]] = sentinel;
        }
        //montagem do grafo...
        int i, j;
        for(i = 0; i < n - 1; i++){
            for(j = i + 1; j < n; j++){
                if(isEdge(wordList[i], wordList[j])){
                    adjlist[mapa[wordList[i]]].push_back(mapa[wordList[j]]);
                    adjlist[mapa[wordList[j]]].push_back(mapa[wordList[i]]);
                }
            }
        }
        for(i = 0; i < n; i++){
            if(isEdge(beginWord, wordList[i])){
                adjlist[mapa[beginWord]].push_back(mapa[wordList[i]]);
                adjlist[mapa[wordList[i]]].push_back(mapa[beginWord]);
            }
        }
        bfs(mapa[beginWord], dist, adjlist, visited);
        if(dist[mapa[endWord]] == 10000000) return 0;
        return dist[mapa[endWord]] + 1;
    }
};
