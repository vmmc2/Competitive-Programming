#include <bits/stdc++.h>
#include <sstream>
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll INF = 100000000;
const int MOD = 1e9 + 7;


class dsu{
    private:
        vector<int> uf;
        vector<int> size;
    public:
        dsu(int n){
            uf.assign(n, 0);
            size.assign(n, 1);
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
                if(size[rootA] <= size[rootB]){
                    uf[rootA] = rootB;
                    size[rootB] += size[rootA];
                }else{
                    uf[rootB] = rootA;
                    size[rootA] += size[rootB];
                }
            }
            return;
        }
        int getSize(int x){
            return size[x];
        }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int numvertices, numgroups;
    cin >> numvertices >> numgroups;

    dsu ds1(numvertices + 1);

    for(int x = 1; x <= numgroups; x++){
        int groupsize, a, b;
        cin >> groupsize;
        for(int y = 1; y <= groupsize; y++){
            if(y == 1) cin >> a;
            else{
                cin >> b;
                ds1.unite(a, b);
            }
        }
    }
    for(int i = 1; i <= numvertices; i++){
        cout << ds1.getSize(ds1.root(i)) << " ";
    }

    return 0;
}
