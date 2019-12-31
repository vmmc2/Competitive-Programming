#include <bits/stdc++.h>
#include <sstream>
#include <cmath>
#define pb push_back
#define mp make_pair
#define INF 99999999

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

class segtree{ //segment tree de soma...
    public:
        //class variables
        vector<ll> t;
        vector<ll> a;
        int tam;
        //class methods
        segtree(vector<ll> aux, int n){ //constructor
            this->a = aux;
            this->tam = n;
            t.resize(4*n, 0);
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
        void update(int v, int tl, int tr, int pos, int new_val){
            if(tl == tr){
                t[v] = new_val;
            }else{
                int tm = (tl + tr)/2;
                if(pos <= tm){
                    update(2*v, tl, tm, pos, new_val);
                }else{
                    update(2*v + 1, tm + 1, tr, pos, new_val);
                }
                t[v] = t[2*v] + t[2*v + 1];
            }
        }
        int query(int v, int tl, int tr, int l, int r){
            if(l > r) return 0;
            if(tl == l && tr == r){
                return t[v];
            }
            int tm = (tl + tr)/2;
            return query(2*v, tl, tm, l, min(r, tm)) + query(2*v + 1, tm + 1, tr, max(l, tm + 1), r);
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    int caso = 1;
    int flag = 0;
    while(cin >> n){
        if(n == 0) break;
        if(flag == 1){
            cout << "\n";
        }
        cout << "Case " << caso << ":\n";
        vector<ll> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        segtree st(v, n);
        st.build(1, 0, n-1);
        string action;
        int l, r;
        int x;
        ll novo_valor;
        ll ans;
        while(true){
            cin >> action;
            if(action == "END") break;
            else if(action == "S"){
                cin >> x >> novo_valor;
                x--;
                st.update(1, 0, n-1, x, novo_valor);
            }
            else if(action == "M"){
                cin >> l >> r;
                l--, r--;
                ans = st.query(1, 0, n-1, l, r);
                cout << ans << "\n";
            }
        }
        caso++;
        flag = 1;
    }
    return 0;
}
