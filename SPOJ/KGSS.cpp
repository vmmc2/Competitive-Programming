#include <bits/stdc++.h>
#include <sstream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

class node{
    public:
        pair<int,int> fstGreatest;
        pair<int,int> sndGreatest;
        node(int fstGrtst, int sndGrtst, int indFst, int indSnd){
            fstGreatest.first = fstGrtst;
            fstGreatest.second = indFst;
            sndGreatest.first = sndGrtst;
            sndGreatest.second = indSnd;
        }
};

class segtree{
    private:
        int size;
        vector<int> base;
        vector<node> stree;
    public:
        segtree(vector<int> a, int n){
            size = n;
            base = a;
            stree.assign(4*size, node(-1, -1, -1, 1));
        }
        node combine(node left, node right){
            node result(-1, -1, -1, -1);
            vector<pair<int,int>> v;
            v.push_back(left.fstGreatest);
            v.push_back(left.sndGreatest);
            v.push_back(right.fstGreatest);
            v.push_back(right.sndGreatest);
            sort(v.begin(), v.end());
            result.fstGreatest = v[3];
            result.sndGreatest = v[2];
            return result;
        }
        void build(int v, int tl, int tr){
            if(tl == tr){
                stree[v] = node(base[tl], -1, tl, -1);
            }else{
                int tm = (tl + tr)/2;
                build(2*v, tl, tm);
                build(2*v + 1, tm + 1, tr);
                stree[v] = combine(stree[2*v], stree[2*v + 1]);
            }
            return;
        }
        void update(int v, int tl, int tr, int pos, int newVal){
            if(tl == tr){
                stree[v] = node(newVal, -1, pos, -1);
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
        node query(int v, int tl, int tr, int l, int r){
            if(l > r) return node(-1, -1, -1, -1);
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

    int n, q;
    char op;
    int l, r, index, val;
    cin >> n;
    vector<int> v(n);
    
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    segtree st(v, n);
    st.build(1, 0, n - 1);

    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> op;
        if(op == 'Q'){
            cin >> l >> r;
            l--, r--;
            node curr = st.query(1, 0, n - 1, l, r);
            cout << curr.fstGreatest.first + curr.sndGreatest.first << "\n";
        }else if(op == 'U'){
            cin >> index >> val;
            index--;
            st.update(1, 0, n - 1, index, val);
        }
    }

    return 0;
}
