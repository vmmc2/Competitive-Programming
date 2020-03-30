#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int m = 3;
    int n = 3;;
    int matrix[m][n] = {{1,4,0},
                        {3,5,6},
                        {0,6,9}};
    //Assumo que nao temos nenhum zero nem na primeira linha
    //e nem na primeira coluna.
    bool firstRowZero = false;
    bool firstColumnZero = false;
    //Checando a primeira linha.
    for(int i = 0; i < n; i++){
        if(matrix[0][i] == 0){
            firstRowZero = true;
            break;
        }
    }
    //Checando a primeira coluna.
    for(int i = 0; i < m; i++){
        if(matrix[i][0] == 0){
            firstColumnZero = true;
            break;
        }
    }
    //Agora tem que checar o restante da matriz e para cada zero encontrado,
    //a gente zera a primeira linha e a primeira coluna correspondente aquela
    //posicao
    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            if(matrix[i][j] == 0){
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    //agora a gente vai interagir de novo pela matriz e vai zerar todas as 
    //linhas e todas as colunas conforme nossa necessidade.
    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
        }
    }
    if(firstRowZero == true){
        for(int i = 0; i < n; i++){
            matrix[0][i] = 0;
        }
    }
    if(firstColumnZero == true){
        for(int i = 0; i < m; i++){
            matrix[i][0] = 0;
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
