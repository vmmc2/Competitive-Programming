#include <bits/stdc++.h>
#include <sstream>
#include <cmath>
#define pb push_back
#define mp make_pair
#define INF 99999999

/*
   xor -> ^   /// or -> |
*/
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

class segtree{
    public:
        //variables
        vector<pair<int,int>> t;
        vector<int> a;
        int n;
        //methods
        segtree(vector<int> base, int tam){
            this->a = base;
            this->n = tam;
            t.resize(4*n, {0,0});
        }
        pair<int,int> combine(pair<int,int> a, pair<int,int> b){
            pair<int,int> c;
            if(a.second ==  1 && b.second == 1){
                c.first = a.first | b.first;
                c.second = 2;
            }else if(a.second == 2 && b.second == 2){
                c.first = a.first ^ b.first;
                c.second = 1;
            }
            return c;
        }
        void build(int v, int tl, int tr){
            if(tl == tr){
                t[v].first = a[tl];
                t[v].second = 1; //se isso for 1 -> manda um or
                //se for 2 -> manda um xor
            }else{
                int tm = (tl + tr)/2;
                build(2*v, tl, tm);
                build(2*v + 1, tm + 1, tr);
                t[v] = combine(t[2*v], t[2*v + 1]);
            }
        }
        void update(int v, int tl, int tr, int pos, int new_val){
            if(tl == tr){
                t[v].first = new_val;
                t[v].second = 1;
            }else{
                int tm = (tl + tr)/2;
                if(pos <= tm){
                    update(2*v, tl, tm, pos, new_val);
                }else{
                    update(2*v + 1, tm + 1, tr, pos, new_val);
                }
                t[v] = combine(t[2*v], t[2*v + 1]);
            }
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int exp, queries;
    cin >> exp >> queries;
    int n = pow(2, exp);
    int pos, new_val;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    segtree st(v, n);
    st.build(1, 0, n - 1);
    for(int i = 0; i < queries; i++){
        cin >> pos >> new_val;
        pos--;
        st.update(1, 0, n - 1, pos, new_val);
        cout << st.t[1].first << "\n";
    }
    return 0;
}
