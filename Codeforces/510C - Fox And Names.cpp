#include <bits/stdc++.h>
#include <sstream>
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll INF = 100000000;
const int MOD = 1e9 + 7;

pair<int,int> getEdge(string s1, string s2){
    int minLen = min(s1.size(), s2.size());
    for(int i = 0; i < minLen; i++){
        if(s1[i] != s2[i]){
            return {(int)s1[i] - (int)'a', (int)s2[i] - (int)'a'};
        }
    }
    return {-1,-1};
}

vector<int> khan_algorithm(vector<vector<int>> &adjlist, vector<int> &indegree){
    vector<int> toposort;
    queue<int> fila;

    for(int i = 0; i < (int)indegree.size(); i++){
        if(indegree[i] == 0) fila.push(i);
    }
    while(!fila.empty()){
        int curr = fila.front();
        toposort.push_back(curr);
        fila.pop();

        for(int i = 0; i < (int)adjlist[curr].size(); i++){
            int u = adjlist[curr][i];
            indegree[u]--;
            if(indegree[u] == 0) fila.push(u);
        }
    }

    return toposort;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int numNames;
    bool notOk = false;
    cin >> numNames;

    vector<string> names(numNames);
    for(int i = 0; i < numNames; i++){
        cin >> names[i];
    }
    vector<vector<int>> adjlist(26, vector<int>());
    vector<int> indegree(26, 0);
    for(int i = 0; i < (int)names.size() - 1; i++){
        pair<int,int> edge = getEdge(names[i], names[i + 1]);
        if(edge.first != -1 && edge.second != -1){
            adjlist[edge.first].push_back(edge.second);
            indegree[edge.second]++;
        }
        else if(edge.first == -1 && edge.second == -1){
            if(names[i].size() > names[i + 1].size()){
                notOk = true;
                break;
            }
        }
    }
    if(notOk == true){
        cout << "Impossible" << endl;
        return 0;
    }
    vector<int> almostAnswer = khan_algorithm(adjlist, indegree);
    for(int i = 0; i < (int)indegree.size(); i++){
        if(indegree[i] != 0){
            cout << "Impossible" << endl;
            return 0;
        }
    }
    vector<char> answer;
    for(int i = 0; i < (int)almostAnswer.size(); i++){
        answer.push_back((char)(almostAnswer[i] + (int)'a'));
    }
    for(auto ch : answer){
        cout << ch;
    }

    return 0;
}
