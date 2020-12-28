#include <bits/stdc++.h>
#include <sstream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double dl;

class dsu{
    private:
        vector<int> p;
        vector<int> size;
    public:
        dsu(int n){
            p.resize(n);
            size.resize(n);
            for(int i = 0; i < n; i++){
                p[i] = i;
                size[i] = 1;
            }
        }
        int get(int a){
            while(p[a] != a){
                a = p[a];
                p[a] = p[p[a]];
            }
            return p[a];
        }
        void unite(int a, int b){
            int rootA = get(a);
            int rootB = get(b);
            if(rootA != rootB){
                if(size[rootA] <= size[rootB]){
                    p[rootA] = rootB;
                    size[rootB] += size[rootA];
                }else{
                    p[rootB] = rootA;
                    size[rootA] += size[rootB];
                }
            }
            return;
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    dsu uf(n + 1);

    string command;
    int a, b;
    for(int i = 0; i < m; i++){
        cin >> command >> a >> b;
        if(command == "union"){
            uf.unite(a, b);
        }else if(command == "get"){
            if(uf.get(a) == uf.get(b)){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }
    }


    return 0;
}
