#include <bits/stdc++.h>
#include <cmath>
#include <sstream>
#define pb push_back
#define INF 99999999

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    stack<string> s;
    string aux;
    set<string> jafoi;
    vector<string> ans;
    for(int i = 0; i < n; i++){
        cin >> aux;
        s.push(aux);
    }
    while(!s.empty()){
        aux = s.top();
        s.pop();
        if(jafoi.find(aux) == jafoi.end()){
            jafoi.insert(aux);
            ans.pb(aux);
        }
    }
    for(int i = 0; i < (int)ans.size(); i++){
        cout << ans[i] << "\n";
    }
    return 0;
}
