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
    int qtdif = 0;
    int hashtable[26] = {0};
};

class segtree{
    public:
        //class variables...
        vector<node> t;
        string s;
        int tam;
        //class methods...
        segtree(string base, int tam){ // constructor
            this->s = base;
            this->tam = tam;
            t.resize(4*tam);
        }
        struct node combine(struct node s1, struct node s2){ //method to merge 2 nodes
            struct node s3;
            for(int i = 0; i < 26; i++){
                if(s1.hashtable[i] != 0 || s2.hashtable[i] != 0){
                    s3.hashtable[i] = s1.hashtable[i] + s2.hashtable[i];
                    s3.qtdif++;
                }
            }
            return s3;
        }
        void build(int v, int tl, int tr){
            if(tl == tr){
                t[v].qtdif = 1;
                t[v].hashtable[s[tl] - 'a']++;
            }else{
                int tm = (tl + tr)/2;
                build(2*v, tl, tm);
                build(2*v + 1, tm + 1, tr);
                t[v] = combine(t[2*v], t[2*v + 1]);
            }
        }
        void update(int v, int tl, int tr, int pos, char new_val){
            if(tl == tr){
                t[v].qtdif = 1;
                memset(t[v].hashtable, 0, sizeof(t[v].hashtable));
                t[v].hashtable[new_val - 'a']++; 
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
        struct node query(int v, int tl, int tr, int l, int r){
            if(l > r){
                struct node trash;
                return trash;
            }
            if(tl == l && tr == r){
                return t[v];
            }
            int tm = (tl + tr)/2;
            return combine(query(2*v, tl, tm, l, min(tm, r)), query(2*v + 1, tm + 1, tr, max(tm + 1, l), r));
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    char novochar;
    int q, pos;
    int type;
    int l, r;
    cin >> s;
    int n = (int)s.size();
    cin >> q;
    segtree st(s, n);
    st.build(1, 0, n - 1);
    for(int i = 0; i < q; i++){
        cin >> type;
        if(type == 1){
            cin >> pos >> novochar;
            pos--;
            st.update(1, 0, n-1, pos, novochar);
        }else if(type == 2){
            cin >> l >> r;
            l--, r--;
            struct node ans = st.query(1, 0, n - 1, l, r);
            cout << ans.qtdif << "\n";
        }
    }
    return 0;
}
