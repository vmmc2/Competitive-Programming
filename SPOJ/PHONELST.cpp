#include <bits/stdc++.h>
#include <sstream>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define vi vector<int>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll MOD = 1000000007;
const int dx[4] = {1, -1, 0,  0};
const int dy[4] = {0,  0, 1, -1};


class trie{
    private:
        static const int ALPHABET_SIZE = 10;
        struct node{
            bool isWordEnd = false;
            node *children[ALPHABET_SIZE];
        };
        struct node *root = NULL;
        bool hasPreffixInsideNumber;
    public:
        trie(){
            root = create_node();
            hasPreffixInsideNumber = false;
        }
        struct node* get_root(){
            return root;
        }
        bool get_hasPreffixInsiderNumber(){
            return hasPreffixInsideNumber;
        }
        struct node* create_node(){
            struct node *temp = new node;
            for(int i = 0; i < ALPHABET_SIZE; i++){
                temp->children[i] = NULL;
            }
            temp->isWordEnd = false;
            return temp;
        }
        void insert_string(struct node *root, string st){
            struct node *tempRoot = root;
            for(int i = 0; i < st.size(); i++){
                int index = st[i] - '0';
                if(tempRoot->children[index] == NULL){
                    tempRoot->children[index] = create_node();
                }
                tempRoot = tempRoot->children[index];
                if(tempRoot->isWordEnd == true){
                    hasPreffixInsideNumber = true;
                }
            }
            tempRoot->isWordEnd = true;
            return;
        }
};



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, numcases;
    cin >> numcases;

    while(numcases--){
        cin >> n;
        trie tt;
        vector<string> telephones(n);
        for(int i = 0; i < n; i++){
            cin >> telephones[i];
        }
        sort(telephones.begin(), telephones.end());
        for(int i = 0; i < n; i++){
            tt.insert_string(tt.get_root(), telephones[i]);
            if(tt.get_hasPreffixInsiderNumber() == true){
                cout << "NO" << endl;
                break;
            }
        }
        if(tt.get_hasPreffixInsiderNumber() == false){
            cout << "YES" << endl;
        }
    }
    
    return 0;
}
