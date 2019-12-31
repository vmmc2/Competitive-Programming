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
        //class variables...
        vector<int> t;
        vector<int> a;
        int tam;
        //class methods...
        segtree(vector<int> base, int n){
            this->a = base;
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
                t[v] = t[2*v] * t[2*v + 1];
            }
        }
        int query(int v, int tl, int tr, int l, int r){
            if(l > r){
                return 1;
            }
            if(tl == l && tr == r){
                return t[v];
            }
            int tm = (tl + tr)/2;
            return query(2*v, tl, tm, l, min(tm ,r)) * query(2*v + 1, tm + 1, tr, max(l, tm + 1), r);
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
                t[v] = t[2*v] * t[2*v + 1];
            }
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    while(cin >> n >> q){
        vector<int> v(n);
        int aux;
        for(int i = 0; i < n; i++){
            cin >> aux;
            if(aux > 0) v[i] = 1;
            else if(aux < 0) v[i] = -1;
            else v[i] = 0;
        }
        segtree st(v, n);
        st.build(1, 0, n-1);
        char command;
        for(int i = 0; i < q; i++){
            cin >> command;
            if(command == 'C'){
                int index, val;
                cin >> index >> val;
                index--;
                if(val > 0) val = 1;
                if(val < 0) val = -1;
                st.update(1, 0, n - 1, index, val);
            }else if(command == 'P'){
                int start, end;
                cin >> start >> end;
                start--, end--;
                int ans = st.query(1, 0, n - 1, start, end);
                if(ans == 0){
                    cout << "0";
                }else if(ans > 0){
                    cout << "+";
                }else if(ans < 0){
                    cout << "-";
                }
            }
        }
        cout << "\n";
    }
    return 0;
}
