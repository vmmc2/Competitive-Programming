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

const int ALPHABET_SIZE = 26;


struct node{
    bool endOfWord = false;
    struct node *children[ALPHABET_SIZE];
};

class trie{
    private:
        struct node *root = NULL;
    public:
        trie(){
            root = create_node();
        }
        struct node *create_node(){
            struct node *tempRoot = new node;
            for(int i = 0; i < ALPHABET_SIZE; i++){
                tempRoot->children[i] = NULL;
            }
            tempRoot->endOfWord = false;
            return tempRoot;
        }
        struct node *get_root(){
            return this->root;
        }
        void insert_string(struct node *root, string s){
            struct node *tempRoot = root;
            for(int i = 0; i < (int)s.size(); i++){
                int index = s[i] - 'a';
                if(tempRoot->children[index] == NULL){
                    tempRoot->children[index] = create_node();
                }
                tempRoot = tempRoot->children[index];
            }
            tempRoot->endOfWord = true;
            return;
        }
        struct node *find_preffix(struct node *root, string preffix){
            struct node *prev = NULL;
            struct node *tempRoot = root;
            for(int i = 0; i < (int)preffix.size(); i++){
                int index = preffix[i] - 'a';
                if(tempRoot->children[index] == NULL){
                    return NULL;
                }
                tempRoot = tempRoot->children[index];
            }
            return tempRoot;
        }
        void dfs(struct node *root, string pref, string curr, vector<string> &answer){
            for(int i = 0; i < ALPHABET_SIZE; i++){
                if(root->children[i] != NULL){
                    dfs(root->children[i], pref, curr + (char)(i + (int)'a'), answer);
                }
            }
            if(curr != pref && root->endOfWord == true){
                answer.push_back(curr);
            }
            return;
        }

};



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    string s;
    trie tt;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        tt.insert_string(tt.get_root(), s);
    }
    cin >> k;
    for(int i = 0; i < k; i++){
        cin >> s;
        struct node *starting_point = tt.find_preffix(tt.get_root(), s);
        cout << "Case #" << (i + 1) << ":" << endl;
        if(starting_point == NULL){
            cout << "No match." << endl;
        }else{
            vector<string> answer;
            tt.dfs(starting_point, s, s, answer);
            if(answer.size() == 0){
                cout << "No match." << endl;
            }else{
                sort(answer.begin(), answer.end());
                for(auto x : answer){
                    cout << x << endl;
                }
            }
        }
    }
    
    return 0;
}
