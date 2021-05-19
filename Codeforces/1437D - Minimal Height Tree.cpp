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

const ll MOD = 1e9 + 7;
const int dx[4] = {1, -1, 0,  0};
const int dy[4] = {0,  0, 1, -1};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int numcases;
    cin >> numcases;

    while(numcases--){
        int vertices;
        cin >> vertices;
        vector<int> bfsorder(vertices);
        for(int i = 0; i < vertices; i++){
            cin >> bfsorder[i];
        }
        if(vertices == 2){
            cout << "1" << endl;
            continue;
        }
        int answer = 0;
        int prevCounterNodes = 1;
        int currCounterNodes = 0;
        int left = 1, right = left + 1;
        while(left < bfsorder.size()){
            while(left < bfsorder.size()){
                if(right >= bfsorder.size()){
                    currCounterNodes++;
                    prevCounterNodes--;
                    break;
                }
                if(bfsorder[left] < bfsorder[right]){
                    currCounterNodes++;
                    left++;
                    right++;
                }else{
                    currCounterNodes++;
                    prevCounterNodes--;
                    break;
                }
            }
            if(prevCounterNodes == 0 || left == bfsorder.size() - 1){
                answer++;
                prevCounterNodes = currCounterNodes;
                currCounterNodes = 0;
            }
            left = right;
            right = left + 1;
        }
        cout << answer << endl;
    }
    return 0;
}
