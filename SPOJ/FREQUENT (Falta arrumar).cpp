#include <bits/stdc++.h>
#include <sstream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

class segtree{
    private:
        int size;
        vector<int> base;
        vector<pair<int,int>> stree;
    public:
        segtree(vector<int> a, int n){
            size = n;
            base = a;
            stree.assign(4*size, {-1000000007,-1});
        }
        pair<int,int> combine(pair<int,int> left, pair<int,int> right){
            pair<int,int> result;
            if(left.first == right.first){
                result.first = left.first;
                result.second = left.second + right.second;    
            }else{
                if(left.second <= right.second){
                    result.first = right.first;
                    result.second = right.second;
                }else{
                    result.first = left.first;
                    result.second = left.second;
                }
            }
            return result;
        }
        void build(int v, int tl, int tr){
            if(tl == tr){
                stree[v] = {base[tl], 1};
            }else{
                int tm = (tl + tr)/2;
                build(2*v, tl, tm);
                build(2*v + 1, tm + 1, tr);
                stree[v] = combine(stree[2*v], stree[2*v + 1]);
            }
            return;
        }
        pair<int,int> query(int v, int tl, int tr, int l, int r){
            if(l > r) return {-1, -1};
            if(tl == l && tr == r){
                return stree[v];
            }
            int tm = (tl + tr)/2;
            return combine(query(2*v, tl, tm, l, min(tm, r)), query(2*v + 1, tm + 1, tr, max(tm + 1, l), r));
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n;
    while(n != 0){
        cin >> q;
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        segtree st(v, n);
        st.build(1, 0, n - 1);

        for(int i = 0; i < q; i++){
            int l, r;
            cin >> l >> r;
            l--, r--;
            pair<int,int> curr = st.query(1, 0, n - 1, l, r);
            cout << curr.second << "\n";
        }

        cin >> n;
    }

    return 0;
}
