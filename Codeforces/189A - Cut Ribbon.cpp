#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int a, b, c;
    int n;
    int k;
    
    int answer = 0;
    
    
    // a*i + b*j + c*k = n
    // c*k = n - a*i - b*j
    
    cin >> n >> a >> b >> c;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            k = n - a*i - b*j;
            if(k >=0 && k % c == 0){
                answer = max(answer, (i + j + k/c));
            }
        }
    }
    
    cout << answer << "\n";
    return 0;
}
