#include <bits/stdc++.h>
#include <sstream>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int n, m;
    long long int answer = 0;
    cin >> n >> m;
 
    vector<int> v(m);
    for(int i = 0; i < m; i++){
        cin >> v[i];
    }
 
    for(int i = 0; i < m; i++){
        if(i == 0){
            answer += (v[i] - 1);
        }else{
            if(v[i] >= v[i - 1]) answer += (v[i] - v[i - 1]);
            else answer += (long long)((n - v[i - 1])*1LL + (v[i] - 1)*1LL + 1);
        }
    }
 
    cout << answer << endl;
 
    return 0;
}
