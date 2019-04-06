#include <bits/stdc++.h>
using namespace std;

map<char,int> reg;
vector<vector<int>> g; //arvore
vector<int> idx; // 
vector<char> order;
vector<int> atual;

// curr = posicao atual na minha string
// lim eh o limite da minha string atual
void ans(int curr,int lim){

    queue<int> q; // criando uma fila para cada recursao

    if(curr == lim){ // cheguei no fim da string, entao devo printar

        for(int i=0;i<lim;i++){
            printf("%c",order[atual[i]]);
        }
        printf("\n");
        return ;
    }

    for(int i=0;i<lim;i++){ // salvo todos os valores que podem ser adicionados na posicao atual
        if(idx[i] == 0){      // ou seja, todos os valores em que o idx[i] == 0
            q.push(i);      // se idx[i] == -1, significa que ele ja foi colocado na string
        }
    }

    while(!q.empty()){ // pega um valor por vez e chama a recursao para a proxima possicao
        int v = q.front();
        q.pop();
        idx[v] = -1; // como usei este elemento, seto como -1 para nao atrapalhar futuramente
        atual[curr] = v; // salva indice no vetor da resposta
        for(int i=0;i<g[v].size();i++){
            int u = g[v][i];
            idx[u]--; // como ja usei v, todos que v liga vai ter o valor do idx reduzido em 1
        }
        ans(curr+1,lim); // recursao para a proxima posicao
        for(int i=0;i<g[v].size();i++){
            int u = g[v][i];
            idx[u]++; // volta tudo como tava antes
        }
        idx[v] = 0; // reseta e vai para o proximo elemento (ordem lexicografica respeitada)
    }

}


int main(){

    string s,s2;
    int k;
    int c1,c2,ok = 1;

    while(getline(cin,s)){
        getline(cin,s2);
        // setando tudo
        reg.clear();
        k = 0;
        g.clear();
        order.clear();

        // so para armazenar as letras
        for(int i=0;i<s.size();i++){
            if(s[i] == ' ') continue;
            order.push_back(s[i]);
        }
        // ordenando as letras em ordem alfabetica
        sort(order.begin(),order.end());

        // salvando as letras no map
        // como armazenei em ordem alfabetica, cada numero respeitara esta ordem
        for(int i=0;i<order.size();i++){
            reg[order[i]] = k++;
        }
        // setando novo valor
        g.resize(k);
        idx.resize(k);
        // idx sera um vetor onde cada posicao me indicara quantos vertices precisam estar
        // antes dele naquele momento
        // por exemplo, se idx[i] == 1, entao antes de colocar i na minha string, preciso colocar
        // um unico valor que vem antes dele
        for(int i=0;i<k;i++) idx[i] = 0;
        for(int i=0;i<s2.size();i++){
            if(s2[i] != ' '){
                c1 = reg[s2[i]];
                for(i++;i<s2.size();i++){
                    if(s2[i] != ' '){
                        c2 = reg[s2[i]];
                        break;
                    }
                }
                g[c1].push_back(c2); // criando a arvore
                idx[c2]++; // se c1 -> c2, entao c2 tem um elemento que precisa ser adicionado antes, no caso, c1
            }
        }
        if(!ok) printf("\n"); // so formatacao
        ok = 0;
        atual.resize(k); // atual guardara os valores da minha string durante a viagem na recursao
        ans(0,k); // funcao magica kk
    }
}
