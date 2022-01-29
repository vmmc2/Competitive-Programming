#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#include <sstream>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int n; 
    long long answer = 0;
    cin >> n;
 
    vector<long long> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
 
    long long curr = 1;
    for(auto x : v){
        answer += abs(curr - x);
        curr++;
    }
    
    cout << answer << endl;
 
    return 0;
}
