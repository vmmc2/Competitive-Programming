#include <bits/stdc++.h>
#include <sstream>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int m, n;
    int answer = 0;
    cin >> n >> m;
 
    for(int i = 0; i <= 32; i++){
        for(int j = 0; j <= 32; j++){
            if((i*i) + j == n && i + (j*j) == m){
                answer++;
            }
        }
    }
 
    cout << answer << endl;
 
    return 0;
}
