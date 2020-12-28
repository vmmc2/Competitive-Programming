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
        vector<int> minimal;
        vector<int> maximal;
    public:
        dsu(int n){
            p.resize(n);
            size.resize(n);
            minimal.resize(n);
            maximal.resize(n);
            for(int i = 0; i < n; i++){
                p[i] = i;
                size[i] = 1;
                minimal[i] = i;
                maximal[i] = i;
            }
        }
        pair<int,pair<int,int>> get(int a){
            while(a != p[a]){
                a = p[a];
                p[a] = p[p[a]];
            }
            pair<int,pair<int,int>> answer;
            answer.first = minimal[a];
            answer.second.first = maximal[a];
            answer.second.second = size[a];
            return answer;
        }
        int root(int a){
            while(a != p[a]){
                a = p[a];
                p[a] = p[p[a]];
            }
            return a;
        }
        void unite(int a, int b){
            int rootA = root(a);
            int rootB = root(b);
            if(rootA != rootB){
                if(size[rootA] <= size[rootB]){
                    p[rootA] = rootB;
                    size[rootB] += size[rootA];
                    maximal[rootB] = max(maximal[rootB], maximal[rootA]);
                    minimal[rootB] = min(minimal[rootB], minimal[rootA]);
                }else{
                    p[rootB] = rootA;
                    size[rootA] += size[rootB];
                    maximal[rootA] = max(maximal[rootA], maximal[rootB]);
                    minimal[rootA] = min(minimal[rootA], minimal[rootB]);
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
        cin >> command;
        if(command == "get"){
            cin >> a;
            pair<int,pair<int,int>> answer = uf.get(a);
            cout << answer.first << " " << answer.second.first << " " << answer.second.second << endl;
        }else if(command == "union"){
            cin >> a >> b;
            uf.unite(a, b);
        }
    }

    return 0;
}
