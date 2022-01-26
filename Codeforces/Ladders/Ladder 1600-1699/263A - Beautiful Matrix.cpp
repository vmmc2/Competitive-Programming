#include <bits/stdc++.h>
#include <sstream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int aux;
    int row, column;

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> aux;
            if(aux == 1){
                row = i;
                column = j;
                break;
            }
        }
    }

    cout << abs(2 - row) + abs(2 - column) << endl;

    return 0;
}
