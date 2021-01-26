#include <bits/stdc++.h>
#include <sstream>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t;
    int numTiles, sizeSquare;
    int tile[2][2];
    cin >> t;
 
    for(int a = 0; a < t; a++){
        cin >> numTiles >> sizeSquare;
        bool haveASymmetricTile = false;
        for(int b = 0; b < numTiles; b++){
            for(int i = 0; i < 2; i++){
                for(int j = 0; j < 2; j++){
                    cin >> tile[i][j];
                }
            }
            if(tile[0][1] == tile[1][0]){
                haveASymmetricTile = true;
            }
        }
        if(sizeSquare % 2 != 0){
            cout << "NO" << "\n";
        }else{
            if(haveASymmetricTile){
                cout << "YES" << "\n";
            }else{
                cout << "NO" << "\n";
            }    
        }
    }
 
 
    return 0;
}
