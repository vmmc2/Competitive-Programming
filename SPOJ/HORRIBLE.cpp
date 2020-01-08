#include <bits/stdc++.h>
#include <sstream>
#include <cmath>
#define pb push_back
#define mp make_pair
#define INF 99999999

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

class segtree{
    public:
        //data members
        vector<ll> t;
        vector<ll> a;
        vector<ll> lazy;
        int n;
        //constructor + methods
        segtree(vector<ll> base, int n){
            this->a = base;
            this->n = n;
            t.resize(4*n, 0);
            lazy.resize(4*n, 0);
        }
        void build(int v, int tl, int tr){
            if(tl == tr){
                t[v] = a[tl];
            }else{
                int tm = (tl + tr)/2;
                build(2*v, tl, tm);
                build(2*v + 1, tm + 1, tr);
                t[v] = t[2*v] + t[2*v + 1];
            }
        }
        void update(int v, int tl, int tr, int l, int r, ll addend){
            if(tl > tr) return;
            //certifique-se de que a propagacao esta sendo feita corretamente
            //em cada no
            if(lazy[v] != 0){
                //t[v] += lazy[v]; <- tava desse jeito
                t[v] += (tr - tl + 1)*lazy[v];
                if(tl != tr){
                    lazy[2*v] += lazy[v];
                    lazy[2*v + 1] += lazy[v];
                }
                lazy[v] = 0;
            }
            //no overlap condition
            if(l > tr || r < tl){
                return;
            }
            //total overlap condition
            if(l <= tl && r >= tr){
                //t[v] += addend; //tava assim
                t[v] += (tr - tl + 1)*addend;
                if(tl != tr){
                    lazy[2*v] += addend;
                    lazy[2*v + 1] += addend;
                }
                return;
            }
            //partial overlap
            int tm = (tl + tr)/2;
            update(2*v, tl, tm, l, r, addend);
            update(2*v + 1, tm + 1, tr, l, r, addend);
            t[v] = t[2*v] + t[2*v + 1];
        }
        ll query(int v, int tl, int tr, int l, int r){
            if(tl > tr) return 0;

            if(lazy[v] != 0){
                //t[v] += lazy[v]; <- tava assim
                t[v] += (tr - tl + 1)*lazy[v];
                if(tl != tr){
                    lazy[2*v] += lazy[v];
                    lazy[2*v + 1] += lazy[v];
                }
                lazy[v] = 0;
            }
            //no overlap
            if(l > tr || r < tl) return 0;
            //total overlap
            if(l <= tl && r >= tr) return t[v];
            //partial overlap
            int tm = (tl + tr)/2;
            return query(2*v, tl, tm, l, r) + query(2*v + 1, tm + 1, tr, l, r);
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int numcasos;
    cin >> numcasos;
    for(int a = 1; a <= numcasos; a++){
        int n, c;
        cin >> n >> c;
        vector<ll> v(n, 0);
        segtree st(v, n);
        st.build(1, 0, n-1);
        int type, l, r;
        ll add;
        for(int i = 0; i < c; i++){
            cin >> type;
            if(type == 0){
                cin >> l >> r >> add;
                l--, r--;
                st.update(1, 0, n-1, l, r, add);
            }else{
                cin >> l >> r;
                l--, r--;
                ll ans = st.query(1, 0, n-1, l, r);
                cout << ans << "\n";
            }
        }
    }
    return 0;
}
