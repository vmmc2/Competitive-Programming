#include <bits/stdc++.h>
#include <sstream>
#include <cmath>
#define pb push_back
#define mp make_pair
#define INF 99999999

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

struct node{
    int length = 0;
    int openbrack = 0;
    int closingbrack = 0;
};

class segtree{
    public:
        //data members
        vector<node> t;
        string s;
        int n;
        //constructor + methods
        segtree(string base, int n){
            this->s = base;
            this->n = n;
            t.resize(4*n);
        }
        struct node make_node(char dale){
            struct node res;
            res.length = 0;
            if(dale == '('){
                res.openbrack++;
            }else{
                res.closingbrack++;
            }
            return res;
        }
        struct node combine(struct node a, struct node b){
            struct node ans;
            int t = min(a.openbrack, b.closingbrack);
            ans.length = a.length + b.length + (2*t);
            ans.openbrack = a.openbrack + b.openbrack - t;
            ans.closingbrack = a.closingbrack + b.closingbrack - t;
            return ans;
        }
        void build(int v, int tl, int tr){
            if(tl == tr){
                t[v] = make_node(s[tl]);
            }else{
                int tm = (tl + tr)/2;
                build(2*v, tl, tm);
                build(2*v + 1, tm + 1, tr);
                t[v] = combine(t[2*v], t[2*v + 1]);
            }
        }
        struct node query(int v, int tl, int tr, int l, int r){
            if(l > r){
                struct node trash;
                return trash;
            }
            if(tl == l && tr == r){
                return t[v];
            }
            int tm = (tl + tr)/2;
            return combine(query(2*v, tl, tm, l, min(r,tm)), query(2*v + 1, tm + 1, tr, max(tm + 1, l), r));
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int numqueries;
    string s;
    int l, r;
    cin >> s;
    cin >> numqueries;
    segtree st(s, (int)s.size());
    st.build(1, 0, (int)s.size() - 1);
    for(int i = 0; i < numqueries; i++){
        cin >> l >> r;
        l--, r--;
        struct node ans = st.query(1, 0, (int)s.size() - 1, l, r);
        cout << ans.length << "\n";
    }
    return 0;
}
