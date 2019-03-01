#include <cstdio>
#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
#define ROW 25
#define COL 25
using namespace std;

int largest_area(int array[], int len){
    stack <int> heights;
    stack <int> indexes;
    int i, lastindex, tempareasize;
    int largestsize = 0;
    for(i = 0; i < len; i++){
        //Caso 1: A altura eh maior do que o elemento que está no top da minha stack
        if(heights.empty() || array[i] > heights.top()){
            heights.push(array[i]);
            indexes.push(i);
        }
        else if(array[i] < heights.top()){
            lastindex = 0;
            while(!heights.empty() && array[i] < heights.top()){
                lastindex = indexes.top();
                indexes.pop();
                tempareasize = heights.top()*(i - lastindex);
                heights.pop();
                if(largestsize < tempareasize){
                    largestsize = tempareasize;
                }
            }
            heights.push(array[i]);
            indexes.push(lastindex);
        }
    }
    while(!heights.empty()){
        tempareasize = heights.top()*(len - indexes.top());
        heights.pop();
        indexes.pop();
        if(largestsize < tempareasize){
            largestsize = tempareasize;
        }
    }
    return largestsize;
}

int find_submatrix(int A[ROW][COL], int ordem){
    int i, j;
    int max, curr_max = 0;
    //Calculando a matriz auxiliar, que vai funcionar como um "histograma"
    for(i = 1; i < ordem; i++){
        for(j = 0; j < ordem; j++){
            if(A[i][j] == 1){
                A[i][j] = A[i-1][j] + 1;
            }
        }
    }
    //Agora temos que calcular a area maxima para cada uma das linhas
    for(i = 0; i < ordem; i++){
        max = largest_area(A[i], ordem);
        if(max > curr_max){
            curr_max = max;
        }
    }
    //regenerando a matriz original
    for(i = ordem-1; i >= 0; i--){
        for(j = 0; j < ordem; j++){
            if(A[i][j]){
                A[i][j] = A[i][j] - A[i-1][j];
            }
        }
    }
    //retorno a maior area
    return curr_max;
}

int main(){
    int matriz[25][25];
    int area;
    int numcasos;
    string nome;
    int tam, i, tamanhomatriz, j, k, linha = 1; // vai ser o numero de linhas/colunas da matriz
    scanf("%d", &numcasos);
    for(i = 1; i <= numcasos; i++){
        linha = 1;
        cin.ignore(0);
        cin >> nome;
        tamanhomatriz = nome.length();
        //preenchendo a linha 0 da matriz
        for(j = 0; j < tamanhomatriz; j++){
            if(nome[j] == '1'){
                matriz[0][j] = 1;
            }
            else if(nome[j] == '0'){
                matriz[0][j] = 0;
            }
        }
        //preenchendo as outras linhas da minha matriz
        for(j = 1; j <= tamanhomatriz-1; j++){
            cin >> nome;
            for(k = 0; k < tamanhomatriz; k++){
                if(nome[k] == '1'){
                    matriz[linha][k] = 1;
                    
                }
                else if(nome[k] == '0'){
                    matriz[linha][k] = 0;
                }
            }
            linha++;
        }
        
        //Pronto ja preenchi minha matriz :D
        //Comecou a brincadeira
        area = find_submatrix(matriz, tamanhomatriz);
        cout << area << endl;
        if(i == numcasos){
            break;
        }
        cout << endl;
    }
    return 0;
}
