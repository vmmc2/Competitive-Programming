#include <bits/stdc++.h>
#include <sstream>
 
using namespace std;
 
typedef long long int ll;
 
struct operation{
    int left, right;
    ll d;
};
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int n, m, k;
    cin >> n >> m >> k;
 
    vector<ll> v(n);
    vector<operation> ops(m);
    vector<int> opRep(m, 0);
 
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
 
    for(int i = 0; i < m; i++){
        cin >> ops[i].left >> ops[i].right >> ops[i].d;
        ops[i].left--;
        ops[i].right--;
    }
 
    int beginop, endop;
    for(int i = 0; i < k; i++){
        cin >> beginop >> endop;
        beginop--, endop--;
        opRep[beginop]++;
        if(endop + 1 <= m - 1){
            opRep[endop + 1]--;
        }
    }
    for(int i = 0; i < m; i++){
        if(i == 0) continue;
        else{
            opRep[i] = opRep[i] + opRep[i - 1];
        }
    }
 
    vector<ll> test(n, 0);
    for(int i = 0; i < m; i++){
        ll times = opRep[i] * 1LL;
        ll finalD = times * ops[i].d * 1LL;
        int left = ops[i].left;
        int right = ops[i].right;
        test[left] += finalD;
        if(right + 1 <= n - 1){
            test[right + 1] -= finalD;
        }
    }
 
    for(int i = 0; i < n; i++){
        if(i == 0) continue;
        else{
            test[i] = test[i] + test[i - 1];
        }
    }
 
    for(int i = 0; i < n; i++){
        v[i] = v[i] + test[i];
    }
    for(auto x : v){
        cout << x << " ";
    }
    cout << endl;
 
 
    return 0;
}
