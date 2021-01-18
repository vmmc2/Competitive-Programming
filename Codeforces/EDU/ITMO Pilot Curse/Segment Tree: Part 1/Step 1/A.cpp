#include <bits/stdc++.h>
#include <sstream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

class segtree{
    private:
        int size;
        vector<ll> a;
        vector<ll> sums;
    public:
        segtree(vector<ll> base, int n){
            a = base;
            size = n;
            sums.resize(4*n, 0);
        }
        void build(vector<ll> base, int v, int tl, int tr){
            if(tl == tr){
                sums[v] = base[tl];
            }else{
                int tm = (tl + tr)/2;
                build(base, 2*v, tl, tm);
                build(base, 2*v + 1, tm + 1, tr);
                sums[v] = sums[2*v] + sums[2*v + 1];
            }
            return;
        }
        void update(int v, int tl, int tr, int pos, int newVal){
            if(tl == tr){
                sums[v] = newVal;
            }else{
                int tm = (tl + tr)/2;
                if(pos <= tm) update(2*v, tl, tm, pos, newVal);
                else update(2*v + 1, tm + 1, tr, pos, newVal);
                sums[v] = sums[2*v] + sums[2*v + 1];
            }
            return;
        }
        ll query(int v, int tl, int tr, int l, int r){
            if(l > r) return 0;
            if(l == tl && r == tr){
                return sums[v];
            }
            int tm = (tl + tr)/2;
            return query(2*v, tl, tm, l, min(tm, r)) + query(2*v + 1, tm + 1, tr, max(l, tm + 1), r);
        }
};


int main(){

    int n, m;
    int op;
    cin >> n >> m;

    vector<ll> v(n);
    for(int x = 0; x < n; x++){
        scanf("%lld", &v[x]);
    }

    segtree st(v, n);
    st.build(v, 1, 0, n - 1);

    for(int a = 0; a < m; a++){
        cin >> op;
        if(op == 1){
            int i, v;
            cin >> i >> v;
            st.update(1, 0, n - 1, i, v);
        }else if(op == 2){
            int l, r;
            cin >> l >> r;
            r--;
            ll answer = st.query(1, 0, n - 1, l, r);
            printf("%lld\n", answer);
        }
    }

    return 0;
}
