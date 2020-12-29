#include <bits/stdc++.h>
#include <sstream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double dl;

struct query{
    string command;
    int u, v;
};

class dsu{
    private:
        vector<int> p;
        vector<int> size;
    public:
        dsu(int n){
            p.resize(n);
            size.assign(n, 1);
            for(int i = 0; i < n; i++){
                p[i] = i;
            }
        }
        int get(int a){
            while(a != p[a]){
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

    int n, m, k;
    int a, b;
    string command;
    cin >> n >> m >> k;

    dsu uf(n + 1);
    struct query aux;
    vector<query> v;
    vector<string> answer;

    for(int i = 0; i < m; i++){
        cin >> a >> b;
    }
    for(int i = 0; i < k; i++){
        cin >> aux.command >> aux.u >> aux.v;
        v.push_back(aux);
    }
    reverse(v.begin(), v.end());
    
    for(int i = 0; i < (int)v.size(); i++){
        if(v[i].command == "ask"){
            if(uf.get(v[i].u) == uf.get(v[i].v)){
                answer.push_back("YES\n");
            }else{
                answer.push_back("NO\n");
            }
        }else if(v[i].command == "cut"){
            uf.unite(v[i].u, v[i].v);
        }
    }
    reverse(answer.begin(), answer.end());
    for(auto s : answer){
        cout << s;
    }
    
    return 0;
}
