#include <bits/stdc++.h>
#include <cmath>
#include <sstream>
#define pb push_back
#define INF 99999999
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
//EXPLANATION:
//Let’s store the order of the rows and columns of table. 
//Thus, row[x] is the number of the row x in the initial table and column[x] is the number of column x in the initial table. 
//Then, the value of an element in the row x and column y in the current table is equal to t[row[x], column[y]], where t — initial table. 
//When we get the update request, we need to swap the x-th element and the y-th element in the corresponding array. 
//Complexity — O(n * m + k)
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int linhas, colunas, queries;
    cin >> linhas >> colunas >> queries;
    int mat[linhas][colunas];
    for(register int i = 0; i < linhas; i++){
        for(register int j = 0; j < colunas; j++){
            cin >> mat[i][j];
        }
    }
    int lin[linhas];
    int col[colunas];
    for(register int i = 0; i < linhas; i++){
        lin[i] = i;
    }
    for(register int i = 0; i < colunas; i++){
        col[i] = i;
    }
    char c;
    int k, l;
    for(register int i = 0; i < queries; i++){
        cin >> c;
        if(c == 'c'){
            cin >> k >> l;
            swap(col[k - 1], col[l - 1]);
        }
        else if(c == 'r'){
            cin >> k >> l;
            swap(lin[k - 1], lin[l - 1]);
        }
        else if(c == 'g'){
            cin >> k >> l;
            cout << mat[lin[k - 1]][col[l - 1]] << "\n";
        }
    }
    return 0;
}
