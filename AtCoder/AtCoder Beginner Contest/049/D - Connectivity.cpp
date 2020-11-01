#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

class dsu{
    private:
        vector<int> root;
        vector<int> size;
    public:
        dsu(int n){
            size.assign(n, 1);
            root.assign(n, 0);
            for(int i = 0; i < n; i++){
                root[i] = i;
            }
        }
        int findRoot(int i){
            while(root[i] != i){
                root[i] = root[root[i]];
                i = root[i];
            }
            return root[i];
        }
        bool find(int a, int b){
            int rootA = findRoot(a);
            int rootB = findRoot(b);
            if(rootA == rootB) return true;
            else return false;
        }
        void unite(int a, int b){
            int rootA = findRoot(a);
            int rootB = findRoot(b);
            if(size[rootA] <= size[rootB]){
                root[rootA] = root[rootB];
                size[rootB] += size[rootA];
            }else{
                root[rootB] = root[rootA];
                size[rootA] += size[rootB];
            }
            return;
        }
        int subsetSize(int i){
            int rootI = findRoot(i);
            return size[rootI];
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k, l;
    cin >> n >> k >> l;
    
    dsu uf1(n + 1);
    dsu uf2(n + 1);
    map<pair<int,int>,int> dicio;
    
    int from, to;
    for(int i = 1; i <= k; i++){
        cin >> from >> to;
        uf1.unite(from, to);
    }
    for(int i = 1; i <= l; i++){
        cin >> from >> to;
        uf2.unite(from, to);
    }
    
    for(int i = 1; i <= n; i++){
        dicio[{uf1.findRoot(i), uf2.findRoot(i)}]++;
    }
    for(int i = 1; i <= n; i++){
        if(i > 1) cout << " ";
        cout << dicio[{uf1.findRoot(i), uf2.findRoot(i)}];
    }
    
    
    return 0;
}
