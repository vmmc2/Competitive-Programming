#include <bits/stdc++.h>
#include <sstream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll INF = 1e10;

class node{
    public:
        ll answer, nodeSum;
        ll preffix, suffix;
        node(ll val){
            answer = nodeSum = val;
            preffix = suffix = val;
        }
};

class segtree{
    private:
        vector<ll> base;
        vector<node> stree;
        int size;
    public:
        segtree(vector<ll> a, int n){
            base = a;
            size = n;
            stree.assign(4*size, node(-INF));
        }
        node combine(node left, node right){
            node result(0);
            result.nodeSum = left.nodeSum + right.nodeSum;
            result.preffix = max(left.preffix, left.nodeSum + right.preffix);
            result.suffix = max(right.suffix, right.nodeSum + left.suffix);
            result.answer = max(max(left.answer, right.answer), left.suffix + right.preffix);
            return result;
        }
        void build(int v, int tl, int tr){
            if(tl == tr){
                stree[v] = node(base[tl]);
            }else{
                int tm = (tl + tr)/2;
                build(2*v, tl, tm);
                build(2*v + 1, tm + 1, tr);
                stree[v] = combine(stree[2*v], stree[2*v + 1]);
            }
            return;
        }
        void update(int v, int tl, int tr, int pos, ll newVal){
            if(tl == tr){
                stree[v] = node(newVal);
            }else{
                int tm = (tl + tr)/2;
                if(pos <= tm){
                    update(2*v, tl, tm, pos, newVal);
                }else{
                    update(2*v + 1, tm + 1, tr, pos, newVal);
                }
                stree[v] = combine(stree[2*v], stree[2*v + 1]);
            }
            return;
        }
        node query(int v, int tl, int tr, int l , int r){
            if(l > r) return node(-INF);
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

    int n, m, op;
    cin >> n;
    vector<ll> v(n);

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    segtree st(v, n);
    st.build(1, 0, n - 1);

    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> op;
        if(op == 0){
            int x; 
            ll v;
            cin >> x >> v;
            x--;
            st.update(1, 0, n - 1, x, v);
        }else if(op == 1){
            int l, r;
            cin >> l >> r;
            l--, r--;
            node ans = st.query(1, 0, n - 1, l, r);
            cout << ans.answer << "\n";
        }
    }

    return 0;
}
