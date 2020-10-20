#include <bits/stdc++.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int h, w, n;
    cin >> w >> h >> n;
    
    int matrix[h][w];
    memset(matrix, 0, sizeof(matrix));
    int x, y, type;
    for(int a = 0; a < n; a++){
        cin >> x >> y >> type;
        if(type == 1){
            for(int i = 0; i < h; i++){
               for(int j = 0; j < x; j++){
                   matrix[i][j] = 1;
               } 
            }
        }else if(type == 2){
            for(int i = 0; i < h; i++){
               for(int j = x; j < w; j++){
                   matrix[i][j] = 1;
               } 
            }
        }else if(type == 3){
            for(int i = h - y; i < h; i++){
               for(int j = 0; j < w; j++){
                   matrix[i][j] = 1;
               } 
            }
        }else if(type == 4){
            for(int i = 0; i < h - y; i++){
               for(int j = 0; j < w; j++){
                   matrix[i][j] = 1;
               } 
            }
        }
    }
    int answer = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(matrix[i][j] == 0)answer++;
        }
    }
    /*for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }*/
    cout << answer << endl;
    return 0;
}
