#include <bits/stdc++.h>

using namespace std;

char matrix[50][50];
int visitados[50][50];
int resposta = 0;
int linha, coluna;

void dfs(int row, int col, int profundidade){
    int i;
    int temporario1, temporario2;
    resposta = max(profundidade,resposta);
    //Vetores para gerar os indices das celulas adjacentes para rodar a dfs
    int rr[8]={-1,-1,-1,0,0,1,1,1};
    int cc[8]={-1,0,1,-1,1,-1,0,1};
    for(i = 0; i < 8; i++){
        temporario1 = row + rr[i];
        temporario2 = col + cc[i];
        //Tem que checar os limites da matriz pra nao dar RTE 
        if((temporario1 >= 0 && temporario1 < linha) && (temporario2 >= 0 && temporario2 < coluna) && visitados[temporario1][temporario2] == 0){
            if(matrix[temporario1][temporario2] == matrix[row][col] + 1){
                visitados[temporario1][temporario2] = 1;
                dfs(temporario1,temporario2, profundidade+1);
            }
        }
    }
    
}
int main(){
    int i, j;
    int numcasos = 0;
    scanf("%d %d", &linha, &coluna);
    while(linha != 0 && coluna != 0){
        numcasos = numcasos + 1;
        resposta = 0;
        //Processando o grid, que vai funcionar como grafo
        for(i = 0; i < linha; i++){
            for(j = 0; j < coluna; j++){
                scanf(" %c", &matrix[i][j]);
                visitados[i][j] = 0;
            }
        }
        //Agora a gente tem que rodar uma dfs para cada vertice A presente no grafo.
        //Para fazer isso, basta percorrer a matriz procurando pelos vertices A e em seguida
        //rodar a dfs a partir deles.
        for(i = 0; i < linha; ++i){
               for(j = 0; j < coluna; ++j){
                    if(matrix[i][j]=='A'){
                         visitados[i][j]=1;
                         dfs(i,j,1);
                    }   
               }
        }       
        printf("Case %d: %d\n", numcasos, resposta);
        scanf("%d %d", &linha, &coluna);
    }
    return 0;
}
