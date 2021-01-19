#include <bits/stdc++.h>
#include <sstream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll INF = 1e10;

class data{
    public:
        ll answer, totalSum;
        ll preffix, suffix;
        data(){
            this->answer = -INF;
            this->totalSum = -INF;
            this->preffix = -INF;
            this->suffix = -INF;
        }
};

class segtree{
    private:
        vector<ll> base;
        vector<data> stree;
        int size;
    public:
        segtree(vector<ll> a, int n){
            base = a;
            size = n;
            stree.assign(4*size, data());
        }
        data makeData(ll val){
            data aux;
            aux.answer = val;   //resposta daquele node associado ao range [L,R]
            aux.totalSum = val; //soma total daquele node
            aux.preffix = val; //maior preffixSum daquele node
            aux.suffix = val;  //maior suffixSum daquele node
            return aux;
        }
        data combine(data node1, data node2){
            data ans;
            ans.totalSum = node1.totalSum + node2.totalSum;
            ans.preffix = max(node1.preffix, node1.totalSum + node2.preffix);
            ans.suffix = max(node1.suffix + node2.totalSum, node2.suffix);
            ans.answer = max(max(node1.answer, node2.answer), node1.suffix + node2.preffix);
            return ans;
        }
        void build(int v, int tl, int tr){
            if(tl == tr){
                stree[v] = makeData(base[tl]);
            }else{
                int tm = (tl + tr)/2;
                build(2*v, tl, tm);
                build(2*v + 1, tm + 1, tr);
                stree[v] = combine(stree[2*v], stree[2*v + 1]);
            }
            return;
        }
        data query(int v, int tl, int tr, int l, int r){
            if(l > r) return makeData(-INF);
            if(tl == l && tr == r){
                return stree[v];
            }
            int tm = (tl + tr)/2;
            return combine(query(2*v, tl, tm, l, min(tm, r)), query(2*v + 1, tm + 1, tr, max(l, tm + 1), r));
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    int l, r;
    cin >> n;
    vector<ll> v(n);

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    segtree st(v, n);
    st.build(1, 0, n - 1);

    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> l >> r;
        l--, r--;
        data ans = st.query(1, 0, n - 1, l, r);
        cout << ans.answer << "\n";
    }

    return 0;
}
