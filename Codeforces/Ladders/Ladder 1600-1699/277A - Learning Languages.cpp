 unite(int a, int b){
            int rootA = root(a);
            int rootB = root(b);
            if(rootA != rootB){
                if(sz[rootA] <= sz[rootB]){
                    uf[rootA] = rootB;
                    sz[rootB] += sz[rootA];
                }else{
                    uf[rootB] = rootA;
                    sz[rootA] += sz[rootB];
                }
            }
            return;
        }
};
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int n, m;
    int numLang, langID;
    int cntGroups = 0;
    int numZeroes = 0;
 
    cin >> n >> m;
 
    dsu union_find(n);
    vector<unordered_set<int>> v(n);
 
    for(int i = 0; i < n; i++){
        cin >> numLang;
        if(numLang == 0) numZeroes++;
        for(int j = 0; j < numLang; j++){
            cin >> langID;
            v[i].insert(langID);
        }
    }
 
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            for(unordered_set<int>::iterator it = v[i].begin(); it != v[i].end(); it++){
                if(v[j].find(*it) != v[j].end()){
                    union_find.unite(i, j);
                    break;
                }
            }
        }
    }
    if(numZeroes == n){
        cout << n << endl;
    }else{
        for(int i = 0; i < n; i++){
            if(i == union_find.root(i)) cntGroups++;
        }
        cout << cntGroups - 1 << endl;
    }
 
    return 0;
}
