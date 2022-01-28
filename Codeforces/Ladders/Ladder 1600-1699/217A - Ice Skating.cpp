#include <bits/stdc++.h>
#include <sstream>
 
using namespace std;
 
class dsu{
    private:
        vector<int> uf;
        vector<int> sz;
    public:
        dsu(int n){
            uf.resize(n);
            sz.assign(n, 1);
            for(int i = 0; i < n; i++){
                uf[i] = i;
            }
        }
        int root(int x){
            while(x != uf[x]){
                uf[x] = uf[uf[x]];
                x = uf[x];
            }
            return uf[x];
        }
        void unite(int a, int b){
            int rootA = root(a);
            int rootB = root(b);
            if(rootA != rootB){
                if(sz[rootA] <= sz[rootB]){
                    uf[rootA] = uf[rootB];
                    sz[rootB] += sz[rootA];
                }else{
                    uf[rootB] = uf[rootA];
                    sz[rootA] += sz[rootB];
                }
            }
            return;
        }
};
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int n, numGroups = 0;
    cin >> n;
 
    vector<pair<int,int>> v(n);
    dsu union_find(n);
 
    for(int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
    }
 
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(abs(v[i].first - v[j].first) == 0 || abs(v[i].second - v[j].second) == 0){
                union_find.unite(i, j);
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(i == union_find.root(i)) numGroups++;
    }
 
    cout << numGroups - 1 << endl;
 
    return 0;
}
