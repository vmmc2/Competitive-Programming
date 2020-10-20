#include <bits/stdc++.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    
    int answer = 1;
    char prev = s[0];
    
    for(int i = 1; i < (int)s.size(); i++){
        if(s[i] != prev){
            answer++;
            prev = s[i];
        }
    }
    
    
    cout << answer - 1 << endl;
    
    
    return 0;
}
