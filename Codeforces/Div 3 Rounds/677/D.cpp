#include <bits/stdc++.h>
#include <sstream>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
class dsu{
    private:
        vector<int> p;
        vector<int> size;
    public:
        dsu(int n){
            p.resize(n);
            size.resize(n, 1);
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
 
    int t, n;
    cin >> t;
 
    for(int a = 0; a < t; a++){
        cin >> n;
        vector<int> gang(n);
        for(int i = 0; i < n; i++){
            cin >> gang[i];
        }
        vector<pair<int,int>> edges;
        vector<pair<int,int>> answer;
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                edges.push_back({i, j});
            }
        }
        dsu uf(n);
        sort(edges.begin(), edges.end());
        int counter = 0;
        for(int i = 0; i < (int)edges.size(); i++){
            if(counter == n - 1) break;
            if(gang[edges[i].first] != gang[edges[i].second]){
                if(uf.get(edges[i].first) != uf.get(edges[i].second)){
                    uf.unite(edges[i].first, edges[i].second);
                    counter++;
                    answer.push_back(edges[i]);
                }
            }
        }
        if(counter != n - 1){
            cout << "NO" << "\n";
        }else{
            cout << "YES" << "\n";
            for(auto par : answer){
                cout << (par.first + 1) << " " << (par.second + 1) << "\n";
            }
        }
    }
 
    return 0;
}
