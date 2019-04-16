#include <bits/stdc++.h>
#define MAX 25

using namespace std;

vector <int> adjlist[MAX];
vector <char> vertices;
map <char,int> dictionary;
vector<int> idx;
vector <int> atual;
string s1, s2;

void preprocess(){
    for(int i = 0; i < MAX; i++){
        adjlist[i].clear();
    }
}

void toposort(int curr, int limite){
    //printf("curr: %d -- limite: %d\n", curr, limite);
    queue <int> q;
    if(curr == limite){
        for(int i = 0; i < limite; i++){
            printf("%c", vertices[atual[i]]);
        }
        printf("\n");
        return;
    }
    for(int i = 0 ; i < limite; i++){
        if(idx[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int v = q.front();
        q.pop();
        idx[v] = -1; // ja foi visitado
        atual[curr] = v;
        for(int i = 0; i < (int)adjlist[v].size(); i++){
            int u = adjlist[v][i];
            idx[u]--;
        }
        toposort(curr+1, limite);
        for(int i = 0; i < (int)adjlist[v].size(); i++){
            int u = adjlist[v][i];
            idx[u]++;
        }
        idx[v] = 0;
    }
}

int main(){
    int ok = 1;
    int a, b;
    int k;
    while(getline(cin, s1)){
        getline(cin, s2);
        for(int i = 0; i < (int)s1.size(); i++){
            if(s1[i] != ' '){
                vertices.push_back(s1[i]);
            }
        }
        sort(vertices.begin(), vertices.end());
        k = 0;
        for(int i = 0; i < (int)vertices.size(); i++){
            dictionary[vertices[i]] = k++;
        }
        idx.resize(k);
        for(int i = 0; i < k; i++){
            idx[i] = 0;
        }
        for(int i = 0; i < (int)s2.size(); i++){
            if(s2[i] != ' '){
                a = dictionary[s2[i]];
                for(i++; i < (int)s2.size(); i++){
                    if(s2[i] != ' '){
                        b = dictionary[s2[i]];
                        break;
                    }
                }
                adjlist[a].push_back(b);
                idx[b]++;
            }
        }
        if(!ok){
            printf("\n");
        }
        ok = 0;
        atual.resize(k);
        toposort(0, k);
        //resetando as paradas
        vertices.clear();
        dictionary.clear();
        preprocess();
        idx.clear();
    }
    return 0;
}
