#include <bits/stdc++.h>
#include <sstream>
#include <cmath>
#define pb push_back
#define mp make_pair
#define INF 99999999999

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

class segtree{
    public:
        //data members:
        vector<ll> t;
        vector<ll> a;
        int n;
        //constructor and methods:
        segtree(vector<ll> base, int tam){
            this->a = base;
            this->n = tam;
            t.resize(4*n);
        }
        void build(int v, int tl, int tr){
            if(tl == tr){
                t[v] = a[tl];
            }else{
                int tm = (tl + tr)/2;
                build(2*v, tl, tm);
                build(2*v + 1, tm + 1, tr);
                t[v] = min(t[2*v], t[2*v + 1]);
            }
        }
        ll query(int v, int tl, int tr, int l, int r){
            if(l > r){
                return INF;
            }
            if(tl == l && tr == r){
                return t[v];
            }
            int tm = (tl + tr)/2;
            return min(query(2*v, tl, tm, l, min(tm, r)), query(2*v + 1, tm + 1, tr, max(tm + 1, l), r));
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int numcasos;
    cin >> numcasos;
    for(int a = 1; a <= numcasos; a++){
        int n, queries;
        cin >> n >> queries;
        vector<ll> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        segtree st(v, n);
        st.build(1, 0, n - 1);
        int left, right;
        cout << "Scenario #" << a << ":\n";
        for(int i = 0; i < queries; i++){
            cin >> left >> right;
            left--, right--;
            //mudar
            ll ans = st.query(1, 0, n - 1, left, right);
            cout << ans << "\n";
        }
    }
    return 0;
}
