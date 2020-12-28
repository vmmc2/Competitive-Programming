#include <bits/stdc++.h>
#include <sstream>

using namespace std;

class dsu{
    private:
        vector<int> p;
        vector<int> size;
        vector<int> points;
        vector<int> extra;
    public:
        dsu(int n){
            p.resize(n);
            size.assign(n, 1);
            points.assign(n, 0);
            extra.assign(n, 0);
            for(int i = 0; i < n; i++) p[i] = i;
        }
        int root(int a){
            while(a != p[a]){
                a = p[a];
            }
            return a;
        }
        int get(int x){
            return (x == p[x] ? points[x] : (points[x] - extra[x] + get(p[x])));
        }
        void unite(int x, int y){
            int rootX = root(x);
            int rootY = root(y);
            if(rootX != rootY){
                if(size[rootX] <= size[rootY]){
                    p[rootX] = rootY;
                    size[rootY] += size[rootX];
                    int aux = points[rootY];
                    extra[rootX] = aux;
                }else{
                    p[rootY] = rootX;
                    size[rootX] += size[rootY];
                    int aux = points[rootX];
                    extra[rootY] = aux;
                }
            }
            return;
        }
        void add(int x, int v){
            int rootX = root(x);
            points[rootX] += v;
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
    int x, v;
    for(int i = 0; i < m; i++){
        cin >> command;
        if(command == "add"){
            cin >> x >> v;
            uf.add(x, v);
        }else if(command == "join"){
            cin >> x >> v;
            uf.unite(x, v);
        }else if(command == "get"){
            cin >> x;
            cout << uf.get(x) << "\n";
        }
    }


    return 0;
}
