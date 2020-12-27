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
                p[a] = p[p[a]];
                a = p[a];
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
        int subsetSize(int x){
            int rootX = get(x);
            return size[rootX];
        }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    unordered_map<int,vector<int>> dict;

    int n, q;
    cin >> n >> q;
    
    vector<int> v(n);
    dsu uf(n + 1);

    for(int i = 0; i < n; i++){
        cin >> v[i];
        dict[v[i]].push_back(i + 1);
    }
    int tp, x, y;
    for(int i = 0; i < q; i++){
        cin >> tp >> x >> y;
        if(tp == 1){
            uf.unite(x, y);
        }else if(tp == 2){
            int answer = 0;
            vector<int> aux = dict[y];
            for(int j = 0; j < (int)aux.size(); j++){
                if(uf.get(aux[j]) == uf.get(x)){
                    answer++;
                    //cout << aux[j] << " e " << x << " satisfazem as condicoes!" << endl;
                }
            }
            cout << answer << endl;
        }
    }


    return 0;
}
