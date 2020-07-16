#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int w, h;
    cin >> w >> h;
    
    long long int answer = 0;
    
    for(int i = 2; i <= w; i += 2){
        for(int j = 2; j <= h; j += 2){
            answer += (w - i + 1)*(h - j + 1)*1LL;
        }
    }
    
    cout << answer << "\n";
    
    return 0;
}
