#include <bits/stdc++.h>
#include <cmath>
#include <sstream>
#define INF 99999999
#define pb push_back
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int numcasos;
    cin >> numcasos;
    for(int a = 1; a <= numcasos; a++){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        set<int> precos;
        int ans = 0;
        for(int i = n - 1; i >= 0; i--){
            if(precos.empty()){
                precos.insert(v[i]);
            }else{
                set<int>::iterator it = precos.begin();
                if(v[i] > *it) ans++;
                precos.insert(v[i]);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
