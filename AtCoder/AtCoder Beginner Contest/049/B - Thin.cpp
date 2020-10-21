#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int h, w;
    cin >> h >> w;
    
    char matrix1[h][w];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> matrix1[i][j];
        }
    }
    /*for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cout << matrix1[i][j] << " ";
        }
        cout << endl;
    }*/
    
    char matrix2[2*h][w];
    for(int i = 0, k = 0; k < h; i += 2, k++){
        for(int j = 0; j < w; j++){
            matrix2[i][j] = matrix1[k][j];
            matrix2[i + 1][j] = matrix1[k][j];
        }
    }
    for(int i = 0; i < 2*h; i++){
        for(int j = 0; j < w; j++){
            cout << matrix2[i][j];
        }
        cout << endl;
    }
    
    return 0;
}
