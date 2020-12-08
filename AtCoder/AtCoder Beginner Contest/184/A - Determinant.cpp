#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int matrix[2][2];
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cin >> matrix[i][j];
        }
    }

    cout << (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]) << endl;


    return 0;
}
